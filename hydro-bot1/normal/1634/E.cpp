#include<bits/stdc++.h>
using namespace std;
int sz[111111];
vector<int> vec[111111],id[111111];
map<int,int> mp;
vector<int> G[233333];
void addedge(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
int col[233333];
void dfs(int u,int c)
{
	col[u]=c;
	for(auto v:G[u])
	{
		if(col[v]==-1)
			dfs(v,1-c);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int m;
	cin>>m;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		cin>>sz[i];
		vec[i].resize(sz[i]);
		for(int j=0;j<sz[i];j++)
		{
			cin>>vec[i][j];
			id[i].push_back(++cnt);
			if(cnt%2==0)addedge(cnt-1,cnt);
			if(mp[vec[i][j]])
			{
				addedge(mp[vec[i][j]],cnt);
				mp.erase(vec[i][j]);
			}
			else
			{
				mp[vec[i][j]]=cnt;
			}
		}
	}
	memset(col,-1,sizeof(col));
	for(int i=1;i<=cnt;i++)
	{
		if(col[i]==-1)
			dfs(i,0);
	}
	if(!mp.empty())
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<sz[i];j++)
		{
			cout<<"LR"[col[id[i][j]]];
		}
		cout<<"\n";
	}
	return 0;
}