#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int mod=998244353;
const int mod=1e9+7;
#define inf 0x3f3f3f3f
// #define DEBUG
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
int main()
{
    #ifdef DEBUG
    freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    #endif
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    ll l,r,z;
    cin>>n>>l>>r>>z;
    vector<int>num,vc;
    vector<vector<int>>dp;
    vector<vector<bool>>vis;
    vector<vector<int>>c(n+1,vector<int>(n+1));
    for(int i=0;i<=n;++i)
        for(int j=0;j<=i;++j)
        {
            if(i==j||j==0) c[i][j]=1;
            else if(j==1) c[i][j]=i;
            else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    function<int(int,int)>dfs=[&](int u,int x)
    {
        if(u==-1) return 1;
        if(vis[u][x]) return dp[u][x];
        vis[u][x]=true;
        int y=min(x*2+num[u],n*2);
        for(int i=vc[u];i<=n&&i<=y;i+=2)
            add(dp[u][x],1ll*dfs(u-1,y-i)*c[n][i]%mod);
        return dp[u][x];
    };
    auto sol=[&](int n,ll r,ll z)
    {
        num.clear();vc.clear();
        while(r) num.push_back(r&1),r>>=1;
        while(z) vc.push_back(z&1),z>>=1;
        ll mxsize=max(num.size(),vc.size());
        num.resize(mxsize);
        vc.resize(mxsize);
        dp=vector<vector<int>>(mxsize,vector<int>(2*n+1));
        vis=vector<vector<bool>>(mxsize,vector<bool>(2*n+1));
        return dfs(mxsize-1,0);
    };
    cout<<(sol(n,r,z)-sol(n,l-1,z)+mod)%mod<<'\n';
}