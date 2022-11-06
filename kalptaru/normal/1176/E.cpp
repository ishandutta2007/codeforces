#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int dfs(int i,int j,int s,vector<int> gr[],bool vis[],vector<int> &a,vector<int> &b)
{
	if(s==1)
	{
		a.push_back(j);
		s=0;
	}
	else
	{
		b.push_back(j);
		s=1;
	}
	vis[j]=0;
	for(int k=0;k<gr[j].size();k++)
	{
		if(gr[j][k]!=i && vis[gr[j][k]]==1)
		dfs(j,gr[j][k],s,gr,vis,a,b);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int t;
 	cin>>t;
 	while(t--)
 	{
 		int n,m,u,v;
 		cin>>n>>m;
 		bool vis[n];
 		for(int i=0;i<n;i++)
 		vis[i]=1;
 		vector<int> gr[n],a,b;
 		for(int i=0;i<m;i++)
 		{
 			cin>>u>>v;
 			gr[u-1].push_back(v-1);
 			gr[v-1].push_back(u-1);
		}
		dfs(-1,0,0,gr,vis,a,b);
		if(a.size()<b.size())
		{
			cout<<a.size()<<"\n";
			for(int i=0;i<a.size();i++)
			cout<<a[i]+1<<' ';
		}
		else
		{
			cout<<b.size()<<"\n";
			for(int i=0;i<b.size();i++)
			cout<<b[i]+1<<' ';
		}
		cout<<"\n";
	}
	return 0;
}