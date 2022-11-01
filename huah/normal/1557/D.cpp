#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
const int N=6e5+5,mod=998244353;
int n,m,op[N],l[N],r[N],hs[N];
vector<pair<int,int>>vc[N];
pair<int,int>t[N<<2],lz[N<<2];
void update(int l,int r,int k)
{
    t[k]=max(t[k],lz[k]);
    if(l!=r)
        lz[k<<1]=max(lz[k<<1],lz[k]),lz[k<<1|1]=max(lz[k<<1|1],lz[k]);
    lz[k]={0,0};
}
void ins(int l,int r,int k,int x,int y,pair<int,int>v)
{
    if(lz[k]!=make_pair(0,0)) update(l,r,k);
    if(r<x||l>y) return;
    if(l>=x&&r<=y)
    {
        lz[k]=v;
        update(l,r,k);
        return;
    }
    int m=(l+r)>>1;
    ins(l,m,k<<1,x,y,v);ins(m+1,r,k<<1|1,x,y,v);
    t[k]=max(t[k<<1],t[k<<1|1]);
}
pair<int,int>query(int l,int r,int k,int x,int y)
{
    if(lz[k]!=make_pair(0,0)) update(l,r,k);
    if(r<x||l>y) return make_pair(0,0);
    if(l>=x&&r<=y) return t[k];
    int m=(l+r)>>1;
    return max(query(l,m,k<<1,x,y),query(m+1,r,k<<1|1,x,y));
}
pair<int,int>dp[N];
bool vis[N];
void sol(int cas)
{
    sc(n,m);
    rep(i,1,m) sc(op[i],l[i],r[i]),hs[i]=l[i],hs[i+m]=r[i];
    sort(hs+1,hs+1+2*m);
    int tot=unique(hs+1,hs+1+2*m)-hs-1;
    rep(i,1,m)
    {
        l[i]=lower_bound(hs+1,hs+1+tot,l[i])-hs;
        r[i]=lower_bound(hs+1,hs+1+tot,r[i])-hs;
        vc[op[i]].push_back({l[i],r[i]});
    }
    for(int i=1;i<=n;i++)
    {
        for(pair<int,int>x:vc[i])
            dp[i]=max(dp[i],query(1,tot,1,x.first,x.second));
        dp[i].first++;
        for(pair<int,int>x:vc[i])
            ins(1,tot,1,x.first,x.second,{dp[i].first,i});
    }
    pair<int,int>mx={0,0};
    for(int i=1;i<=n;i++) mx=max(mx,dp[i]);
    for(int i=1;i<=n;i++)
        if(mx==dp[i])
        {
            int now=i;
            while(now)
            {
                vis[now]=true;
                now=dp[now].second;
            }
            break;
        }
    vector<int>ans;
    for(int i=1;i<=n;i++)
        if(!vis[i]) ans.push_back(i);
    printf("%d\n",int(ans.size()));
    for(int i=0;i<ans.size();i++)
        printf(i==ans.size()-1?"%d\n":"%d ",ans[i]);
}
int main()
{
//   freopen("1.in", "r",stdin);
  // freopen("2.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  // scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/