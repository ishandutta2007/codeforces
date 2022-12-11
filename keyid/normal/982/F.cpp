#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=100005;

vector <int> G[MAXN];
stack <int> sta;
int vis[MAXN],cc,cir[MAXN],far[MAXN],sum[MAXN*2];

bool find_cir(int u)
{
	vis[u]=-1;
	sta.push(u);
	for (int v:G[u])
		if (!vis[v])
		{
			if (find_cir(v))
				return true;
		}
		else if (vis[v]==-1)
		{
			for (;;)
			{
				int x=sta.top();
				sta.pop();
				cir[cc++]=x;
				if (x==v)
					break;
			}
			reverse(cir,cir+cc);
			return true;
		}
	sta.pop();
	vis[u]=1;
	return false;
}

int now;

bool dfs(int u)
{
	vis[u]=-1;
	int &ret=far[u];
	ret=-1;
	for (int v:G[u])
	{
		if (vis[v]==-1)
			return false;
		if (!vis[v]&&!dfs(v))
			return false;
		if (far[v]>=0&&(ret==-1||(far[v]<=now?far[v]+cc:far[v])>(ret<=now?ret+cc:ret)))
			ret=far[v];
	}
	vis[u]=1;
	return true;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]&&find_cir(i))
			break;
	for (int i=1;i<=n;i++)
		vis[i]=0;
	for (int i=0;i<cc;i++)
	{
		vis[cir[i]]=1;
		far[cir[i]]=i;
	}
	for (int i=0;i<cc;i++)
	{
		now=i;
		int ret=(i+1)%cc;
		for (int v:G[cir[i]])
		{
			if (!vis[v]&&!dfs(v))
			{
				printf("-1");
				return 0;
			}
			if (far[v]>=0&&(far[v]<=now?far[v]+cc:far[v])>(ret<=now?ret+cc:ret))
				ret=far[v];
		}
		if (ret<=i)
			ret+=cc;
		sum[i+1]++;
		sum[ret]--;
	}
	int ans=0;
	for (int i=1;i<2*cc;i++)
		sum[i]+=sum[i-1];
	for (int i=0;i<cc;i++)
		if (sum[i]==0&&sum[i+cc]==0)
		{
			ans=cir[i];
			break;
		}
	if (ans)
	{
		for (int i=1;i<=n;i++)
			if (i!=ans)
				for (auto k=G[i].begin();k!=G[i].end();)
					if (*k==ans)
						k=G[i].erase(k);
					else
						++k;
		for (int i=1;i<=n;i++)
			vis[i]=0;
		cc=0;
		stack<int>().swap(sta);
		for (int i=1;i<=n;i++)
			if (i!=ans&&!vis[i]&&find_cir(i))
			{
				printf("-1");
				return 0;
			}
		printf("%d",ans);
	}
	else
		printf("-1");
	return 0;
}