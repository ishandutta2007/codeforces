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
const int N=2e5+5,mod=1e9+7;
int n,a[N];
int tot,p[N];
bool use[N];
map<pair<int,int>,ll>vis;
ll lcm(int x,int y){return 1ll*x/__gcd(x,y)*y;}
int b[N];
ll query(int x,int y)
{
  // return lcm(b[x],b[y]);
  if(vis.count({x,y})) return vis[{x,y}];
  printf("? %d %d\n",x,y);
  fflush(stdout);
  ll ans;scanf("%lld",&ans);
  return vis[{x,y}]=vis[{y,x}]=ans;
}
namespace Miller_Rabin
{
	const int Pcnt=12;
	const ll p[Pcnt]={2,3,5,7,11,13,17,19,61,2333,4567,24251};
	ll pow(ll a,ll b,ll p)
	{
		ll ans=1;
		for(;b;a=a*a%p,b>>=1)if(b&1)ans=ans*a%p;
		return ans;
	}
	bool check(ll x,ll p)
	{
		if(x%p==0||pow(p%x,x-1,x)^1)return true;
		ll t,k=x-1;
		while((k^1)&1)
		{
			t=pow(p%x,k>>=1,x);
			if(t^1&&t^x-1)return true;
			if(!(t^x-1))return false;
		}
    return false;
	}
	bool MR(ll x)
	{
		if(x<2)return false;
		for(int i=0;i^Pcnt;++i)
		{
			if(!(x^p[i]))return true;
			if(check(x,p[i]))return false;
		}
    return true;
	}
}
namespace Pollard_Rho
{
	#define Rand(x) (1ll*rand()*rand()%(x)+1)
	ll gcd(const ll a,const ll b){return b?gcd(b,a%b):a;}
	ll mul(const ll x,const ll y,const ll X)
	{
		ll k=(1.0L*x*y)/(1.0L*X)-1,t=x*y-k*X;
		while(t<0)t+=X;return t;
	}
	ll PR(const ll x,const ll y)
	{
		int t=0,k=1;ll v0=Rand(x-1),v=v0,d,s=1;
		while(true)
		{
			v=(mul(v,v,x)+y)%x,s=mul(s,abs(v-v0),x);
			if(!(v^v0)||!s)return x;
			if(++t==k){if((d=gcd(s,x))^1)return d;v0=v,k<<=1;}
		}
	}
	void Resolve(ll x,ll&ans)
	{
		if(!(x^1)||x<=ans)return;
		if(Miller_Rabin::MR(x)){if(ans<x)ans=x;return;}
		ll y=x;while((y=PR(x,Rand(x)))==x);while(!(x%y))x/=y;
		Resolve(x,ans);Resolve(y,ans);
	}
	long long check(ll x)
	{
		ll ans=0;Resolve(x,ans);
		return ans;
	}
}
void sol(int cas)
{
  vis.clear();
  scanf("%d",&n);
  /*
  rep(i,1,n) b[i]=i;
  random_shuffle(b+1,b+1+n);
  int ss=rand()%10;
  rep(i,1,n) b[i]+=ss;
  printf("! ");
  rep(i,1,n) printf(i==n?"%d\n":"%d ",b[i]);
  */
  rep(i,1,n) a[i]=0;
  if(n<=100)
  {
    ll ans=0,x,y;
    rep(i,1,n)
      rep(j,i+1,n)
      {
        ll res=query(i,j);
        if(res>ans)
        {
          ans=res;
          x=i,y=j;
        }
      }
    int l=1,r=200000;
    while(l<r)
    {
      int m=(l+r+1)>>1;
      if(1ll*m*(m+1)<=ans) l=m;
      else r=m-1;
    }
    assert(1ll*l*(l+1)==ans);
    r=l+1;
    l=l-(n-2);
    vector<ll>v1,v2;
    rep(i,l,r)
      if(i!=r-1) v1.push_back(lcm(r-1,i));
    rep(i,1,n)
      if(i!=x) v2.push_back(query(i,x));
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1!=v2) swap(x,y);
    a[x]=r-1;a[y]=r;
    nep(i,r-2,l)
    {
      ans=0;
      rep(j,1,n)
      if(!a[j])
      {
        ll res=query(x,j);
        if(res>ans)
          ans=res,y=j;
      }
      a[y]=i;
      x=y;
    }
    printf("! ");
    rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);
    fflush(stdout);
    return;
  }
  vector<int>vc;
  rep(i,1,n) vc.push_back(i);
  random_shuffle(vc.begin(),vc.end());
  int s=min(5000,n/2);
  ll ans=0,x,y;
  while(s--)
  {
    int xx=vc.back();vc.pop_back();
    int yy=vc.back();vc.pop_back();
    ll res=Pollard_Rho::check(query(xx,yy));
    if(res>ans)
    {
      ans=res;
      x=xx;y=yy;
    }
  }
  int z=rand()*rand()%n+1;
  while(z==x||z==y) z=rand()*rand()%n+1;
  if(query(z,x)%ans!=0) x=y;
  a[x]=ans;
  // cout<<x<<' '<<ans<<endl;
  rep(i,1,n)
    if(i!=x)
    a[i]=query(i,x)/ans;
  printf("! ");
  rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);
  fflush(stdout);
}
int main()
{
  rep(i,2,N-1)
  {
    if(!use[i]) p[++tot]=i;
    for(int j=1;j<=tot&&i*p[j]<N;j++)
    {
      use[i*p[j]]=true;
      if(i%p[j]==0) break;
    }
  }
  // freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
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