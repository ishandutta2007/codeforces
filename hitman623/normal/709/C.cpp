#include <iostream>

using namespace std;

int main()
{
    char a[100002];long i,f=0;
    cin>>a;
    for(i=0;a[i]!=0;++i)
    {
        if(a[i]!='a') {a[i]--;f=1;}
        else if(f==1) break;
    }
    if(f==0)
        a[i-1]='z';
    cout<<a;
    return 0;
}