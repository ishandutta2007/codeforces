#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=2e5;
vector<int> e[N+10];
int ans=0;
int type[N+10]; // 0-bud, 1-leaf, 2-other
int kk[N+10];
void dfs(int x,int p)
{
	for(auto v:e[x])
	{
		if(v!=p)
			dfs(v,x);
	}
	for(size_t i=0;i<e[x].size();)
	{
		if(e[x][i]==p || type[e[x][i]]==0)
		{
			swap(e[x][i],e[x].back());
			e[x].pop_back();
		}
		else
			i++;
	}
	if(e[x].empty())
	{
		kk[x]=1;
		type[x]=1;
		return;
	}
	bool bud=true;
	for(auto v:e[x])
	{
		if(type[v]!=1)
		{
			bud=false;
			break;
		}
	}
	if(x!=1 && bud)
	{
		type[x]=0;
		kk[x]=e[x].size();
		ans+=kk[x]-1;
		return;
	}
	type[x]=2;
	kk[x]=0;
	for(auto v:e[x])
		kk[x]+=kk[v];
	return;
}
int solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	ans=0;
	dfs(1,0);
	ans+=kk[1];
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int qq;
	cin>>qq;
	while(qq--)
		cout<<solve()<<"\n";
	return 0;
}