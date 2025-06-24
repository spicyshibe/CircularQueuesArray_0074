/**
 * @mainpage Documentation Circular Queues
 * 
 * @section Introduction 
 * Project ini merupakan project struktur data 
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 * 
 * @section Operations 
 * Project ini memiliki beberapa operasi antara lain: 
 * 1. Insert 
 * 2. Delete 
 * 3. Display 
 * 
 * @section Cara Penggunaan 
 * berikut beberapa menu yang bisa di gunakan:
 * 1. en queue 
 * 2. de queue 
 * 3. display
 * 4. exit 
 * 
 * @author Profil 
 * - nama   : Rafie Rasydan Wahyudi
 * - nim    : 20240140074
 * - kelas  : B
 * 
 * @brief
 * @version 1.0
 * @date 2025-06-24
 * 
 * @copyright rafie.rasydan.ft24@mail.umy.ac.id (c) 2025
 * 
 *  
 */

#include <iostream>
using namespace std;
/**
 * @class Queues 
 * @brief Class ini untuk operasi lengkap queues
 */
class Queues
{
    private:
        int max = 5; ///< variable private max untuk menyimpan ukuran maximum antrian
        int FRONT; ///< variable private front untuk menyimpani posisi depan antrian
        int REAR; ///< variable rear untuk menyimpan posisi belakang antrian 
        int queue_array[5]; ///< variable private queue_array untuk menyimpan elemen antrian

    public: 
    /**
     * @brief construct a new queues object 
     * set default queues null
     * with front = -1 and rear =-1
     */
    Queues()
    {
        FRONT = -1;
        REAR = -1;

    }

    /**
     * @brief method untuk memasukkan data dalam antrian
     * data dimasukkan dalam variable queue_array 
     */

    void insert()
    {
        int num; ///< variable num untuk menyimpan nilai 
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // 1. cek apakah antrian penuh 
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n"; // 1.a
            return; // 1.b
        }
        // 2. cek apakah antrian kosong 
        if (FRONT == -1)
        {
            FRONT = 0; // 2.a
            REAR = 0; // 2.b 

        }
        else 
        {
            // jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
                else 
                    REAR = REAR + 1;

        }
        queue_array[REAR] = num;
    }

    /**
     * @brief method untuk menghapus data dalam antrian
     * data di hapuskan dari dalam variable queue_array
     */

    void remove()
    {
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
         cout << "Queue underflow\n";
         return;
        }
          cout << "\nThe Element deleted from the queue is: " << queue_array[FRONT] << "\n";

            // Cek jika antrian hanya memiliki satu elemen
            if (FRONT == REAR)
            {
                FRONT = -1;
                REAR = -1;
            }
            else
            {
                // Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
                if (FRONT == max - 1)
                    FRONT = 0;
                else
                    FRONT = FRONT + 1;
            }
    }
    /**
     * @brief method untuk menampilkan data dalam antrian 
     * data ditampilkan yang berada dalam variable queue_array 
     */
    void display()
    {
        int FRONT_position = FRONT; ///< variable front_posisition untuk menandakan posisi element
        int REAR_position = REAR; ///< variable rear_posistion untuk menandakan posisi element 

        // cek apakah antrian kosong 
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;

        }

        cout << "\nElements in the queue are ...\n";

        //jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
        while (FRONT_position <= REAR_position)
        {
            cout << queue_array[FRONT_position] << " ";
            FRONT_position++;
        }
        cout << endl;
        }
        else 
        {
            // Jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << "   ";
                FRONT_position++;
            }

            FRONT_position = 0;

              while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
    }

};

/**
 * @brief method utama untuk menjalankan program
 * 
 * @return int
 */
int main()
{
    Queues q; ///< objek untuk menggunakan member yang ada class queues 
    char ch; ///< variable ch untuk menyimpan pilihan pada menu yang di berikan 

    while (true)
    {
        try
        {
            cout << "menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display Value" << endl;
            cout << "4. Exit" << endl;
            cout << "enter your choice (1-4)" << endl;
            cin >> ch;
            cout << endl;

            switch (ch)
            {
                case '1':
                {
                    q.insert();
                    break;
                }

                case '2':
                {
                    q.remove();
                    break;
                }

                case '3':
                {
                    q.display();
                    break;
                }

                case '4':
                {
                    return 0;
                }

                default:
                {
                    cout << "Invalid option!!" << endl;
                    break;
                }
            }
        }
        catch (exception &e)
            {
                cout << "Check for the values entered." << endl;
            }
    }
    return 0;
    
}