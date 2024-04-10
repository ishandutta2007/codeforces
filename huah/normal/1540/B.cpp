#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
const int N=205,mod=1e9+7;
int n;
ll inv[N],c[N][N];
ll C(int n,int m)
{
    if(m==0||m==n) return 1;
    if(m==1) return n;
    if(c[n][m]) return c[n][m];
    return c[n][m]=(C(n-1,m-1)+C(n-1,m))%mod;
}
ll invc[N][N];
ll qpow(ll a,ll n)
{
    ll ans=1;
    for(;n;n>>=1,a=a*a%mod)
        if(n&1) ans=ans*a%mod;
    return ans;
}
ll invC(int n,int m)
{
    if(invc[n][m]) return invc[n][m];
    return invc[n][m]=qpow(C(n,m),mod-2);
}
vector<int>e[N];
int si[N],fa[N];
void dfs(int u,int p)
{
    fa[u]=p;
    si[u]=1;
    for(int v:e[u])
    if(v!=p)
        dfs(v,u),si[u]+=si[v];
}
bool vis[N];
int top,s[N];
ll ans,dp[N][N];
ll Dp(int x,int y)
{
    //return C(x+y-1,y)*invC(x+y,y)%mod;
    if(x==0) return 1;
    if(y==0) return 0;
    if(dp[x][y]) return dp[x][y];
    return dp[x][y]=(Dp(x-1,y)+Dp(x,y-1))*inv[2]%mod;
}
void dfs(int u)
{
    s[++top]=u;
    vis[u]=true;
    if(top>=2)
    {
        if(s[1]>s[top])
        {
            if(fa[s[1]]==s[2]) ans=(ans+si[s[1]])%mod;
            else ans=(ans+n-si[s[2]])%mod;
            for(int i=2;i<top;i++)
            {
                int sum;
                if(fa[s[i-1]]==s[i]&&fa[s[i+1]]==s[i])
                    sum=n-si[s[i-1]]-si[s[i+1]];
                else if(fa[s[i-1]]==s[i])
                    sum=si[s[i]]-si[s[i-1]],assert(fa[s[i]]==s[i+1]);
                else sum=si[s[i]]-si[s[i+1]],assert(fa[s[i]]==s[i-1]);
                ans=(ans+sum*Dp(i-1,top-i)%mod)%mod;
                //cout<<s[1]<<' '<<s[top]<<' '<<Dp(i-1,top-i)<<endl;
            }
        }
        /*
        else
        {
            if(fa[s[top]]==s[top-1]) ans=(ans+si[s[top]])%mod;
            else ans=(ans+n-si[s[top-1]])%mod;
            for(int i=top-1;i>1;i--)
            {
                int sum;
                if(fa[s[i-1]]==s[i]&&fa[s[i+1]]==s[i])
                    sum=n-si[s[i-1]]-si[s[i+1]];
                else if(fa[s[i-1]]==s[i])
                    sum=si[s[i]]-si[s[i-1]];
                else sum=si[s[i]]-si[s[i+1]];
                ans=(ans+sum*C(top-2,i-1)%mod*invC(top-1,i-1)%mod)%mod;
            }
        }
        */
    }
    for(int v:e[u])
        if(!vis[v])
        dfs(v);
    vis[u]=false;
    top--;
}
int main()
{
    inv[1]=1;
    rep(i,2,N-1) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    sc(n);
    rep(i,1,n-1)
    {
        int x,y;sc(x,y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        dfs(i);
    out(ans*inv[n]%mod);
}