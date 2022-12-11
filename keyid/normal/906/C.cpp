#include <bits/stdc++.h>
using namespace std;

const int MAXN=25;

struct state
{
	int s,p;
}pre[1<<22];

int e[MAXN],dp[1<<22];

void output(int n)
{
	if (dp[n]==0)
		return;
	output(pre[n].s);
	printf("%d ",pre[n].p+1);
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		e[i]|=1<<i;
	while (m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;
		v--;
		e[u]|=1<<v;
		e[v]|=1<<u;
	}
	for (int i=1;i<(1<<n);i++)
	{
		bool flag=true;
		for (int j,t=i;t;t-=1<<j)
		{
			j=__builtin_ctz(t);
			if ((e[j]&i)!=i)
			{
				flag=false;
				break;
			}
		}
		if (!flag)
			dp[i]=n;
	}
	for (int i=1;i<(1<<n);i++)
	{
		for (int j,t=i;t;t-=1<<j)
		{
			j=__builtin_ctz(t);
			if (dp[i|e[j]]>dp[i]+1)
			{
				pre[i|e[j]]={i,j};
				dp[i|e[j]]=dp[i]+1;
			}
		}
	}
	printf("%d\n",dp[(1<<n)-1]);
	output((1<<n)-1);
	return 0;
}