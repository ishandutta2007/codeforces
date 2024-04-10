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
const int N=1e5+5,mod=1e9+7;
int n,m,id,tot,rt,t[N*50],tim[N*50],ls[N*50],rs[N*50],f[N*50];
string op[N];
ll up,A[N],B[N];
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
void ins(ll l,ll r,ll x,ll y,int &now,int tim)
{
  if(r<x||l>y) return;
  if(!now) now=++tot;
  if(l>=x&&r<=y)
  {
    t[now]=tim;
    return;
  }
  ll m=(l+r)>>1;
  ins(l,m,x,y,ls[now],tim);ins(m+1,r,x,y,rs[now],tim);
  t[now]=-1;
}
struct node
{
  ll l,r;
  int id;
};
vector<pair<int,int>>e[N];
bool jiao(ll l1,ll r1,ll l2,ll r2)
{
  return max(l1,l2)<=min(r1,r2);
}
vector<node> build(ll l,ll r,int now)
{
  vector<node>ans;
  if(!now) {ans.push_back({l,r,++id});tim[id]=0;return ans;}
  if(t[now]!=-1)
  {
    ans.push_back({l,r,++id});
    tim[id]=t[now];
    return ans;
  }
  ll m=(l+r)>>1;
  ans=build(l,m,ls[now]);
  vector<node>res=build(m+1,r,rs[now]);
  int i=0,j=0;
  ll len=m-l+1;
  assert(ans[0].l==res[0].l-len);
  assert(ans.back().r==res.back().r-len);
  while(i<ans.size()&&j<res.size())
  {
    if(jiao(ans[i].l,ans[i].r,res[j].l-len,res[j].r-len))
      e[max(tim[ans[i].id],tim[res[j].id])].push_back({ans[i].id,res[j].id});
    if(ans[i].r<res[j].r-len) i++;
    else j++;
  }
  ans.insert(ans.end(),res.begin(),res.end());
  return ans;
}
void sol(int cas)
{
  cin>>n>>m;
  up=(1ll<<n)-1;
  rep(i,1,m) cin>>op[i]>>A[i]>>B[i];
  rep(i,1,m)
  if(op[i]=="block") ins(0,up,A[i],B[i],rt,m-i+1);
  vector<node>vc=build(0,up,rt);
  vector<ll>g;
  for(node &x:vc) g.push_back(x.r);
  rep(i,1,id) f[i]=i;
  for(pair<int,int>x:e[0]) f[getf(x.first)]=getf(x.second);
  vector<int>ans;
  nep(i,m,1)
  if(op[i]=="ask")
  {
    A[i]=lower_bound(g.begin(),g.end(),A[i])-g.begin();
    B[i]=lower_bound(g.begin(),g.end(),B[i])-g.begin();
    A[i]=vc[A[i]].id;
    B[i]=vc[B[i]].id;
    ans.push_back(getf(A[i])==getf(B[i]));
  }
  else
  { 
    for(pair<int,int>x:e[m-i+1])
      f[getf(x.first)]=getf(x.second);
  }
  reverse(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++) out(ans[i]);
}
int main()
{
    // freopen("1.in","r",stdin);
    srand(time(0));
    int t=1,cas=0;
    // scanf("%d",&t);
    while(t--)
    {
        sol(++cas);
    }
}