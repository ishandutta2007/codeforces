#include <iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    switch(a){
        case 1: case 4: cout<<2; break;
        case 2: cout<<3; break;
        case 3: case 5: cout<<1; break;
    }
    return 0;
}