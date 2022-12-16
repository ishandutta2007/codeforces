#include<bits/stdc++.h>
using namespace std;
const int N=300005;
const long long inf=1000000000000000000ll;
int n,m,i,j,s=0,u,v,Q,k;
long long d[N],w1,w2;
int head[N],Next[N*2],adj[N*2],vis[N],fa[N],son[N],dep[N];
int top[N],num[N],siz[N];
long long leng1[N*2],leng2[N*2];
struct str{
	long long d;
	int x;
};
bool operator <(str a,str b)
{
	return a.d>b.d;
}
priority_queue<str> q;
struct mt{
	long long a[2][2];
}t[N],tree[N*4];
mt mult(mt a,mt b)
{
	mt t;
	t.a[0][0]=min(a.a[0][0]+b.a[0][0],a.a[0][1]+b.a[1][0]);
	t.a[0][1]=min(a.a[0][0]+b.a[0][1],a.a[0][1]+b.a[1][1]);
	t.a[1][0]=min(a.a[1][0]+b.a[0][0],a.a[1][1]+b.a[1][0]);
	t.a[1][1]=min(a.a[1][0]+b.a[0][1],a.a[1][1]+b.a[1][1]);
	return t;
}
void Push(int u,int v,long long w1,long long w2)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
	leng1[k]=w1;
	leng2[k]=w2;
}
mt Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return tree[i];
	int mid=l+r>>1;
	if(mid>=ll&&mid<rr)
		return mult(Query(i<<1|1,mid+1,r,ll,rr),Query(i<<1,l,mid,ll,rr));
	else
		if(mid>=ll)
			return Query(i<<1,l,mid,ll,rr);
		else
			return Query(i<<1|1,mid+1,r,ll,rr);
}
void dfs(int i,int f)
{
	int j;
	fa[i]=f;
	siz[i]=1;
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=f)
		{
			dep[adj[j]]=dep[i]+1;
			dfs(adj[j],i);
			siz[i]+=siz[adj[j]];
			if(siz[adj[j]]>siz[son[i]])
				son[i]=adj[j];
		}
}
void dfs2(int i,int t)
{
	int j;
	top[i]=t;
	num[i]=++k;
	if(son[i])
		dfs2(son[i],t);
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa[i]&&adj[j]!=son[i])
			dfs2(adj[j],adj[j]);
}
void Build(int i,int l,int r)
{
	if(l==r)
	{
		tree[i]=t[l];
		return;
	}
	int mid=l+r>>1;
	Build(i<<1,l,mid);
	Build(i<<1|1,mid+1,r);
	tree[i]=mult(tree[i<<1|1],tree[i<<1]);
}
int LCA(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		u=top[u];
		u=fa[u];
	}
	return (dep[u]<dep[v]?u:v);
}
mt Ans(int u,int v)
{
	mt ans;
	ans.a[1][0]=ans.a[0][1]=inf;
	ans.a[0][0]=ans.a[1][1]=0;
	while(top[u]!=top[v])
	{
		ans=mult(ans,Query(1,1,n,num[top[u]],num[u]));
		u=top[u];
		u=fa[u];
	}
	if(u!=v)
		ans=mult(ans,Query(1,1,n,num[v]+1,num[u]));
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&d[i]);
		q.push((str){d[i],i});
	}
	for(i=1;i<n;++i)
	{
		scanf("%d %d %lld %lld",&u,&v,&w1,&w2);
		Push(u,v,w1,w2);
		Push(v,u,w1,w2);
	}
	while(!q.empty())
	{
		str x=q.top();
		q.pop();
		if(vis[x.x])
			continue;
		vis[x.x]=1;
		for(i=head[x.x];i;i=Next[i])
			if(d[adj[i]]>d[x.x]+leng1[i]+leng2[i])
			{
				d[adj[i]]=d[x.x]+leng1[i]+leng2[i];
				q.push((str){d[adj[i]],adj[i]});
			}
	}
	k=0;
	dfs(1,0);
	dfs2(1,1);
	for(i=1;i<=n;++i)
		for(j=head[i];j;j=Next[j])
			if(adj[j]!=fa[i])
			{
				t[num[adj[j]]].a[0][0]=leng1[j];
				t[num[adj[j]]].a[0][1]=leng1[j]+d[i];
				t[num[adj[j]]].a[1][0]=leng2[j]+d[i];
				t[num[adj[j]]].a[1][1]=leng2[j];
			}
	Build(1,1,n);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d %d",&u,&v);
		long long p,q,x,y;
		if(u&1)
		{
			p=0;
			q=d[(u+1)/2];
		}
		else
		{
			p=d[(u+1)/2];
			q=0;
		}
		if(v&1)
		{
			x=0;
			y=d[(v+1)/2];
		}
		else
		{
			x=d[(v+1)/2];
			y=0;
		}
		u=(u+1)/2,v=(v+1)/2;
		int lca=LCA(u,v);
		mt a=Ans(u,lca);
		mt b=Ans(v,lca);
		long long l=min(p+a.a[0][0],q+a.a[1][0]),r=min(p+a.a[0][1],q+a.a[1][1]);
		long long g=min(x+b.a[0][0],y+b.a[1][0]),f=min(x+b.a[0][1],y+b.a[1][1]);
		//cout<<p<<' '<<q<<endl;
		//cout<<a.a[0][0]<<' '<<a.a[0][1]<<endl<<a.a[1][0]<<' '<<a.a[1][1]<<endl;
		//cout<<l<<' '<<r<<' '<<g<<' '<<f<<' ';
		printf("%lld\n",min(l+g,r+f));
	}
}