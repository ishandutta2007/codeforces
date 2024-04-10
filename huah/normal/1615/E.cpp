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
const int N=2e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,k,dep[N],rev[N],fa[N],L[N],R[N],tot,s[N];
vector<int>e[N];
bool del[N];
void dfs(int u,int p)
{
	dep[u]=dep[p]+1;
	fa[u]=p;
	bool flag=true;
	L[u]=tot+1;
	for(int v:e[u])
		if(v!=p) dfs(v,u),flag=false;
	if(flag) s[++tot]=u,rev[tot]=u;
	R[u]=tot;
}
int t[N<<2],lz[N<<2];
void build(int l,int r,int k)
{
	lz[k]=0;
	if(l==r){t[k]=dep[s[l]];return;}
	int m=(l+r)>>1;
	build(l,m,k<<1);build(m+1,r,k<<1|1);
	t[k]=max(t[k<<1],t[k<<1|1]);
}
void update(int l,int r,int k)
{
	t[k<<1]+=lz[k];
	t[k<<1|1]+=lz[k];
	lz[k<<1]+=lz[k];
	lz[k<<1|1]+=lz[k];
	lz[k]=0;
}
void fix(int l,int r,int k,int x,int y,int v)
{
	if(r<x||l>y) return;
	if(l>=x&&r<=y)
	{
		t[k]+=v;
		lz[k]+=v;
		return;
	}
	if(lz[k]) update(l,r,k);
	int m=(l+r)>>1;
	fix(l,m,k<<1,x,y,v);fix(m+1,r,k<<1|1,x,y,v);
	t[k]=max(t[k<<1],t[k<<1|1]);
}
int query(int l,int r,int k)
{
	if(l==r) return l;
	if(lz[k]) update(l,r,k);
	int m=(l+r)>>1;
	if(t[k<<1]>=t[k<<1|1]) return query(l,m,k<<1);
	return query(m+1,r,k<<1|1);
}
int main()
{
	{
		sc(n,k);
		rep(i,1,n) e[i].clear(),del[i]=false;
		tot=0;
		rep(i,1,n-1)
		{
			int u,v;sc(u,v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		build(1,tot,1);
		int ans=0;
		ll res=-1e18;
		rep(i,1,k)
		{
			int y=t[1];
			int x=query(1,tot,1);
			ans+=y;
			x=rev[x];
			while(y--) fix(1,tot,1,L[x],R[x],-1),x=fa[x];
			int b=min(n/2,n-ans);
			res=max(res,1ll*i*(n-i)-1ll*b*(n-b));
		}
		out(res);
	}
}