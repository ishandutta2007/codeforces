#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e3;
long long tab[N+10];
vector<int> e[N+10];
bool vis[N+10];
int mt[N+10];
bool dfs(int x)
{
	vis[x]=true;
	for(auto v:e[x])
	{
		if(mt[v]==0 || (!vis[mt[v]] && dfs(mt[v])))
		{
			mt[v]=x;
			mt[x]=v;
			return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>tab[i];
	for(int i=1;i<=n;i++)
	{
		if(tab[i]*3<=m)
			continue;
		for(int j=1;j<=n;j++)
		{
			if(tab[i]%tab[j]==0 && tab[j]<=m-tab[i]*2)
			{
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
	}
	for(bool con=true;con;)
	{
		con=false;
		for(int i=1;i<=n;i++)
			vis[i]=false;
		for(int i=1;i<=n;i++)
		{
			if(tab[i]*3<=m || vis[i] || mt[i]!=0)
				continue;
			if(dfs(i))
				con=true;
		}
	}
	vector<pair<int,int>> ans;
	for(int i=1;i<=n;i++)
	{
		if(mt[i]!=0)
		{
			if(tab[i]*3>m)
				ans.emplace_back(tab[i]*2+tab[mt[i]],tab[i]+tab[mt[i]]);
		}
		else if(tab[i]*3>m)
		{
			cout<<"-1\n";
			return 0;
		}
		else
			ans.emplace_back(tab[i]*3,tab[i]*2);
	}
	cout<<ans.size()<<"\n";
	for(auto [a,b]:ans)
		cout<<a<<" "<<b<<"\n";
	return 0;
}