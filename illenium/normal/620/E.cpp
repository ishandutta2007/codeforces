#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<bitset>
#define ll long long
#define maxn 400005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

bitset <65> s[maxn<<2],g;
vector <int> mp[maxn];
int n,m,siz[maxn],dfn[maxn],w[maxn],f[maxn],cnt,col[maxn];
struct node{int l,r,f;}tree[maxn<<2];

inline void dfs1(int u,int fa)
{
	siz[u]=1; w[u]=++cnt; dfn[cnt]=u;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(v==fa) continue;
		f[v]=u;
		dfs1(v,u);
		siz[u]+=siz[v];
	}
}

inline void pushup(int now)
{
	s[now]=s[now<<1]|s[now<<1|1];
}

inline void build(int now,int l,int r)
{
	tree[now].l=l; tree[now].r=r; tree[now].f=0;
	if(l==r)
	{
		s[now][col[dfn[l]]]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	pushup(now);
}

inline void pushdown(int now)
{
	if(tree[now].f)
	{
		if(tree[now].l!=tree[now].r)
		{
			s[now<<1].reset(); s[now<<1|1].reset();
			tree[now<<1].f=tree[now].f; tree[now<<1|1].f=tree[now].f;
			s[now<<1][tree[now].f]=1;
			s[now<<1|1][tree[now].f]=1;
		}
		s[now].reset();
		s[now][tree[now].f]=1;
		tree[now].f=0;
	}
	return;
}

inline void change(int now,int l,int r,int v)
{
	pushdown(now);
	if(l==tree[now].l&&r==tree[now].r)
	{
		tree[now].f=v;
		pushdown(now);
		return;
	}
	if(r<=tree[now<<1].r)
	{
		change(now<<1,l,r,v);
		pushdown(now<<1|1);
	}
	else if(l>=tree[now<<1|1].l)
	{
		change(now<<1|1,l,r,v);
		pushdown(now<<1);
	}
	else
	{
		change(now<<1,l,tree[now<<1].r,v);
		change(now<<1|1,tree[now<<1|1].l,r,v);
	}
	pushup(now);
}

inline void query(int now,int l,int r)
{
	pushdown(now);
	if(tree[now].l==l&&tree[now].r==r)
	{
		g|=s[now];
		return;
	}
	int mid=(tree[now].l+tree[now].r)>>1;
	if(r<=mid) query(now<<1,l,r);
	else if(l>mid) query(now<<1|1,l,r);
	else
	{
		query(now<<1,l,mid);
		query(now<<1|1,mid+1,r);
	}
}

int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++) col[i]=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs1(1,0);
	//cout<<w[4]<<" "<<w[4]+siz[4]-1<<endl;
	build(1,1,n);
	while(m--)
	{
		int op=read();
		if(op==1)
		{
			int v=read(),c=read();
			//cout<<v<<" "<<w[v]<<" "<<w[v]+siz[v]-1<<" "<<c<<endl;
			change(1,w[v],w[v]+siz[v]-1,c);
			//cout<<s[1]<<endl; //cout<<s[1][2]<<endl;
		}
		else
		{
			int v=read(); g.reset(); query(1,w[v],w[v]+siz[v]-1);
			printf("%d\n",g.count());
		}
	}
	return 0;
}