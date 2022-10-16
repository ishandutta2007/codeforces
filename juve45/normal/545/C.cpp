#include <iostream>
#define DMAX 100010

using namespace std;

long long n, x[DMAX], h[DMAX];
long long L[DMAX], R[DMAX], none[DMAX];

long long max3(long long x, long long y, long long z)
{
    if(x<y) x=y;
    if(x<z) x=z;
    return x;
}

int main()
{
cin>>n;

    for(long long i=1;i<=n;i++)
    cin>>x[i]>>h[i];

    L[1]=1;
    none[1]=0;
    R[1]=0;
    x[n+1] = 2000000001;
    for(long long i=2;i<=n;i++)
    {
        none[i] = max3(L[i-1], R[i-1], none[i-1]);

        if(x[i] > x[i-1] + h[i])
            L[i] = max(L[i-1], none[i-1]);

        if(x[i] > x[i-1] + h[i] + h[i-1])
            L[i] = max(L[i], R[i-1]);

        L[i]++;

        if(x[i+1] > x[i] + h[i])
            R[i] = none[i] + 1;

    }

    cout<<max3(R[n], L[n], none[n]);

    return 0;
}