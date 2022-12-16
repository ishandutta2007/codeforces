#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,i,j,k,sa[N],rnk[N],h[N],tree[N*4];
int ch[N*2][26],fa[N*2],len[N*2],tot,last,pos[N*2],vis[N*2];
int head[N*2],Next[N*2],adj[N*2];
long long ans,siz[N*2];
char c[N];
struct asd{
	int x,y;
	bool operator <(const asd &a) const
	{
		return a.y>y;
	}
};
set<asd> d[N*2];
struct str{
	int x,y;
};
void Build(int i,int l,int r)
{
	if(l==r)
	{
		tree[i]=h[l];
		return;
	}
	int mid=l+r>>1;
	Build(i<<1,l,mid);
	Build(i<<1|1,mid+1,r);
	tree[i]=min(tree[i<<1],tree[i<<1|1]);
}
int Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return tree[i];
	int mid=l+r>>1,s=1<<30;
	if(mid>=ll)
		s=min(s,Query(i<<1,l,mid,ll,rr));
	if(mid<rr)
		s=min(s,Query(i<<1|1,mid+1,r,ll,rr));
	return s;
}
void Insert(int c)
{
	int p=last,nt=++tot;
	len[tot]=len[last]+1;last=nt;
	for(;p&&!ch[p][c];p=fa[p])
		ch[p][c]=nt;
	if(!p)
		fa[nt]=1;
	else
	{
		int q=ch[p][c];
		if(len[q]==len[p]+1)
			fa[nt]=q;
		else
		{
			int nq=++tot;
			memcpy(ch[nq],ch[q],sizeof(ch[nq]));
			fa[nq]=fa[q];
			fa[q]=fa[nt]=nq;
			len[nq]=len[p]+1;
			for(;p&&ch[p][c]==q;p=fa[p])
				ch[p][c]=nq;
		}
	}
}
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i)
{
	int j;
	if(pos[i]&&pos[i]<n-1)
	{
		vis[i]=1;
		siz[i]+=n-pos[i]-1;
		d[i].insert((asd){pos[i]+2,rnk[pos[i]+2]});
	}
	else
		if(pos[i]==n-1)
			vis[i]=1;
	if(i==1)
	{
		siz[i]+=n-1;
		d[i].insert((asd){2,rnk[2]});
	}
	for(j=head[i];j;j=Next[j])
	{
		dfs(adj[j]);
		vis[i]|=vis[adj[j]];
		if(d[i].size()<d[adj[j]].size())
		{
			swap(d[i],d[adj[j]]);
			siz[i]=siz[adj[j]];
		}
		for(auto it:d[adj[j]])
		{
			auto tmp=d[i].lower_bound(it);
			auto t2=tmp;
			if(tmp!=d[i].end()&&tmp!=d[i].begin())
			{
				--t2;
				siz[i]+=Query(1,1,n-1,t2->y,tmp->y-1);
			}
			if(tmp!=d[i].end())
				siz[i]-=Query(1,1,n-1,it.y,tmp->y-1);
			if(tmp!=d[i].begin())
			{
				--tmp;
				siz[i]-=Query(1,1,n-1,tmp->y,it.y-1);
			}
			d[i].insert(it);
			siz[i]+=n-it.x+1;
		}
	}
	ans+=len[i]-len[fa[i]];
	if(vis[i])
		ans+=(len[i]-len[fa[i]])*(siz[i]+1);
}
struct node{
	int a,b,x;
}p[1000005];
bool cmp(node a,node b)
{
	if(a.a==b.a)
		return a.b<b.b;
	return a.a<b.a;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%s",c+1);
	n=strlen(c+1);
	if(n==1)
	{
		cout<<3;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		p[i].a=c[i]-'a'+1;
		p[i].x=i;
	}
	sort(p+1,p+1+n,cmp);
	for(i=1;i<=n;i++)
		if(p[i].a==p[i-1].a)
			sa[p[i].x]=sa[p[i-1].x];
		else
			sa[p[i].x]=i;
	for(k=1;k<n;k*=2)
	{
		for(i=1;i<=n-k;i++)
			p[i]=(node){sa[i],sa[i+k],i};
		for(i=n-k+1;i<=n;i++)
			p[i]=(node){sa[i],0,i};
		sort(p+1,p+1+n,cmp);
		for(i=1;i<=n;i++)
			if(p[i].a==p[i-1].a&&p[i].b==p[i-1].b)
				sa[p[i].x]=sa[p[i-1].x];
			else
				sa[p[i].x]=i;
	}
	for(i=1;i<=n;++i)
		rnk[sa[i]]=i;
	for(i=1;i<=n;++i)
		swap(sa[i],rnk[i]);
	last=0;
	for(i=1;i<=n;++i)
	{
		if(rnk[i]==1)
			continue;
		for(j=max(last-1,0);c[i+j]==c[sa[rnk[i]-1]+j];++j);
		h[rnk[i]]=j;
		last=j;
	}
	for(i=1;i<n;++i)
		h[i]=h[i+1];
	Build(1,1,n-1);
	last=tot=1;
	for(i=1;i<=n;++i)
	{
		pos[tot+1]=i;
		Insert(c[i]-'a');
	}
	k=0;
	for(i=2;i<=tot;++i)
		Push(fa[i],i);
	dfs(1);
	cout<<ans+siz[1]+2;
}