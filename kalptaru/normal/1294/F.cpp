#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) ;for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int dep[200002];
int parent[200002];
int dfs(int i,int j,vector<int> tree[],int d)
{
	int n=i,no;
	int md=d;
	dep[i]=d;
	parent[i]=j;
	FOR(k,0,tree[i].size())
	{
		if(tree[i][k]!=j)
		{
			no=dfs(tree[i][k],i,tree,d+1);
			if(dep[no]>md)
			{
				md=dep[no];
				n=no;
			}	
		}
	}
	return n;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		vector<int> tree[n];
		pair<int,int> ed[n-1];
		int u,v;
		FOR(i,0,n-1)
		{
			cin>>u>>v;
			ed[i]=mp(u,v);
			tree[u-1].pb(v-1);
			tree[v-1].pb(u-1);
		}
		int n1,n2,n3;
		n1=dfs(0,-1,tree,0);
		n2=dfs(n1,-1,tree,0);
		vector<int> ntree[n];
		bool sno[n]={0};
		int cno=n2;
		int ans=0;
		while(cno>=0)
		{
			sno[cno]=1;
			cno=parent[cno];
			ans++;
		}
		if(ans==n)
		{
			if(min(n1,n2)==0)
			{
				if(max(n1,n2)==1)
				{
					n3=2;
				}
				else
				{
					n3=1;
					
				}
			}
			else
			{
				n3=0;
			}
			cout<<ans-1<<'\n';
			cout<<n1+1<<' '<<n2+1<<' '<<n3+1;
			return 0;
		}
		FOR(i,0,n-1)
		{
			u=ed[i].first;
			v=ed[i].second;
			if(sno[u-1])
			{
				if(sno[v-1]);
				else
				{
					ntree[n2].pb(v-1);
					ntree[v-1].pb(n2);
				}
				
			}
			else
			{
				if(sno[v-1])
				{
					ntree[n2].pb(u-1);
					ntree[u-1].pb(n2);
				}
				else
				{
					ntree[v-1].pb(u-1);
					ntree[u-1].pb(v-1);
				}
			}
		}
		n3=dfs(n2,-1,ntree,0);
		ans+=dep[n3];
		cout<<ans-1<<'\n';
		cout<<n1+1<<' '<<n2+1<<' '<<n3+1;
	}
	return 0;
}