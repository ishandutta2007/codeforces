#include<bits/stdc++.h>
using namespace std;
const int Maxn=100005;
bool vis[Maxn],color[Maxn];
vector<int> G[Maxn];
int X[Maxn],Y[Maxn];
int N,M;
void dfs_color(int x,bool col)
{
	color[x]=col;
	col^=1;
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
		if(!vis[G[x][i]])
			dfs_color(G[x][i],col);
	return ;
}
bool check()
{
	for(int i=0;i<M;i++)
		if(color[X[i]]==color[Y[i]])
			return false;
	return true;
}
int main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		cin>>X[i]>>Y[i];
		G[X[i]].push_back(Y[i]);
		G[Y[i]].push_back(X[i]);
	}
	for(int i=1;i<=N;i++)
		if(!vis[i])
			dfs_color(i,0);
	if(check())
	{
		int cnt[2]={0,0};
		for(int i=1;i<=N;i++)
			cnt[color[i]]++;
		cout<<cnt[0]<<endl;
		for(int i=1;i<=N;i++)
			if(color[i]==0)
				cout<<i<<" ";
		cout<<endl;
		cout<<cnt[1]<<endl;
		for(int i=1;i<=N;i++)
			if(color[i]==1)
				cout<<i<<" ";
		cout<<endl;
	}
	else	puts("-1");
}