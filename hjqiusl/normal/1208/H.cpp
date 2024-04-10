//~~
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class T> using tre=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
pa tr[N<<2];
int c[N];
tre<pa>S[N];
int dfn[N],idfn[N],ffa[N],siz[N],son[N],top[N],to[N];
int DFN;
int n,m,q;
decltype(begin(S[0]))d[N];
poly G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
int rk(tre<pa>&x,int v){
	return x.order_of_key(mp(v,inf));
}
bool chk(int k,int p,int ad)
{
	int x=rk(S[k],p)+ad;
	int y=S[k].size()+1-x;
	return y-x>=p;
}
void upd(int k,int &r,int ad)
{
	while (!chk(k,r-1,ad))
	{
		r--;
	}
	while (chk(k,r,ad))
	{
		r++;
	}
	// cout<<"???"<<r<<" "<<k<<" "<<ad<<" "<<chk(k,r-1,ad)<<endl;
}
pa merge(pa x,pa y)
{
	return mp(min(x.se,max(x.fi,y.fi)),min(x.se,max(x.fi,y.se)));
}
void update(int k,int l,int r,int L)
{
	if (l==r)
	{
		int u=idfn[l];
		if (G[u].size()==1&&u!=1)
		{
			if (c[u])
			{
				tr[k]=mp(inf,inf);
			} else tr[k]=mp(-inf,-inf);
		} else
		{
			upd(u,tr[k].fi,1);
			upd(u,tr[k].se,0);
		}
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L);
	else update(k<<1|1,mid+1,r,L);
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
}		
pa query(int k,int l,int r,int L,int R)
{
	// cout<<k<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	if (L<=l&&r<=R) return tr[k];
	int mid=l+(r-l)/2;
	// pa res=mp(-inf,inf);
	if (R<=mid) return query(k<<1,l,mid,L,R);
	if (L>mid) return query(k<<1|1,mid+1,r,L,R);
	return merge(query(k<<1,l,mid,L,R),query(k<<1|1,mid+1,r,L,R));
	// return res;
}
void build(int k,int l,int r)
{
	tr[k]=mp(0,0);
	if (l==r) return;
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void dfs(int k,int fa)
{
	ffa[k]=fa;
	siz[k]=1;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		if (siz[u]>siz[son[k]]) son[k]=u;
		siz[k]+=siz[u];
	}
}
void dfs1(int k,int tp)
{
	dfn[k]=++DFN;
	idfn[DFN]=k;
	top[k]=tp;
	if (son[k]) dfs1(son[k],tp),to[k]=to[son[k]];
	else to[k]=k;
	for (auto u:G[k])
	{
		if (u==ffa[k]||u==son[k]) continue;
		dfs1(u,u);
		pa x=query(1,1,n,dfn[u],dfn[to[u]]);
		d[u]=S[k].insert(mp(x.fi,u)).fi;
	}
	update(1,1,n,dfn[k]);
}

void BellaKira()
{
	n=read();m=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ad(x,y);
		ad(y,x);
	}
	for (int i=1;i<=n;i++) c[i]=read();
	build(1,1,n);
	dfs(1,0);
	dfs1(1,1);
	// return ;
	// cout<<"??? "<<query(1,1,n,dfn[1],dfn[to[1]]).fi<<endl;
	q=read();
	for (int i=1;i<=q;i++)
	{
		int opt=read();
		if (opt==1)
		{
			int x=read();
			// cout<<m<<" "<<query(1,1,n,dfn[x],dfn[to[x]]).fi<<endl;
			if (query(1,1,n,dfn[x],dfn[to[x]]).fi>m) puts("1");
			else puts("0");
		} else
		if (opt==2)
		{
			int x=read(),y=read();
			c[x]=y;
			while (x)
			{
				update(1,1,n,dfn[x]);
				// cout<<"upd "<<x<<endl;
				x=top[x];
				if (x==1) break;
				int k=ffa[x];
				int u=x;
				// cout<<"ers "<<u<<endl;
				S[k].erase(d[u]);
				// cout<<"ers ac"<<endl;
				pa xx=query(1,1,n,dfn[u],dfn[to[u]]);
				d[u]=S[k].insert(mp(xx.fi,u)).fi;
				x=ffa[x];
				// cout<<"??"<<x<<" "<<ffa[x]<<endl;
			}
		} else m=read();
	}
			
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/