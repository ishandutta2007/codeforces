#include <iostream>

using namespace std;

int main()
{
    long long n,k,m,j;
    cin>>n>>k;
    if(n%2==0)
    {
        if(k<=n/2)
            m=(2*k-1);
        else
            m=(2*k-n);
    }
    else
    {
        j=n/2+1;
        if(k>j)
            m=(2*k-n-1);
        else
            m=(2*k-1);

    }
    cout<<m;
}