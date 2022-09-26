#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 3e6+100;
const int mod = 1e9+7;

int bpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b%2)
        {
            res*=a;
            res%=mod;
        }
        a*=a;
        a%=mod;
        b/=2;
    }
    return res;
}

int inv(int x)
{
    return bpow(x, mod-2);
}

int fact[nmax];
int cnk(int n, int k)
{
    if ((k < 0) or (k > n))
        return 0;
    return fact[n] * inv(fact[k]) % mod * inv(fact[n-k]) % mod;
}

int a[nmax];
int b[nmax];
int c[nmax];
int n;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;
    for (int i=1; i<nmax; i++)
        fact[i] = i*fact[i-1] % mod;

    cin>>n;
    for (int i=1; i<=3*n+3; i++)
        a[i-1] = cnk(3*n+3, i);
    b[0] = 3;
    b[1] = 3;
    b[2] = 1;
    c[0] = n+1;
    c[1] = (3*n*(n+1)/2)%mod;
    int rb = inv(b[0]);
    for (int i=2; i<=3*n; i++)
    {
        // b[3] * c[i-2] + b[2] * c[i-1] + b[1] * c[i] = a[i];
        c[i] = ((a[i] - b[2] * c[i-2] - b[1] * c[i-1]) % mod) * rb;
        c[i] %= mod;
        c[i] += mod;
        c[i] %= mod;
    }
//    for (int i=0; i<=3*n; i++)
//        cout<<i<<" "<<c[i]<<"\n";

    int q;
    cin>>q;
    while (q--)
    {
        int x;
        cin>>x;
        cout<<c[x]<<"\n";
    }
}