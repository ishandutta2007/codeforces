#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
vector<int> G[100100];
int a[100100];
int sum[100100];
int x;
int dfs(int u,int fa)
{
	sum[u]=a[u];
	int sm=0;
	for(int i=0;i<sz(G[u]);i++)
	{
		int v=G[u][i];
		if(v==fa)
			continue;
		int tmp=dfs(v,u);
		sum[u]^=sum[v];
		if(tmp==2)
			return 2;
		if(tmp==1&&sm==1)
			return 2;
		sm+=tmp;
	}
	if(sm==1&&!sum[u])
		return 2;
	if(!sm&&sum[u]==x)
		return 1;
	return sm;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		x=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			x^=a[i];
		}
		for(int i=1;i<=n;i++)
			G[i].resize(0);
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].pb(v);
			G[v].pb(u);
		}
		if(!x)
			puts("YES");
		else
		{
			if(k==2)
				puts("NO");
			else
			{
				if(dfs(1,0)==2)
					puts("YES");
				else	puts("NO");
			}
		}
	}
	return 0;
}