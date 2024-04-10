#include <bits/stdc++.h>
using namespace std;

const int MAXN=300005;

#define pb push_back

int maxbit,fa[20][MAXN],deep[MAXN],sum[MAXN],d[MAXN];
vector <int> G[MAXN],kp;
bool ok[MAXN];

void dfs(int u)
{
	for (int v:G[u])
	{
		deep[v]=deep[u]+1;
		dfs(v);
	}
}

int LCA(int u,int v)
{
	if (deep[u]<deep[v])
		swap(u,v);
	for (int i=maxbit;i>=0;i--)
		if (deep[fa[i][u]]>=deep[v])
			u=fa[i][u];
	if (u==v) return u;
	for (int i=maxbit;i>=0;i--)
		if (fa[i][u]!=fa[i][v])
		{
			u=fa[i][u];
			v=fa[i][v];
		}
	return fa[0][u];
}

int dis(int u,int v)
{
	return deep[u]+deep[v]-deep[LCA(u,v)]*2;
}

int main()
{
	int n;
	scanf("%d",&n);
	n++;
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&fa[0][i]);
		G[fa[0][i]].pb(i);
	}
	deep[1]=1;
	dfs(1);
	while ((1<<maxbit)<n) maxbit++;
	maxbit--;
	for (int j=1;j<=maxbit;j++)
		for (int i=1;i<=n;i++)
			fa[j][i]=fa[j-1][fa[j-1][i]];
	int now=0,p1=1,p2=1;
	ok[1]=true;
	for (int i=2;i<=n;i++)
	{
		int d1=dis(i,p1),d2=dis(i,p2);
		if (d1>now)
			p2=i;
		else if (d2>now)
			p1=i;
		d1=max(d1,d2);
		if (d1>now)
		{
			d[i]=now=d1;
			kp.pb(i);
		}
		if (d1==now)
			ok[i]=true;
	}
	for (int i=1;i<=n;i++)
		if (ok[i])
		{
			sum[i]++;
			int l=upper_bound(kp.begin(),kp.end(),i)-kp.begin(),r=kp.size()-1;
			while (l<=r)
			{
				int m=l+r>>1;
				if (dis(kp[m],i)==d[kp[m]])
					l=m+1;
				else
					r=m-1;
			}
			if (l<kp.size())
				sum[kp[l]]--;
		}
	for (int i=2;i<=n;i++)
		sum[i]+=sum[i-1];
	for (int i=2;i<=n;i++)
		printf("%d\n",sum[i]);
	return 0;
}