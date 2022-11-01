#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int mod=998244353;
const int mod=1e9+7;
// #define inf 0x3f3f3f3f
#define inf 0x3f3f3f3f3f3f3f3fll
// #define DEBUG
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const double eps=1e-8;
int main()
{
    #ifdef DEBUG
    freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    int t=1;
    while(t--)
    {
        int n,k;cin>>n>>k;
        vector<vector<int>>e(n+1);
        for(int i=1;i<n;++i)
        {
            int u,v;cin>>u>>v;
            e[u].push_back(v);e[v].push_back(u);
        }
        vector<int>f(n+1),inv(n+1),invf(n+1);
        f[0]=f[1]=invf[0]=invf[1]=inv[1]=1;
        for(int i=2;i<=n;++i)
        {
            f[i]=1ll*f[i-1]*i%mod;
            inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
            invf[i]=1ll*invf[i-1]*inv[i]%mod;
        }
        auto C=[&](int n,int m){if(m>n) return 0ll;return 1ll*f[n]*invf[m]%mod*invf[n-m]%mod;};
        int ans=0;
        vector<int>si(n+1),dp(n+1),g(n+1);
        auto update=[&](int u,int v)
        {
            dp[u]=(dp[u]+1ll*(si[u]-si[v])*C(si[v],k)%mod)%mod;
            g[u]=(g[u]+C(si[v],k)%mod)%mod;
            dp[u]=(dp[u]+dp[v])%mod;
        };
        auto iupdate=[&](int u,int v)
        {
            dp[u]=(dp[u]+mod-1ll*(si[u]-si[v]-si[v])*C(si[v],k)%mod)%mod;
            dp[u]=(dp[u]+mod-1ll*g[u]*si[v]%mod)%mod;
            g[u]=(g[u]+mod-C(si[v],k)%mod)%mod;
            dp[u]=(dp[u]+mod-dp[v])%mod;
        };
        function<void(int,int)>dfs1=[&](int u,int p)
        {
            si[u]=1;
            dp[u]=g[u]=0;
            for(int v:e[u])
            {
                if(v==p) continue;
                dfs1(v,u);
                si[u]+=si[v];
            }
            for(int v:e[u])
            {
                if(v==p) continue;
                update(u,v);
            }
        };
        function<void(int,int)>dfs2=[&](int u,int p)
        {
            ans=(ans+1ll*n*C(n,k)%mod+mod-dp[u])%mod;
            for(int v:e[u])
            {
                if(v==p) continue;
                int siu=si[u],siv=si[v],dpu=dp[u],dpv=dp[v],gu=g[u],gv=g[v];
                iupdate(u,v);
                si[u]-=si[v];
                dp[v]=(dp[v]+1ll*g[v]*si[u])%mod;
                si[v]+=si[u];
                update(v,u);
                dfs2(v,u);
                si[u]=siu;si[v]=siv;dp[u]=dpu;dp[v]=dpv;g[u]=gu;g[v]=gv;
            }
        };
        dfs1(1,0);
        dfs2(1,0);
        ans=(ans+mod)%mod;
        cout<<ans<<'\n';
    }
}