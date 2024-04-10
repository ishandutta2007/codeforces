#include<bits/stdc++.h>
using namespace std;

struct node
{
	int nxt,to,val,ans;
}Edge[2000005];
int n,m,head[300005],cnt=1,deg[300005],NxtEdge[2000005],NowEdge[300005][3];
bool vis[300005];

void addEdge(int u,int v,int w)
{
	Edge[++cnt]=(node){head[u],v,w,0};
	NxtEdge[cnt]=NowEdge[u][w];
	NowEdge[u][w]=head[u]=cnt;
}

void dfs(int u,int Val)
{
	vis[u]=true;
	while(NowEdge[u][Val] && Edge[NowEdge[u][Val]].ans) 
	{
		NowEdge[u][Val]=NxtEdge[NowEdge[u][Val]];
	}
	if(!NowEdge[u][Val])
	{
		Val=3-Val;
		while(NowEdge[u][Val] && Edge[NowEdge[u][Val]].ans) NowEdge[u][Val]=NxtEdge[NowEdge[u][Val]];
	}
	if(!NowEdge[u][Val]) return;
	Edge[NowEdge[u][Val]].ans=1;
	Edge[NowEdge[u][Val]^1].ans=2; 
	int tmp=NowEdge[u][Val];
	NowEdge[u][Val]=NxtEdge[NowEdge[u][Val]];
	dfs(Edge[tmp].to,Val);
	for(int i=head[u];i;i=Edge[i].nxt)
	{
		head[u]=Edge[i].nxt;
		if(!Edge[i].ans)
		{
			Edge[i].ans=1;
			Edge[i^1].ans=2;
			dfs(Edge[i].to,Edge[i].val);
		}
	}
}

int ansp[300005],cntp;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addEdge(u,v,w);
		addEdge(v,u,w);
		deg[u]++;
		deg[v]++;
	}
	for(int i=1;i<=n;i++) 
	{
		if(deg[i]%2==0) continue;
		addEdge(n+1,i,1);
		addEdge(i,n+1,1);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) dfs(i,1);
	}
	for(int i=2;i<=2*m+1;i++)
	{
		if(Edge[i].ans==1)
		{
			ansp[Edge[i].to]+=Edge[i].val;
		}
		else
		{
			ansp[Edge[i].to]-=Edge[i].val;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ansp[i]==1 || ansp[i]==-1) cntp++;
	}
	printf("%d\n",cntp);
	for(int i=1;i<=m;i++)
	{
		printf("%d",Edge[2*i].ans);
	}
	printf("\n");
	return 0;
}