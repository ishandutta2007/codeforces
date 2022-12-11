#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=100005;

vector <int> G[MAXN];
int deep[MAXN],cnt[MAXN];

void dfs(int u)
{
	for (int v:G[u])
	{
		deep[v]=deep[u]+1;
		dfs(v);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		int p;
		scanf("%d",&p);
		G[p].pb(i);
	}
	dfs(1);
	for (int i=1;i<=n;i++)
		cnt[deep[i]]^=1;
	int ans=0;
	for (int i=0;i<n;i++)
		ans+=cnt[i];
	printf("%d",ans);
	return 0;
}