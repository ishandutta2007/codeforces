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
const int N=5e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,a[N],b[N],c[N];
int d[]={0,1,6,4,2,3,5,4};
int query(string s,int x,int y)
{
  // if(s=="or") return d[x]|d[y];
  // return d[x]&d[y];
  cout<<s<<' '<<x<<' '<<y<<'\n';
  fflush(stdout);
  int ans;scanf("%d",&ans);
  return ans;
}
int main()
{
  	// freopen("1.in","r",stdin);
    int t=1;
    sc(t);
    while(t--)
    {
		int n,m;
		sc(m,n);
		int x1,y1,x2,y2;
		sc(x1,y1);sc(x2,y2);
		int nn,mm;
		sc(mm,nn);
		int ans=mod;
		if(x1<=mm&&y1<=nn)
		{
			if(x2+mm-x1<=m) ans=min(ans,mm-x1);
			if(y2+nn-y1<=n) ans=min(ans,nn-y1);
		}
		else ans=0;
		if(x2>=m-mm&&y2>=n-nn)
		{
			if(x1-(x2-(m-mm))>=0) ans=min(ans,x2-(m-mm));
			if(y1-(y2-(n-nn))>=0) ans=min(ans,y2-(n-nn));
		}
		else ans=0;
		if(x1<=mm&&y2>=n-nn)
		{
			if(x2+mm-x1<=m) ans=min(ans,mm-x1);
			if(y1-(y2-(n-nn))>=0) ans=min(ans,y2-(n-nn));
		}
		else ans=0;
		if(x2>=m-mm&&y1<=nn)
		{
			if(x1-(x2-(m-mm))>=0) ans=min(ans,x2-(m-mm));
			if(y2+nn-y1<=n) ans=min(ans,nn-y1);
		}
		else ans=0;
		if(ans==mod) ans=-1;
		out(ans);
    }
}
/*
7 2 5
0 4 0
*/