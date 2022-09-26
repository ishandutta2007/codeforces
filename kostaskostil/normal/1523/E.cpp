#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

typedef long long ll;
#define int ll

using namespace std;

const int nmax = 2e5 + 100;

int f[nmax];
int rf[nmax];
int mod = 1e9 + 7;

int bpow(int a, int b)
{
    int x = 1;
    while (b > 0)
    {
        if (b%2)
        {
            x*=a;
            x%=mod;
        }
        b/=2;
        a*=a;
        a%=mod;
    }
    return x;
}

int rev(int a)
{
    return bpow(a, mod-2);
}

int cnk(int n, int k)
{
    if ((k > n) or (k < 0))
        return 0;
    return ((f[n] * rf[k]) % mod) * rf[n-k] % mod;
}

int supercnk(int n, int k)
{
    return cnk(n+k-1, k-1);
}

main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    f[0] = rf[0] = 1;
    for (int i=1; i<nmax; i++)
    {
        f[i] = (f[i-1] * i) % mod;
        rf[i] = rev(f[i]);
    }

    int q;
    cin>>q;
    while (q--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> cnt(n+2);
        cnt[0] = 1;
        for (int i=1; i<=n; i++)
        {
            cnt[i] = supercnk(n + k - 1 - k*i, i+1);
            cnt[i] *= f[i];
            cnt[i] %= mod;
        }
        cnt[n+1] = 0;

        int mul = 1;
        for (int i=0; i<=n; i++)
        {
            cnt[i] *= mul;
            cnt[i] %= mod;

            mul *= rev(n-i);
            mul %= mod;
        }

        int ans = 0;
        for (int i=1; i<=n; i++)
        {
            ans+= (i + 1) * (cnt[i] - cnt[i+1]);
            ans %= mod;
        }

        cout<<ans<<"\n";
    }

}