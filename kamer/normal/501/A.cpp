#include<iostream>
#include<fstream>
using namespace std;

int a,b,c,d;

int main(void){
    cin >> a >> b >> c >> d;
    int x,y;
    x = max(3*a/10 , a - (a/250) * c);
    y = max(3*b/10 , b - (b/250) * d);
    if (x > y){
        cout << "Misha";
    }
    if (x < y){
        cout << "Vasya";
    }
    if (x == y){
        cout << "Tie";

    }
    return 0;
}