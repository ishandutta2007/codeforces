#include <iostream>

using namespace std;

int main()
{
    long long m,k,p;
    cin>>m;
    if(m<0)
    {
        m=-m;
        k=m/10;
        p=m/100;
        p=p*10+m%10;
        m=min(k,p);
        m=-m;

    }
    cout<<m;
}