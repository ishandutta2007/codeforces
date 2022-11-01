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
const int N=2e5+5;
const int inf=2e9;
int n,a[N],b[N],hs[N];
vector<pair<int,int>>v1,v2;
int t1[N<<2],t2[N<<2];
void build(int l,int r,int k,int *t)
{
  t[k]=inf;
  if(l==r) return;
  int m=(l+r)>>1;
  build(l,m,k<<1,t);
  build(m+1,r,k<<1|1,t);
}
void ins(int l,int r,int k,int x,int v,int *t)
{
  t[k]=min(t[k],v);
  if(l==r) return;
  int m=(l+r)>>1;
  if(x<=m) ins(l,m,k<<1,x,v,t);
  else ins(m+1,r,k<<1|1,x,v,t);
}
int query(int l,int r,int k,int x,int y,int *t)
{
  if(r<x||l>y||x>y) return inf;
  if(l>=x&&r<=y) return t[k];
  int m=(l+r)>>1;
  return min(query(l,m,k<<1,x,y,t),query(m+1,r,k<<1|1,x,y,t));
}
bool cmp1(pair<int,int>&x,pair<int,int>&y)
{
  return x.first<y.first;
}
bool cmp2(pair<int,int>&x,pair<int,int>&y)
{
  return x.second<y.second;
}
void sol(int cas)
{
  sc(n);
  rep(i,1,n) sc(a[i]),hs[i]=a[i];
  rep(i,1,n) sc(b[i]);
  sort(hs+1,hs+1+n);
  ll ans=0,sum=0;
  rep(i,1,n)
  {
    ans+=abs(a[i]-b[i]);
    if(a[i]>b[i]) v1.push_back({a[i],b[i]});
    if(a[i]<b[i]) v2.push_back({a[i],b[i]});
  }
  sum=ans;
  sort(v1.begin(),v1.end(),cmp1);
  sort(v2.begin(),v2.end(),cmp2);
  build(1,n,1,t1);
  build(1,n,1,t2);
  for(int i=0,j=0;i<v1.size();i++)
  {
    while(j<v2.size()&&v2[j].second<=v1[i].first)
    {
      int x=lower_bound(hs+1,hs+1+n,v2[j].first)-hs;
      ins(1,n,1,x,-v2[j].second+v2[j].first-abs(v2[j].first-v2[j].second),t1);
      ins(1,n,1,x,-v2[j].second-v2[j].first-abs(v2[j].first-v2[j].second),t2);
      j++;
    }
    int x=lower_bound(hs+1,hs+1+n,v1[i].second)-hs;
    ans=min(ans,sum+v1[i].first-v1[i].second-abs(v1[i].first-v1[i].second)+query(1,n,1,x,n,t1));
    ans=min(ans,sum+v1[i].first+v1[i].second-abs(v1[i].first-v1[i].second)+query(1,n,1,1,x-1,t2));
  }
  build(1,n,1,t1);
  build(1,n,1,t2);
  for(int i=v1.size()-1,j=v2.size()-1;i>=0;i--)
  {
    while(j>=0&&v2[j].second>=v1[i].first)
    {
      int x=lower_bound(hs+1,hs+1+n,v2[j].first)-hs;
      ins(1,n,1,x,v2[j].second+v2[j].first-abs(v2[j].first-v2[j].second),t1);
      ins(1,n,1,x,v2[j].second-v2[j].first-abs(v2[j].first-v2[j].second),t2);
      j--;
    }
    int x=lower_bound(hs+1,hs+1+n,v1[i].second)-hs;
    ans=min(ans,sum-v1[i].first-v1[i].second-abs(v1[i].first-v1[i].second)+query(1,n,1,x,n,t1));
    ans=min(ans,sum-v1[i].first+v1[i].second-abs(v1[i].first-v1[i].second)+query(1,n,1,1,x-1,t2));
  }
  out(ans);
}
/*
a[i]>b[i]
b[j]>a[j]

a[i] b[j] b[i] a[j]
a[i] b[j] a[j] b[i]
b[j] a[i] a[j] b[i]
b[j] a[i] b[i] a[j]
*/
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
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