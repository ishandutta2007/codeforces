#include<iostream>
#include<fstream>
using namespace std;

int main(void){
    
    int n;
    cin >> n;
    if (n%2 == 0){
        cout << "white\n 1 2";
    }
    else{
        cout << "black";
    }
    return 0;
}