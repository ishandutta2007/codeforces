#include<bits/stdc++.h>
using namespace std;
int n,t,m,a[100005],f[3005][3005],x,i,u,v;
long long g[3005][3005];
int head[3005],Next[6005],adj[6005],k,siz[100005];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
struct str{
	int s,x;
}p[5005];
bool cmp(str a,str b)
{
	return a.s<b.s;
}
void dfs(int i,int fa)
{
	int j,k,l,s=0,u=0;
	siz[i]=1;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
		{
			dfs(adj[j],i);
			siz[i]+=siz[adj[j]];
		}
	for(j=0;j<=siz[i];++j)
	{
		f[i][j]=-100000000;
		g[i][j]=-10000000000000ll;
	}
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
			p[++u]=(str){siz[adj[j]],adj[j]};
	sort(p+1,p+1+u,cmp);
	g[i][0]=a[i];
	f[i][0]=0;
	for(j=1;j<=u;++j)
	{
		s+=p[j].s;
		for(k=min(s,m);k>=0;--k)
		{
			int fs=-100000000;
			long long fg=-1000000000000ll;
			for(l=min(p[j].s,k);k-l<=s-p[j].s&&l>=0;--l)
			{
				if(fs==f[i][k-l]+f[p[j].x][l])
					fg=max(fg,g[i][k-l]+g[p[j].x][l]);
				if(fs<f[i][k-l]+f[p[j].x][l])
				{
					fs=f[i][k-l]+f[p[j].x][l];
					fg=g[i][k-l]+g[p[j].x][l];
				}
				if(l>0)
				{
					if(fs==f[i][k-l]+f[p[j].x][l-1]+(g[p[j].x][l-1]>0))
						fg=max(fg,g[i][k-l]);
					if(fs<f[i][k-l]+f[p[j].x][l-1]+(g[p[j].x][l-1]>0))
					{
						fs=f[i][k-l]+f[p[j].x][l-1]+(g[p[j].x][l-1]>0);
						fg=g[i][k-l];
					}
				}
			}
			f[i][k]=fs;
			g[i][k]=fg;
				//cout<<i<<' '<<k<<' '<<f[i][k]<<' '<<g[i][k]<<endl;
		}
	}
	//cout<<i<<' '<<g[i][2]<<endl;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&x);
			a[i]=x-a[i];
		}
		memset(head,0,sizeof(head));
		k=0;
		for(i=1;i<n;++i)
		{
			scanf("%d %d",&u,&v);
			Push(u,v);
			Push(v,u);
		}
		dfs(1,0);
		cout<<f[1][m-1]+(g[1][m-1]>0)<<endl;
	}
}