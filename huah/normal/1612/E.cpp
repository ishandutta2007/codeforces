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
mt19937_64 gen(time(0));
ll rdint(ll l,ll r){return uniform_int_distribution<ll>(l,r)(gen);}
const int N=3e5+5,mod1=1e9+7,mod2=998244353;
#define inf 0x3f3f3f3f
int n;
vector<int>vc[N];
int tot;
pair<ll,int>b[N];
void sol(int l,int r,int k)
{
  swap(b[l],b[rdint(l,r)]);
  int i=l,j=r;
  while(i<j)
  {
    while(i<j&&b[j]>=b[i]) j--;
    swap(b[i],b[j]);
    while(i<j&&b[i]<=b[j]) i++;
    swap(b[i],b[j]);
  }
  if(r-i+1==k) return;
  if(r-i>=k) sol(i+1,r,k);
  else sol(l,i-1,k-(r-i+1));
}
ll cal(int k)
{
  tot=0;
  for(int i=1;i<=200000;i++)
    if(int(vc[i].size()))
    {
      ll sum=0;
      for(int x:vc[i]) sum+=min(x,k);
      b[++tot]={sum,i};
    }
  if(tot<=k)
  {
    ll sum=0;
    for(int i=1;i<=tot;i++) sum+=b[i].first;
    return sum;
  }
  sol(1,tot,k);
  ll sum=0;
  for(int i=tot-k+1;i<=tot;i++)
    sum+=b[i].first;
  return sum;
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    sc(n);
    rep(i,1,n)
    {
      int a,b;sc(a,b);
      vc[a].push_back(b);
    }
    ll x=cal(1);
    int y=1;
    for(int i=2;i<=30;i++)
    {
      ll z=cal(i);
      if(x*i<z*y) x=z,y=i;
    }
    cal(y);
    printf("%d\n",y);
    for(int i=tot-y+1;i<=tot;i++)
      printf(i==tot?"%d\n":"%d ",b[i].second);
}