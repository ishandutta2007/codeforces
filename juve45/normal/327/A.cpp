#include <iostream>

using namespace std;

int nmax=-3, n, a[102], n1, n0;

int main()
{
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }

    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
        {
            n1=a[j]-a[i-1];
            n0=j-i+1-n1;
            if(n0-n1>nmax)
                nmax=n0-n1;
        }

    cout<<a[n]+nmax;


    return 0;
}