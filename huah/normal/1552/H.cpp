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
const int N=2e5+5,mod=998244353,G=3,Gi=332748118;
int query(vector<pair<int,int>>vc)
{
    printf("? %d\n",int(vc.size()));
    for(auto x:vc)
        printf("%d %d\n",x.first,x.second);
    fflush(stdout);
    int ans;scanf("%d",&ans);return ans;
}
bool vis[205];
int F[205];
int f(int d)
{
    if(d>200) return 0;
    if(vis[d]) return F[d];
    vis[d]=true;
    vector<pair<int,int>>vc;
    for(int i=d;i<=200;i+=d)
        for(int j=1;j<=200;j++)
        vc.push_back({i,j});
    // cout<<"Q: "<<d<<endl;
    return F[d]=query(vc);
}
void sol(int cas)
{
    int s=f(1);
    int l=0,r=7;
    while(l<r)
    {
        int m=(l+r)>>1;
        if(s%(1<<m)) {r=m-1;continue;}
        int t=abs(2*f(2*(1<<m))-abs(s/(1<<m)));
        if(t==0) {l=m+1;continue;}
        int d=s/t;
        if(d%(1<<m)==0&&d%(1<<(m+1))) r=m;
        else r=m-1;
    }
    int t=abs(2*f(1<<(l+1))-s/(1<<l));
    int d=s/t;
    printf("! %d\n",(t-1)*2+(d-1)*2);
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