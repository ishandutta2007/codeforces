#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 4e6 + 100;
int dp[nmax];
int pref[nmax];
int suf[nmax];
int mod;
int n;
void f(int i)
{
    for (int k=2; ;k++)
    {
        /// [ k*i, k*i + k)
        if (k*i > n)
            break;
        suf[k*i] = (suf[k*i] + dp[i]) % mod;
        if (k*i + k <= n)
        suf[k*i + k] = (suf[k*i + k] - dp[i]) % mod;

    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>mod;
    dp[1] = 1;
    pref[1] = 1;
    f(1);
    for (int i=2; i<=n; i++)
    {
        dp[i] = (pref[i-1] + suf[i])%mod;

        f(i);
        suf[i+1] = (suf[i] + suf[i+1]) % mod;
        pref[i] = (pref[i-1] + dp[i]) % mod;
    }
    cout<<(dp[n]+mod)%mod<<"\n";
}