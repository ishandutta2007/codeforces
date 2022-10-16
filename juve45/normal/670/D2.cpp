#include <iostream>

using namespace std;

long long n, k, a[100009], b[100009];

bool isOK(long long nr)
{
    long long k2=k;

    for(long long i=1; i<=n; i++)
    {
        long long c=b[i]/a[i];
        long long am=b[i]%a[i];
        long long nev=nr-c;
        if(nev<=0) continue;
        nev*=a[i];
        nev-=am;
        k2-=nev;
        if(k2<0)
            return false;
    }

    return true;
}

long long caut_bin(long long st, long long dr)
{
    if(st==dr) return st;

    long long mid=(st+dr+1)/2;
    if(isOK(mid))
        return caut_bin(mid, dr);
    return caut_bin(st, mid-1);
}

int main()
{
    cin>>n>>k;
    for(long long i=1; i<=n; i++)
        cin>>a[i];
    for(long long i=1; i<=n; i++)
        cin>>b[i];

    int i;

    long long ans=caut_bin(0, 2000000001LL);
    cout<<ans<<'\n';

    return 0;
}