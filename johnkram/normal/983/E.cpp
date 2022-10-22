#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200010,K=15,M=10000010;
int n,m,Q,i,j,x,y,z,g[N],v[N<<1],nxt[N<<1],ed,G[N],V[N<<1],NXT[N<<1],ED,p[N],fa[N][K],f[N],d[N],size[N],son[N],st[N],en[N],dfn,q[N],top[N],T[N],l[M],r[M],val[M],tot;
struct node
{
	int x,y,z;
}e[N];
inline bool cmp(const node&a,const node&b)
{
	return d[a.z]<d[b.z];
}
inline void add(int x,int y)
{
	v[++ed]=y;
	nxt[ed]=g[x];
	g[x]=ed;
}
inline void ADD(int x,int y)
{
	V[++ED]=y;
	NXT[ED]=G[x];
	G[x]=ED;
}
void dfs(int x)
{
	size[x]=1;
	d[x]=d[f[x]]+1;
	for(int i=g[x];i;i=nxt[i])if(v[i]!=f[x])
	{
		f[v[i]]=x;
		dfs(v[i]);
		size[x]+=size[v[i]];
		if(size[v[i]]>size[son[x]])son[x]=v[i];
	}
}
void dfs2(int x,int y)
{
	q[st[x]=++dfn]=x;
	top[x]=y;
	if(son[x])dfs2(son[x],y);
	for(int i=g[x];i;i=nxt[i])if(v[i]!=son[x]&&v[i]!=f[x])dfs2(v[i],v[i]);
	en[x]=dfn;
}
int lca(int x,int y)
{
	for(;top[x]!=top[y];x=f[top[x]])if(d[top[x]]<d[top[y]])swap(x,y);
	return d[x]<d[y]?x:y;
}
int up(int x,int k)
{
	for(;;)
	{
		int t=st[x]-st[top[x]];
		if(k<=t)return q[st[x]-k];
		k-=t+1;
		x=f[top[x]];
	}
}
int go(int x,int y)
{
	if(x==y)return 0;
	if(d[fa[x][K-1]]>d[y])return -1;
	int t=1;
	for(int i=K-1;~i;i--)if(d[fa[x][i]]>d[y])
	{
		x=fa[x][i];
		t+=1<<i;
	}
	return t;
}
int ins(int x,int a,int b,int c)
{
	int y=++tot;
	val[y]=val[x]+1;
	if(a==b)return y;
	int mid=a+b>>1;
	if(c<=mid)
	{
		l[y]=ins(l[x],a,mid,c);
		r[y]=r[x];
	}
	else
	{
		l[y]=l[x];
		r[y]=ins(r[x],mid+1,b,c);
	}
	return y;
}
int ask(int x,int a,int b,int c,int d)
{
	if(c<=a&&b<=d)return val[x];
	int mid=a+b>>1,t=0;
	if(c<=mid)t=ask(l[x],a,mid,c,d);
	if(d>mid)t+=ask(r[x],mid+1,b,c,d);
	return t;
}
bool check(int x,int y)
{
	return ask(T[en[x]],1,n,st[y],en[y])>ask(T[st[x]-1],1,n,st[y],en[y]);
}
int query(int x,int y)
{
	if(st[x]<=st[y]&&en[y]<=en[x])return go(y,x);
	if(st[y]<=st[x]&&en[x]<=en[y])return go(x,y);
	int z=lca(x,y),t=0;
	if(d[fa[x][K-1]]>d[z])return -1;
	for(int i=K-1;~i;i--)if(d[fa[x][i]]>d[z])
	{
		x=fa[x][i];
		t|=1<<i;
	}
	int l=0,r=d[y]-d[z]-1,mid,o=d[y]-d[z];
	while(l<=r)if(check(x,up(y,mid=l+r>>1)))r=(o=mid)-1;
	else l=mid+1;
	o=go(y,up(y,o));
	if(o<0)return -1;
	return t+o+1;
}
void dfs3(int x)
{
	int i;
	for(i=1;i<K;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(i=g[x];i;i=nxt[i])if(v[i]!=f[x])dfs3(v[i]);
}
int F(int x)
{
	return p[x]==x?x:p[x]=F(p[x]);
}
void col(int x,int y)
{
	for(x=F(x);d[x]>=d[y];x=F(x))
	{
		fa[x][0]=y;
		p[x]=f[x];
	}
}
int main()
{
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&j);
		add(i,j);
		add(j,i);
	}
	dfs(1);
	dfs2(1,1);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&e[i].x,&e[i].y);
		e[i].z=lca(e[i].x,e[i].y);
		x=e[i].x;
		y=e[i].y;
		z=e[i].z;
		if(x==y)continue;
		ADD(st[x],st[y]);
		ADD(st[y],st[x]);
	}
	sort(e+1,e+m+1,cmp);
	for(i=1;i<=n;i++)p[i]=fa[i][0]=i;
	for(i=1;i<=m;i++)
	{
		col(e[i].x,e[i].z);
		col(e[i].y,e[i].z);
	}
	for(dfs3(i=1);i<=n;i++)for(T[i]=T[i-1],j=G[i];j;j=NXT[j])T[i]=ins(T[i],1,n,V[j]);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",query(x,y));
	}
	return 0;
}