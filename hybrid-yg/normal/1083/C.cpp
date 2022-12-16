#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int fa[N],ch[N][2],n,rev[N],p[N];
int head[N],Next[N*2],adj[N*2],k,ff;
int mn[N*4],mnn[N*4],dfn[N*4],lat[N*4],id[N*4];
int f[N*2][20],dep[N*4],Log[N*4],q,x,y,i,j,t,tot,num[N*4];
struct str{
	int a,b;
}tree[N*4];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
bool isr(int x){return !(ch[fa[x]][0]==x||ch[fa[x]][1]==x);}
void rotate(int x)
{
    int y=fa[x];bool d=(ch[y][0]==x);
    ch[y][!d]=ch[x][d];
    if(ch[x][d]!=0)fa[ch[x][d]]=y;
    fa[x]=fa[y];if(!isr(y))ch[fa[y]][ch[fa[y]][1]==y]=x;
    ch[x][d]=y;fa[y]=x;
}
void pushdown(int x)
{
	if(rev[x])
	{
		swap(ch[x][0],ch[x][1]);
		rev[ch[x][0]]^=1;
		rev[ch[x][1]]^=1;
		rev[x]=0;
	}
}
void pd(int x)
{
	if(!isr(x))
		pd(fa[x]);
	pushdown(x);
}
void splay(int x)
{
	pd(x);
	for(int y=fa[x];!isr(x);rotate(x),y=fa[x])
		if(!isr(y))
			rotate((ch[fa[y]][0]==y)==(ch[y][0]==x)?y:x);
}
void dfs(int i,int f,int d)
{
	int j;
	fa[i]=f;
	dfn[i]=++k;
	num[i]=++tot;
	id[tot]=i,dep[tot]=d;
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=f)
		{
			dfs(adj[j],i,d+1);
			id[++tot]=i,dep[tot]=d;
		}
	lat[i]=k;
}

inline void pre()
{
	Log[0]=-1;
	for(int i=1;i<=tot;++i) Log[i]=Log[i>>1]+1;
	for(int i=1;i<=tot;++i) f[i][0]=i;
	for(int j=1;(1<<j)<=tot;++j)
	  for(int i=1;i+(1<<j)-1<=tot;++i)
	  {
	  	int x=f[i][j-1],y=f[i+(1<<j-1)][j-1];
	  	if(dep[x] < dep[y]) f[i][j]=x;
	  	else f[i][j]=y;
	  }
}
 
inline int LCA(int x,int y)
{
	if(num[x]>num[y]) swap(x,y);
	int s=num[x],t=num[y],len=Log[t-s+1];
	if(dep[f[s][len]]<dep[f[t-(1<<len)+1][len]]) return id[f[s][len]];
	else return id[f[t-(1<<len)+1][len]];
}
bool isf(int a,int b)
{
	return (dfn[a]<=dfn[b]&&lat[a]>=lat[b]);
}
bool iso(int a,int u,int v)
{
	bool x=isf(a,u),y=isf(a,v);
	if(x||y)
	{
		if(x&&y)
			return (LCA(u,v)==a);
		return true;
	}
	return false;
}
str Merge(str a,str b)
{
	if(iso(a.b,a.a,b.a)&&iso(b.b,a.a,b.a))
		return (str){a.a,b.a};
	if(iso(a.a,a.b,b.a)&&iso(b.b,a.b,b.a))
		return (str){a.b,b.a};
	if(iso(a.a,a.b,b.b)&&iso(b.a,a.b,b.b))
		return (str){a.b,b.b};
	if(iso(a.b,a.a,b.b)&&iso(b.a,a.a,b.b))
		return (str){a.a,b.b};
	if(iso(b.b,a.a,a.b)&&iso(b.a,a.a,a.b))
		return (str){a.a,a.b};
	if(iso(a.b,b.a,b.b)&&iso(a.a,b.a,b.b))
		return (str){b.a,b.b};
	return (str){0,0};
}
void pushup(int i)
{
	if(tree[i<<1].a&&tree[i<<1|1].a)
		tree[i]=Merge(tree[i<<1],tree[i<<1|1]);
	else
		tree[i].a=tree[i].b=0;
}
void modify(int i,int l,int r,int x,int y)
{
	if(l==r)
	{
		tree[i].a=tree[i].b=y;
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)
		modify(i<<1,l,mid,x,y);
	else
		modify(i<<1|1,mid+1,r,x,y);
	pushup(i);
}
int tgh;
str Query(int i,int l,int r,str x)
{
	if(l==r)
	{
		tgh=l;
		return x;
	}
	int mid=l+r>>1;
	if(tree[i<<1].a)
	{
		if(!x.a)
			return Query(i<<1|1,mid+1,r,tree[i<<1]);
		else
		{
			str u=Merge(tree[i<<1],x);
			if(u.a)
				return Query(i<<1|1,mid+1,r,u);
		}
	}
	return Query(i<<1,l,mid,x);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&p[i]);
	/*for(i=1;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}*/
	for(i=2;i<=n;++i)
	{
		scanf("%d",&ff);
		Push(ff,i);
	}
	k=0;
	dfs(1,0,0);
	pre();
	for(i=1;i<=n;++i)
		modify(1,0,n,p[i],i);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d %d",&x,&y);
			modify(1,0,n,p[x],y);
			modify(1,0,n,p[y],x);
			swap(p[x],p[y]);
		}
		else
		{
			Query(1,0,n,(str){0,0});
			printf("%d\n",tgh);
		}
	}
}