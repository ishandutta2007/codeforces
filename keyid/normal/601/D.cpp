#include <bits/stdc++.h>
using namespace std;

const int MAXN=300005,SIGMA=26;

struct edge
{
	int to,nxt;
}e[MAXN*2];

int ec,first[MAXN],c[MAXN],sz,ch[MAXN][SIGMA],size[MAXN];
char s[MAXN];

inline void addedge(int u,int v)
{
	e[ec]=(edge){v,first[u]};
	first[u]=ec++;
}

void merge(int &r1,int r2)
{
	if (r2==0) return;
	if (r1==0)
	{
		r1=r2;
		return;
	}
	size[r1]=1;
	for (int i=0;i<SIGMA;i++)
	{
		merge(ch[r1][i],ch[r2][i]);
		size[r1]+=size[ch[r1][i]];
	}
}

void dfs(int u,int fa)
{
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa)
		{
			dfs(v,u);
			merge(ch[u][s[v]-'a'],v);
		}
	}
	size[u]=1;
	for (int i=0;i<SIGMA;i++)
		size[u]+=size[ch[u][i]];
	c[u]+=size[u];
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	scanf("%s",s+1);
	fill(first+1,first+n+1,-1);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,0);
	int _max=0,cnt=0;
	for (int i=1;i<=n;i++)
		if (c[i]>_max)
		{
			_max=c[i];
			cnt=1;
		}
		else if (c[i]==_max)
			cnt++;
	printf("%d\n%d",_max,cnt);
	return 0;
}