/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 1e9 + 7;
//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int $result=1; base%=mod;
   while(expo) {   if(expo%2==1)  $result=($result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return $result;
}

void solve()
{
    int k, n;
    cin>>k>>n;

    map<string, int> mp;
    string s[7] = {"", "white", "yellow", "green", "blue", "red", "orange"};
    for(int i=1; i<=6; i++) mp[s[i]]=(i+1)/2;
    map<int, int> tc;

    int tot=1;
    for(int i=1; i<=k; i++) tot*=2;
    tot--;

    priority_queue<int> pq;
    map<int, array<int, 4>> dp;
    map<int, int> dc;

    for(int i=1; i<=n; i++)
    {
        int u; string col;
        cin>>u>>col;
        int j = mp[col];
        dc[u] = j;
        pq.push(u);
    }

    int ans=1;
    map<int, int> vis;

    while(!pq.empty())
    {
        int u = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=1;   tot--;
        if(u!=1) pq.push(u/2);
        int lc = 2*u;
        int rc = 2*u+1;
        if(vis[lc]==0 && vis[rc]==0)
        {
            dp[u][dc[u]]=1;
            continue;
        }
        if(vis[lc]==0 && vis[rc]==1)
        {
            for(int i=1; i<=3; i++)
            {
                if(dc[u]!=0 && dc[u]!=i) { dp[u][i]=0; continue; }
                int t1 = dp[rc][1] + dp[rc][2] + dp[rc][3] - dp[rc][i];
                dp[u][i] = t1%mod;
                if(dc[u]==0) { dp[u][i]*=2; dp[u][i]%=mod; }
            }
        }
        if(vis[lc]==1 && vis[rc]==0)
        {
            for(int i=1; i<=3; i++)
            {
                if(dc[u]!=0 && dc[u]!=i) { dp[u][i]=0; continue; }
                int t1 = dp[lc][1] + dp[lc][2] + dp[lc][3] - dp[lc][i];
                dp[u][i] = t1;
                if(dc[u]==0) { dp[u][i]*=2; dp[u][i]%=mod; }
            }
        }
        if(vis[lc]==1 && vis[rc]==1)
        {
            for(int i=1; i<=3; i++)
            {
                if(dc[u]!=0 && dc[u]!=i) { dp[u][i]=0; continue; }
                int t1 = dp[rc][1] + dp[rc][2] + dp[rc][3] - dp[rc][i]; t1%=mod;
                int t2 = dp[lc][1] + dp[lc][2] + dp[lc][3] - dp[lc][i]; t2%=mod;
                dp[u][i] = (t1*t2)%mod;
                if(dc[u]==0) { dp[u][i]*=2; dp[u][i]%=mod; }
            }
        }
    }

    ans = ((dp[1][1]+dp[1][2]+dp[1][3])%mod)*Power(4, tot);
    ans %= mod;
    if(ans<0) ans+=mod;

    cout<<ans<<endl;
}

int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}