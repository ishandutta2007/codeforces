#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 2e5 + 100;

int dp[nmax];
int p[nmax];
int x[nmax];
int y[nmax];
int s[nmax];
set<pair<int, int> > st;

int mod = 998244353;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>x[i]>>y[i]>>s[i];
    int ans=x[n] + 1;
    int pos=0;
    for (int i=1; i<=n; i++)
    {
        st.insert({x[i], i});

        auto it = st.lower_bound({y[i], 0});
        int j = it->se;

        dp[i] = ((x[i] - y[i] + p[i-1] - p[j-1])%mod + mod)%mod;
        p[i] = (p[i-1] + dp[i])%mod;
        if (s[i] == 1)
            ans+=dp[i];
    }
    cout<<ans%mod<<"\n";
}