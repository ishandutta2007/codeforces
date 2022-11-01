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
const int N=1e5+5,mod=998244353;
int n,m,q;
ll a[N],b[N],da[N],db[N];
ll t[N<<2],lz[N<<2];
struct node
{
  int len;
  ll sum,fsum;
  node operator+(const node&o)const
  {
    node ans;
    ans.len=len+o.len;
    ans.sum=sum+o.sum;
    ans.fsum=fsum+o.fsum+sum*o.len;
    return ans;
  }
}s[N<<2];
void build(int l,int r,int k)
{
  if(l==r){t[k]=db[l];s[k]={1,db[l],db[l]};return;}
  int m=(l+r)>>1;
  build(l,m,k<<1);build(m+1,r,k<<1|1);
  t[k]=max(t[k<<1],t[k<<1|1]);
  s[k]=s[k<<1]+s[k<<1|1];
}
void update(int l,int r,int k)
{
  if(l!=r)
  {
    int m=(l+r)>>1;
    s[k<<1].sum+=lz[k]*(m-l+1);
    s[k<<1].fsum+=lz[k]*(1ll*(m-l+1)*(m-l+2)/2);
    s[k<<1|1].sum+=lz[k]*(r-m);
    s[k<<1|1].fsum+=lz[k]*(1ll*(r-m)*(r-m+1)/2);
    t[k<<1]+=lz[k];
    t[k<<1|1]+=lz[k];
    lz[k<<1]+=lz[k];
    lz[k<<1|1]+=lz[k];
  }
  lz[k]=0;
}
void ins(int l,int r,int k,int x,int v)
{
  if(r<x) return;
  if(l>=x)
  {
    t[k]+=v;
    s[k].sum+=1ll*(r-l+1)*v;
    s[k].fsum+=1ll*(r-l+1)*(r-l+2)/2*v;
    lz[k]+=v;
    return;
  }
  int m=(l+r)>>1;
  if(lz[k]) update(l,r,k);
  ins(l,m,k<<1,x,v);
  ins(m+1,r,k<<1|1,x,v);
  t[k]=max(t[k<<1],t[k<<1|1]);
  s[k]=s[k<<1]+s[k<<1|1];
}
int query(int l,int r,int k,ll v)
{
  if(t[k]<=v) return r;
  if(l==r) return -1;
  int m=(l+r)>>1;
  if(lz[k]) update(l,r,k);
  if(t[k<<1]>v) return query(l,m,k<<1,v);
  return max(m,query(m+1,r,k<<1|1,v));
}
node qsum(int l,int r,int k,int x,int y)
{
  if(l>=x&&r<=y) return s[k];
  int m=(l+r)>>1;
  if(lz[k]) update(l,r,k);
  if(x<=m&&y>m) return qsum(l,m,k<<1,x,y)+qsum(m+1,r,k<<1|1,x,y);
  if(x<=m) return qsum(l,m,k<<1,x,y);
  return qsum(m+1,r,k<<1|1,x,y);
}
ll query()
{
  ll x=a[1]+b[1],sum=x;
  int j=1;
  for(int i=1;i<n;i++)
  {
    int p=query(1,m-1,1,da[i]);
    if(p>=j)
    {
      node g=qsum(1,m-1,1,j,p);
      sum+=x*(p-j+1)+g.fsum;
      x+=g.sum;
      j=p+1;
    }
    x+=da[i];
    sum+=x;
  }
  if(j<=m-1)
  {
    node g=qsum(1,m-1,1,j,m-1);
    sum+=x*(m-j)+g.fsum;
  }
  return sum;
}
int main()
{
  	// freopen("1.in","r",stdin);
    sc(n,m,q);
    rep(i,1,n) sc(a[i]);
    rep(i,1,m) sc(b[i]);
    rep(i,1,n-1) da[i]=a[i+1]-a[i];
    rep(i,1,m-1) db[i]=b[i+1]-b[i];
    build(1,m-1,1);
    while(q--)
    {
      int op;sc(op);
      ll k,d;sc(k,d);
      if(op==1) 
      {
        if(k==n) a[1]+=d,k--;
        rep(i,n-k,n-1) da[i]+=d;
      }
      else
      {
        if(k==m) b[1]+=d,k--;
        ins(1,m-1,1,m-k,d);
      }
      printf("%lld\n",query());
    } 
}