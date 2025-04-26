#include<iostream>
using namespace std;

//declaration of functions
void create_data(int* arr, int a);
void display_data(int* arr, int a);
void append_data(int* arr, int a, int b);
void count_data(int* arr, int a);
void search_data(int* arr, int a, int ch1);
void update_data(int* arr, int a, int ch1);
void delete_data(int* arr, int& b, int choice);
void reverse_data(int* arr, int a);
void sort_asc_data(int* arr, int a);
void sort_desc_data(int* arr, int a);

int main () {
    int ch, a, b, ch1;
    int* array = nullptr;
   
    do{
        system("cls");
        cout << "-------------------------------------------------------" << endl;
        cout << "1. CREATE DATA " << endl;
        cout << "2. DISPLAY DATA " << endl;
        cout << "3. APPEND DATA " << endl;
        cout << "4. COUNT DATA " << endl;
        cout << "5. SEARCH DATA " << endl;
        cout << "6. UPDATE DATA " << endl;
        cout << "7. DELETE DATA " << endl;
        cout << "8. REVERSE DATA " << endl;
        cout << "9. SORT DATA ASCENDING " << endl;
        cout << "10. SORT DATA DESCENDING " << endl;
        cout << "0. EXIT " << endl ;
        cout << "-------------------------------------------------------" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        cout << endl;

        switch(ch){
            case 1 : 
                    cout << "How many Elements you want : ";
                    cin >> a;
                    delete[] array;
                    array = new int [a];
                    create_data(array, a);
            break;

            case 2 :
                    cout << "Your data is : " << endl;
                    display_data(array, a);
                    cout << endl;
                    cout << endl << "Press ENTER...........";
                    cin.ignore();
                    cin.get();
            break;

            case 3 :{
                    cout << "Enter how many MORE elements you want : ";
                    cin >> b;

                    //creating new newarray
                    int* newarray = new int[a+b];

                    //copying data to newarray
                    for(int i = 0; i < a; i++){
                        newarray[i] = array[i];
                    }

                    //deleting array
                    delete[] array;

                    //initializing array to newarray
                    array = newarray;
                    
                    //appending data
                    append_data(array, a, b);

                     //updating a
                     a = a + b;
                    }
            break;


            case 4 :
                   count_data(array, a);
                   cout << endl;
                   cout << endl << "Press ENTER...........";
                   cin.ignore();
                   cin.get();
            break;

            case 5 :
                    cout << "1. SEARCH BY VALUE " << endl;
                    cout << "2. SEARCH BY POSITION " << endl;
                    cout << "Enter your choice : ";
                    cin >> ch1;
                    cout << endl;
                    search_data(array, a, ch1);
            break;

            case 6 :
                    cout << "1. UPDATE BY VALUE ( MULTIPLE VALUES MAY UPDATED ) " << endl;
                    cout << "2. UPDATE BY POSITION ( RECOMMENDED ) " << endl;
                    cout << "Enter your choice : ";
                    cin >> ch1;
                    cout << endl;
                    update_data(array, a, ch1);
            break;

            case 7 :
                    cout << "1. DELETE BY VALUE ( MULTIPLE VALUE MAY DELETED ) " << endl;
                    cout << "2. DELETE BY POSITION ( RECOMMENDED ) " << endl;
                    cout << "Enter your choice : ";
                    cin >> ch1;
                    cout << endl;
                    delete_data(array, a, ch1);
            break;

            case 8 :
                    reverse_data(array, a);
                    cout << "Data RVERSED........" << endl;
                    cout << "Press ENTER.........";
                    cin.ignore();
                    cin.get();
            break;

            case 9 :
                    sort_asc_data(array, a);
                    cout << "Data SORTED........" << endl;
                    cout << "Press ENTER.........";
                    cin.ignore();
                    cin.get();
            break;
        }
    }while (ch != 0);

    delete[] array;
    return 0;
}

//create data
void create_data(int* arr, int a){
    for (int i = 0; i < a; i++){
        cout << "Enter [" << i + 1 << "] element : ";
        cin >> arr[i];
    }
 return;
}

//display data
void display_data(int* arr, int a){
    for (int i = 0; i < a; i++){
        cout << arr[i] << " " ;
    }
 return;
}

//append data
void append_data(int *arr, int a, int b){
    for (int i = a; i < a+b; i++){
        cout << "Enter [" << i + 1 << "] element : ";
        cin >> arr[i];
    }
 return;
}

//count data
void count_data(int *arr, int a){
    int b = 0;
    b = a + b;
    cout << "You have >> " << b << " << elements.";
 return;
}

//search data
void search_data(int *arr, int a, int ch1){
    switch(ch1){
        case 1 :{            
                int value;
                cout << "Enter the value to search : ";
                cin >> value;
                bool found = 0;
                //if found
                for (int i = 0; i < a; i++){
                    if(value == arr[i]){
                        cout << value << " is at the postion [" << i+1 << "] " << endl;
                        found = 1;
                    }
                }
                //if not found 
                if(found == 0 ){
                    cout << value << " NOT found !!! " << endl;
                }
                cout << endl;
                cout << "Press ENTER..........";
                cin.ignore();
                cin.get();
                }
        break;

        case 2 :
                int pos;
                cout << "Enter position to search ( 1 - " << a << " ) : ";
                cin >> pos;
                if (0 < pos && pos <= a){
                    cout << "Value at [" << pos << "] is : " << arr[pos-1] << endl;
                }else{
                    cout << "Position NOT found !!!" << endl;
                }
                cout << endl;
                cout << "Press ENTER..........";
                cin.ignore();
                cin.get();
        break;
    }
 return;
}

//update data 
void update_data(int* arr, int a, int ch1){
    switch(ch1){
        case 1 :{ 
                int value, newvalue;
                bool update = 0;
                cout << "Enter value to update : ";
                cin >> value;
                for(int i = 0; i < a; i++){
                    //if updated
                    if (arr[i] == value){
                        cout << "Enter NEW value at position [" << i + 1 << "] : ";
                        cin >> newvalue;
                        arr[i] = newvalue;
                        update = 1;
                    }}
                    //if not updated
                    if (update == 0){
                        cout << "Value NOT found !!! ";
                        cout << endl;
                        cout << "Press ENTER..........";
                        cin.ignore();
                        cin.get();           
                    }}
        break;

        case 2 :{ 
                int pos, newvalue;
                cout << "Enter Position to update : ";
                cin >> pos;
                if(pos > 0 && pos <= a){
                cout << "Enter NEW value at position [" << pos << "] : ";
                cin >> newvalue;
                arr[ pos - 1 ] = newvalue;
                }else{
                    cout << "Envalid position......" << endl;
                    cin.ignore();
                    cin.get();
                }
                }
        break;
        }            
 return;
}

//delete data
void delete_data(int *arr, int& b, int ch1){
    switch(ch1){
        case 1 :{
                int value; 
                bool deleted = 0;
                cout << "Enter Value to delete ( MULTIPLE VALUES MAY DELETED ) : ";
                cin >> value;
                //if found
                for( int i = 0; i < b;){
                    if ( value == arr[i] ){                       
                        for ( int j = i; j < b; j++){
                            arr[j] = arr[j + 1];
                        }
                        b--;
                        deleted = 1;
                       }else{
                        i++;
                       }
                }

                //if not found 
                if (deleted == 0){
                    cout << "Value NOT found !!! ";
                    cout << endl;
                    cout << "Press ENTER..........";
                    cin.ignore();
                    cin.get();           
                }}
        break;

        case 2 :
                int pos;
                cout << "Enter position to delete [ 1 -  " << b << " ] : ";
                cin >> pos;
                if(pos > 0 && pos <= b ){
                    for( int i = pos - 1; i < b - 1; i++){
                        arr[i] = arr[ i + 1 ];
                    }
                  b--;
                }else{
                    cout << "Position NOT found !!! " << endl;
                    cout << "Press ENTER...............";
                    cin.ignore();
                    cin.get();
                }
        break;
    }
 return;
}

//reverse data
void reverse_data(int *arr, int a){
    int tmp;
    for (int i = 0; i < a/2; i++){
        tmp = arr[i];
        arr[i] = arr[ (a - 1) - i ];
        arr[ (a-1) - i ] = tmp;
    }
 return;
}

//sorting data (ascending)
void sort_asc_data(int* arr, int a){
    int tmp;
    for ( int i = 0; i < a - 1; i++ ){
        for( int j = 0; j < a - 1 - i; j++){
            if (arr[j] > arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            } 
        }
    }
}