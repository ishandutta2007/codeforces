#pragma GCC optimize(2)
#include<bits/stdc++.h>
typedef long long ll;
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
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=3e5+5,mod=998244353;
#define inf 0x3f3f3f3f
int n,ans[N];
vector<int>e[N];
bool vis[N];
void dfs(int u,int p)
{
    vis[u]=vis[p]^1;
    for(int v:e[u])
    {
        if(v==p) continue;
        dfs(v,u);
    }
}
int upbit(int x)
{
    int ans=0;
    while(x) x>>=1,ans++;
    return 1<<(ans-1);
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,1,n) e[i].clear(),vis[i]=false;
        rep(i,1,n-1)
        {
            int u,v;sc(u,v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1,0);
        vector<int>v1,v2;
        rep(i,1,n)
            if(vis[i]) v1.push_back(i);
            else v2.push_back(i);
        if(v1.size()>v2.size()) swap(v1,v2);
        int u=v1.size();
        rep(i,1,n)
            if(upbit(i)&u)
            {
                ans[v1.back()]=i;
                v1.pop_back();
            }
            else ans[v2.back()]=i,v2.pop_back();
        rep(i,1,n)
            printf(i==n?"%d\n":"%d ",ans[i]);
    }
}
/*
*/