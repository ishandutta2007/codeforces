#include <iostream>

using namespace std;

int main()
{
    int f,i;
    char a[6];
    cin>>f;
    cin>>a;
    if(f==12)
    {
        if(a[0]>'1' && a[1]!='0') a[0]='0';
        else if(a[0]>='1') a[0]='1';
        else if(a[1]=='0') a[1]='1';
        if(a[0]!='0' && a[1]>'2') a[1]='1';
        if(a[3]>'5') a[3]='0';
    }
    else
    {
         if(a[0]>'2') a[0]='0';
        if(a[0]=='2' && a[1]>'3') a[1]='1';
        if(a[3]>'5') a[3]='0';
    }
    cout<<a;
    return 0;
}