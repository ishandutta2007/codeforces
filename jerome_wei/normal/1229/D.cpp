#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
const long long M=1000000007;
#define ri register int 
#define rl register long long
int n,i,k,j,m,p[200005][6],q[200005],r,f[155],sta[10005],top,t,b[6],e,num[200005],v[155],a[155],el,er,op;
int head[155],Next[100005],adj[100005];
long long ans;
int sum(int x[])
{
	int i,j,s=0,ans=0,p=1;
	for(i=m;i>=1;i--)
	{
		s=0;
		for(j=i+1;j<=m;j++)
			if(x[j]<x[i])
				s++;
		ans+=p*s;
		p*=(m-i+1);
	}
	return ans;
}
void Push(int u,int v)
{
	Next[++op]=head[u];
	head[u]=op;
	adj[op]=v;
}
int p1[6],p2[6];
struct str{
	int u,v;
};
vector<str> g[155];
void dfs2(int i)
{
	if(i>m)
	{
		int a,b,op[6];
		for(a=1;a<=m;a++)
		{
			for(b=1;b<=m;b++)
				if(p1[a]==p2[b])
					break;
			op[a]=b;
		}
		g[sum(op)].push_back((str){sum(p1),sum(p2)});
		return;
	}
	int j;
	for(j=1;j<=m;j++)
		if(v[j]==0)
		{
			v[j]=1;
			p2[i]=j;
			dfs2(i+1);
			v[j]=0;
		}
}
void dfs(int i)
{
	if(i>m)
	{
		dfs2(1);
		return;
	}
	int j;
	for(j=1;j<=m;j++)
		if(f[j]==0)
		{
			f[j]=1;
			p1[i]=j;
			dfs(i+1);
			f[j]=0;
		}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			scanf("%d",&p[i][j]);
		num[i]=sum(p[i]);
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		q[++r]=i;
		memset(f,0,sizeof(f));
		f[0]=1;
		a[1]=0;
		k=1;
		top=0;
		memset(head,0,sizeof(head));
		op=0;
		for(j=r;j>=1;j--)
		{
			int last=k;
			for(t=0;t<g[num[q[j]]].size();t++)
				if(f[g[num[q[j]]][t].u]!=1||f[g[num[q[j]]][t].v]!=1)
					Push(g[num[q[j]]][t].u,g[num[q[j]]][t].v);
			for(t=1;t<=k;t++)
				for(e=head[a[t]];e!=0;e=Next[e])
					if(f[adj[e]]==0)
					{
						f[adj[e]]=1;
						a[++k]=adj[e];
					}
			if(last!=k)
				sta[++top]=q[j];
			ans+=1ll*k*(q[j]-q[j-1]);
		}
		r=top;
		for(j=1;j<=top;j++)
			q[j]=sta[top-j+1];
	}
	cout<<ans;
}