#include <iostream>

using namespace std;
long long a, b;
int main()
{
cin>>a>>b;

    if(a>b)
    {
        long long aux=a;
        a=b;
        b=aux;
    }
    long long k=0;
    while(a!=b && a!=0 && b!=0)
    {

    long long r=b/a;
    k+=r;
    b-=r*a;
    if(a>b)
    {
        long long aux=a;
        a=b;
        b=aux;
    }
    }

    cout<<k<<'\n';

    return 0;
}