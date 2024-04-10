#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=250005;

vector <int> G[MAXN];
int fa[MAXN],dep[MAXN];
bool vis[MAXN],son[MAXN];

void dfs(int u)
{
	for (int v:G[u])
		if (!vis[v])
		{
			vis[v]=true;
			son[u]=true;
			fa[v]=u;
			dep[v]=dep[u]+1;
			dfs(v);
		}
}

void output(int u,int v)
{
	for (;;)
	{
		printf("%d ",u);
		if (u==v)
			break;
		u=fa[u];
	}
}

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	vis[1]=true;
	dfs(1);
	for (int i=1;i<=n;i++)
		if (dep[i]>=(n-1)/k)
		{
			printf("PATH\n%d\n",dep[i]+1);
			output(i,1);
			return 0;
		}
	puts("CYCLES");
	for (int i=1,cnt=0;cnt<k;i++)
		if (!son[i])
		{
			int v[2],c=0;
			for (int j:G[i])
				if (j!=fa[i])
				{
					v[c]=j;
					if (++c==2)
						break;
				}
			if ((dep[i]-dep[v[0]]+1)%3)
			{
				printf("%d\n",dep[i]-dep[v[0]]+1);
				output(i,v[0]);
			}
			else if ((dep[i]-dep[v[1]]+1)%3)
			{
				printf("%d\n",dep[i]-dep[v[1]]+1);
				output(i,v[1]);
			}
			else
			{
				if (dep[v[0]]<dep[v[1]])
					swap(v[0],v[1]);
				printf("%d\n%d ",dep[v[0]]-dep[v[1]]+2,i);
				output(v[0],v[1]);
			}
			puts("");
			cnt++;
		}
	return 0;
}