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

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	int r=1,leaf=0;
	for (int i=1;i<=n;i++)
	{
		if (G[i].size()==1)
			leaf++;
		if (G[i].size()>G[r].size())
			r=i;
	}
	if (G[r].size()==leaf-(G[r].size()==1))
	{
		puts("Yes");
		printf("%u\n",G[r].size());
		for (int i=1;i<=n;i++)
			if (i!=r&&G[i].size()==1)
				printf("%d %d\n",r,i);
	}
	else
		puts("No");
	return 0;
}