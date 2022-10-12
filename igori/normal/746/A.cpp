#include <iostream>

using namespace std;

int main()
{
    int a,b,c=0;
    cin>>a>>b>>c;
    int n=0;
    while(a!=1001)
    {
        n++;
        if((n>a)||(2*n>b)||(4*n>c))
        {
            cout<<7*(n-1);
            break;
        }
    }
}