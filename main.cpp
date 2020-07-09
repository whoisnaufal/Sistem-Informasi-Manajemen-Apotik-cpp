#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct node
{
    int idKaryawan;
    string namaKaryawan;
    string alamatKaryawan;
    string usernameKaryawan;
    string passwordKaryawan;
    char jenkelKaryawan;

    node *next;
};


struct dataAdmin
{
    string username[2]= {"admin1","admin2"};
    string password[2]= {"admin1","admin2"};
} login;

node *baru,*head = NULL,*tail = NULL,*hapus,*temp;

void buatBaru();
void tampilData();
void tambahData();
void tampilData();
void cariData();
void hapusData();
void menuAdmin();
void menuKaryawan();
void tampilLogin();

void buatBaru()
{
    baru = new node;
    system("CLS");
    cout << "Tambah Data karyawan" <<endl;
    cout << "======================" <<endl;
    cout << "Id karyawan\t: ";
    cin >> baru->idKaryawan;
    cout << "Nama karyawan\t: ";
    cin >> baru->namaKaryawan;
    cout << "Alamat karyawan\t: ";
    cin >> baru->alamatKaryawan;
    cout << "Username\t: ";
    cin >> baru->usernameKaryawan;
    cout << "Password\t: ";
    cin >> baru->passwordKaryawan;
    baru->next=NULL;
}

void tampilData()
{
    cout << "\nDaftar karyawan."<<endl;
    cout << "================"<<endl;
    if (head==NULL)
    {
        cout << "Data kosong." <<endl;
    }
    else
    {
        temp = head;
        while(temp!=NULL)
        {
            cout << "Id karyawan\t: " << temp->idKaryawan <<endl;
            cout << "Nama karyawan\t: " << temp->namaKaryawan <<endl;
            cout << "Alamat karyawan\t:" << temp->alamatKaryawan <<endl;
            cout << "Username\t: " << temp->usernameKaryawan <<endl;
            cout << "Password\t: " << temp->passwordKaryawan <<endl;
            cout << "\n";
            temp=temp->next;
        }
    }
    getch();
    system("CLS");
}

void tambahData()
{
    buatBaru();
    if (head==NULL)
    {
        head=baru;
        tail=baru;
    }
    else
    {
        tail->next=baru;
        tail=baru;
    }
    tampilData();
}

void hapusData()
{
    int jumDat,delPos,poshapus;
    node *hapus,*temp;
    if(head != NULL)
    {
        cout << "Akan dihapus pada data ke : ";
        cin >> delPos;
        jumDat=1;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            jumDat++;
        }
        if((delPos<1)||(delPos>jumDat))
        {
            cout << "Belum ada data yang masuk";
        }
        else
        {
            temp=head;
            poshapus=1;
            while(poshapus<(delPos-1))
            {
                temp=temp->next;
                poshapus++;
            }
            hapus=temp->next;
            temp->next=hapus->next;
            delete hapus;
        }
    }
    else
    {
        cout<<"Data masih kosong";
    }
}

void cariData()
{
    temp = head;
    int cariId;
    cout << "\nId yang dicari\t: ";
    cin >> cariId;
    int find = false;
    if (head != NULL)
    {
        while(temp!=NULL)
        {
            temp->idKaryawan;
            if (cariId == temp->idKaryawan)
            {
                cout << "\nData ditemukan" <<endl;
                cout << "Id karyawan\t: " << temp->idKaryawan <<endl;
                cout << "Nama karyawan\t: " << temp->namaKaryawan <<endl;
                cout << "Alamat karyawan\t:" << temp->alamatKaryawan <<endl;
                cout << "Username\t: " << temp->usernameKaryawan <<endl;
                cout << "Password\t: " << temp->passwordKaryawan <<endl;
                cout << "\n";
                find = true;
            }
            temp=temp->next;
        }
        if (find==false)
        {
            cout << "\nData tidak ditemukan";
        }
    }
    else
    {
        cout << "\nData masih kosong";
    }
}

void menuAdmin()
{
    system("CLS");
    int pil;
    do
    {
        cout<<"Selamat Datang di Sistem Informasi Manajemen Apotik\n\n";
        cout << "1. Tambah Data Karyawan"<<endl;
        cout << "2. Hapus Data Karyawan"<<endl;
        cout << "3. Tampil Data Karyawan"<<endl;
        cout << "4. Cari Data Karyawan" <<endl;
        cout << "5. Logout" <<endl;
        cout << "6. Keluar Aplikasi" <<endl;
        cout << "Masukkan pilihan [1..6] : ";
        cin >> pil;
        switch(pil)
        {
        case 1:
            tambahData();
            break;
        case 2:
            hapusData();
            tampilData();
        case 3:
            tampilData();
            break;
        case 4:
            cariData();
            cin.get();
            break;
        case 5:
            tampilLogin();
            break;
        }
    }
    while(pil!=6);
}


void menuKaryawan()
{
    system("CLS");
    int pil;
    do
    {
        cout<<"Selamat Datang di Sistem Informasi Manajemen Apotik\n\n";
        cout << "1. Tambah Antrian"<<endl;
        cout << "2. Ambil Antrian"<<endl;
        cout << "3. Cek Ketersediaan Obat"<<endl;
        cout << "4. Tambah Data Obat" <<endl;
        cout << "5. Hapus Data Obat" <<endl;
        cout << "6. Tampilkan Data Obat" <<endl;
        cout << "7. Logout" <<endl;
        cout << "8. Keluar" <<endl;
        cout << "Masukkan pilihan [1..8] : ";
        cin >> pil;
        switch(pil)
        {
        case 1:
            break;
        case 2:
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        }
    }
    while(pil!=8);
}

void tampilLogin()
{
loginGagal:
    system("CLS");
    string username, password;
    int i=0;
    cout<<"Selamat Datang di Sistem Informasi Manajemen Apotik\n\n";
    cout<<"Silahkan login terlebih dahulu!\n";
    cout<<"Username : ";
    cin>>username;
    cout<<"Password : ";
    cin>>password;
    bool ketemu=false;

    temp = head;
    if(username==login.username[0]&&password==login.password[0]||username==login.username[1]&&password==login.password[1])
    {
        menuAdmin();
    }
    else if(head!=NULL)
    {
        temp->usernameKaryawan;
        temp->passwordKaryawan;
        while(temp!=NULL)
        {
            if(username==temp->usernameKaryawan && password == temp->passwordKaryawan)
            {
                cout<<"Login berhasil!\nTekan ENTER untuk melanjutkan";
                ketemu = true;
                getch();
                menuKaryawan();
            }
            temp=temp->next;
        }
        if(ketemu==false)
        {
            cout<<"\nMaaf username atau password yang kamu masukkan salah!\nTekan ENTER untuk coba lagi\n";
            getch();
            goto loginGagal;
        }
    }
    else
    {
        cout<<"\nMaaf username atau password yang kamu masukkan salah!\nTekan ENTER untuk coba lagi\n";
        getch();
        goto loginGagal;
    }
}

int main()
{
    tampilLogin();
    cin.get();
    return 0;
}
