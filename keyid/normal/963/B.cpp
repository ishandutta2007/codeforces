#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=200005;

vector <int> G[MAXN];
bool f[MAXN][2];

void dfs(int u,int fa)
{
	bool flag=false;
	int cnt=0;
	for (int v:G[u])
		if (v!=fa)
		{
			dfs(v,u);
			if (!f[v][0]&&!f[v][1])
				return;
			if (f[v][0]&&f[v][1])
				flag=true;
			if (f[v][1])
				cnt++;
		}
	if (flag)

		f[u][0]=f[u][1]=true;
	else
		f[u][(G[u].size()-(u==1?0:1)-cnt)&1]=true;
}

void output(int u,int k,int fa)
{
	int cnt=G[u].size();
	if (u!=1)
		cnt-=(k^1);
	for (int v:G[u])
		if (v!=fa&&!f[v][0]&&f[v][1])
		{
			output(v,1,u);
			cnt--;
		}
	cnt&=1;
	for (int v:G[u])
		if (v!=fa&&f[v][0]&&f[v][1])
		{
			output(v,cnt,u);
			cnt=0;
		}
	printf("%d\n",u);
	for (int v:G[u])
		if (v!=fa&&f[v][0]&&!f[v][1])
			output(v,0,u);
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int p;
		scanf("%d",&p);
		if (p==0)
			continue;
		G[i].pb(p);
		G[p].pb(i);
	}
	dfs(1,0);
	if (f[1][0])
	{
		puts("YES");
		output(1,0,0);
	}
	else
		puts("NO");
	return 0;
}