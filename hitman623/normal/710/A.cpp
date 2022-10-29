#include <iostream>

using namespace std;

int main()
{
    char a[3];
    int c=8;
    cin>>a;
    if((a[0]=='a' || a[0]=='h') && (a[1]=='1' || a[1]=='8'))
    c=3;
    else if((a[0]=='a' || a[0]=='h') || (a[1]=='1' || a[1]=='8'))
    c=5;
    cout<<c;
    return 0;
}