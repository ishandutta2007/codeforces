#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;

//#define int long long

const int nmax=2e5+100;
int a[nmax];
int b[1000];
long long cnt[1000];

long long bpow(long long a, int b, int m)
{
    long long res=1;
    while (b)
    {
        if (b%2) res*=a, res%=m;
        b/=2;
        a*=a;
        a%=m;
    }
    return res;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1, a+n+1);
    for (int i=1; i<=n; i++)
    {
        a[i]%=m;
        for (int j=0; j<m; j++)
            cnt[ (a[i]-j+m)%m ] += b[j];
        b[a[i]]++;
    }

    long long res=1;
    for (int i=0; i<m; i++)
        res*=bpow(i, cnt[i], m), res%=m;
    cout<<res<<"\n";
    return 0;
}