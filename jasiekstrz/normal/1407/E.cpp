#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
vector<pair<int,bool>> e[500010];
bool bad[500010][2];
bool vis[500010][2];
int d[500010][2];
bool ans[500010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,i;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		int a,b,t;
		cin>>a>>b>>t;
		e[b].push_back({a,t});
	}
	queue<pair<int,bool>> q;
	q.push({n,0});
	q.push({n,1});
	vis[n][0]=vis[n][1]=true;
	while(!q.empty())
	{
		int x=q.front().fi;
		bool t=q.front().se;
		q.pop();
		if((!bad[x][0])&&(!bad[x][1]))
		{
			bad[x][t]=true;
			continue;
		}
		for(auto v:e[x])
		{
			if(!vis[v.fi][v.se])
			{
				vis[v.fi][v.se]=true;
				d[v.fi][v.se]=d[x][t]+1;
				q.push(v);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(bad[i][0])
			ans[i]=1;
		else
			ans[i]=0;
	}
	if(!vis[1][ans[1]])
		cout<<"-1\n";
	else
		cout<<d[1][ans[1]]<<"\n";
	for(i=1;i<=n;i++)
		cout<<ans[i];
	cout<<"\n";
	return 0;
}