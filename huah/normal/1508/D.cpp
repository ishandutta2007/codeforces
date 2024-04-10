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
void iary(int *a,int l,int r){rep(i,l,r)sc(a[i]);}
void iary(ll *a,int l,int r){rep(i,l,r)sc(a[i]);}
void oary(int *a,int l,int r){rep(i,l,r)printf(i==r?"%d\n":"%d ",a[i]);}
void oary(ll *a,int l,int r){rep(i,l,r)printf(i==r?"%lld\n":"%lld ",a[i]);}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=2e3+5,mod=1e9+7;
int n;
struct node
{
    int x,y,id,z;
}a[N];
vector<pair<int,int>>op;
ll xmul(ll x1,ll y1,ll x2,ll y2)
{
    return x1*y2-x2*y1;
}
bool cmp(node &x,node &y)
{
    return xmul(x.x-a[1].x,x.y-a[1].y,y.x-a[1].x,y.y-a[1].y)>0;
}
int f[N];
int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}
void cal()
{
    if(n==0) return;
    rep(i,2,n)
        if(a[i].x<a[1].x||a[i].x==a[1].x&&a[i].y<a[1].y)
        swap(a[1],a[i]);
    sort(a+2,a+1+n,cmp);
    rep(i,1,n) f[a[i].id]=a[i].id;
    rep(i,1,n) f[getf(a[i].id)]=getf(a[i].z);
    rep(i,2,n-1)
    {
        if(getf(a[i].id)!=getf(a[i+1].id))
        {
            op.push_back({a[i].id,a[i+1].id});
            swap(a[i].z,a[i+1].z);
            f[getf(a[i].id)]=getf(a[i+1].id);
        }
    }
    while(a[1].id!=a[1].z)
    {
        rep(i,2,n)
            if(a[i].id==a[1].z)
            {
                op.push_back({a[1].id,a[i].id});
                swap(a[1].z,a[i].z);
                break;
            }
    }
    rep(i,1,n) assert(a[i].id==a[i].z);
}
void sol(int cas)
{
    sc(n);
    rep(i,1,n) sc(a[i].x,a[i].y,a[i].z),a[i].id=i;
    int tot=0;
    rep(i,1,n)
        if(a[i].id!=a[i].z)
        a[++tot]=a[i];
    n=tot;
    cal();
    printf("%d\n",op.size());
    for(pair<int,int>x:op)
        cout<<x.first<<' '<<x.second<<'\n';
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
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