#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b;
    c=0;
    int d;
    int i=0;
    while(b!=0){
        c=c*10+(b%10);
        i++;
        b=(int)(b/10);
    }
    cout<<c+a;
    return 0;
}