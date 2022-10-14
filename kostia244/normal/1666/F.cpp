#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

const int NMAX = 5050;
const int MOD = 998244353;

int dp[NMAX][NMAX];
int apref[NMAX];
int a[NMAX];
int b[NMAX];
int fact[NMAX];
int rfact[NMAX];
int bpow(int a, int b)
{
    int res = 1;
    while (b>0)
    {
        if (b%2)
        {
            res *= a;
            res %= MOD;
        }
        b/=2;
        a*=a;
        a%=MOD;
    }
    return res;
}

void solve()
{
    int n;
    cin>>n;

    for (int i=1; i<=n; i++)
        apref[i] = a[i] = 0;

    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        apref[x]++;
        a[x]++;
        b[i] = x;
    }
    sort(b+1, b+n+1);

    set<int> poses = {1, n+1};
    for (int i=2; i<=n; i++)
        if (b[i] != b[i-1])
            poses.insert(i);

    for (int i=2; i<=n; i++)
        apref[i]+=apref[i-1];
//    cout<<"ap "<<apref[3]<<"\n";
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j] = 0;
    for (int i=1; i<=n; i++)
        dp[1][i] = apref[b[i]-1];

    for (int i=1; i<n/2; i++)
    {
        for (int j=1; j<=n; j++)
        {
            int q = (apref[b[j]-1] - 2*i + 1);
            if (q <= 0)
                continue;
            q %= MOD;

            int k = *poses.upper_bound(j);
//            cout<<j<<" "<<k<<"\n";
            dp[i+1][k] = (dp[i+1][k] + dp[i][j]*q) % MOD;

//            for (int k=j+1; k<=n; k++)
//                if (b[k] > b[j])
//                {
//                    dp[i+1][k] = (dp[i+1][k] + dp[i][j]*q) % MOD;
//                }
        }
        for(int j=1; j<=n; j++)
            dp[i+1][j] = (dp[i+1][j-1] + dp[i+1][j]) % MOD;
    }
//    for (int i=1; i<=n/2; i++, cout<<"\n")
//        for (int j=1; j<=n; j++)
//            cout<<dp[i][j]<<" ";

    int ans = dp[n/2][n];
    for (int i=1; i<=n; i++)
        ans *= rfact[a[i]], ans%=MOD;
    cout<<ans<<"\n";
//    cout<<dp[n/2][n]<<"\n";
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = rfact[0] = 1;
    for (int i=1; i<NMAX; i++)
        fact[i] = (i*fact[i-1])%MOD, rfact[i] = bpow(fact[i], MOD-2);

    int T;
    cin>>T;
    for (int i=1; i<=T; i++)
    {
        solve();
    }
}