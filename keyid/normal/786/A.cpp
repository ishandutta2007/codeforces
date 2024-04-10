#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=7005;

struct state
{
	int player,pos;
};

vector <int> dis[2];
int cnt[2][MAXN],ans[2][MAXN];
bool vis[2][MAXN];
queue <state> q;

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<2;i++)
	{
		int k;
		scanf("%d",&k);
		for (int j=0;j<k;j++)
		{
			int x;
			scanf("%d",&x);
			dis[i].pb(x);
		}
	}
	vis[0][0]=vis[1][0]=true;
	ans[0][0]=ans[1][0]=2;
	q.push((state){0,0});
	q.push((state){1,0});
	while (!q.empty())
	{
		state u=q.front();q.pop();
		int p=u.player^1;
		if (ans[u.player][u.pos]==1)
		{
			for (int j=0;j<dis[p].size();j++)
			{
				int x=(u.pos-dis[p][j]+n)%n;
				if (vis[p][x]) continue;
				if (++cnt[p][x]==dis[p].size())
				{
					vis[p][x]=true;
					ans[p][x]=2;
					q.push((state){p,x});
				}
			}
		}
		else
		{
			for (int j=0;j<dis[p].size();j++)
			{
				int x=(u.pos-dis[p][j]+n)%n;
				//if (p==1) printf("%d %d\n",u.pos,x);
				if (vis[p][x]) continue;
				vis[p][x]=true;
				ans[p][x]=1;
				q.push((state){p,x});
			}
		}
	}
	for (int j=0;j<2;j++)
	{
		for (int i=1;i<n;i++)
			if (ans[j][i]==1)
				printf("Win ");
			else if (ans[j][i]==2)
				printf("Lose ");
			else
				printf("Loop ");
		puts("");
	}
	return 0;
}