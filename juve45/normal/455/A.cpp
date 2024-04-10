#include <iostream>

#define dmax 100002
#define nmax 100005

using namespace std;

unsigned long long k, nr[nmax], kmax;
unsigned long long f[nmax], n;

int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        nr[k]++;
        if(k>kmax)
            kmax=k;
    }
    f[0]=0;
    f[1]=nr[1];
    for(long long i=2;i<=kmax;i++)
    {
        f[i]=max(f[i-1], f[i-2]+nr[i]*i);
    }

    cout<<f[kmax];
    return 0;
}