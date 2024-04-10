#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
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
const int N=4e5+5,mod=998244353;
ll f[N],invf[N];
int n,m;
ll C(int n,int m){return f[n]*invf[m]%mod*invf[n-m]%mod;}
int bit[N];
void add(int x,int v)
{
    while(x<=n)
        bit[x]+=v,x+=x&-x;
}
int query(int k)
{
    int ans=0,sum=0;
    for(int i=1<<18;i;i>>=1)
        if((ans|i)<=n&&sum+bit[ans|i]<k)
        ans|=i,sum+=bit[ans];
    return ans+1;
}
bool vis[N];
void sol(int cas)
{
    sc(n,m);
    int s=n-1;
    vector<int>vc;
    rep(i,1,m)
    {
        int x,y;sc(x,y);
        vc.push_back(y);
    }
    reverse(vc.begin(),vc.end());
    vector<int>del;
    for(int x:vc)
    {
        int p=query(x);
        add(p,-1);
        vis[p]=true;
        if(!vis[p+1]) s--;
        del.push_back(p);
    }
    for(int p:del) add(p,1),vis[p]=false;
    printf("%lld\n",C(n+s,s));
}
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  f[0]=f[1]=invf[0]=invf[1]=1;
  rep(i,2,N-1) f[i]=1ll*f[i-1]*i%mod,invf[i]=(mod-mod/i)*invf[mod%i]%mod;
  rep(i,2,N-1) invf[i]=invf[i-1]*invf[i]%mod;
  rep(i,1,N-1) bit[i]=i&-i;
  srand(time(0));
  int t=1,cas=0;
  scanf("%d",&t);
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