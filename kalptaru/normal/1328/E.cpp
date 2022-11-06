#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod1=1000000007;
ll mod2=67280421310721;
ll mod3=998244353;
ll INF=1e18;
int parent[25][200005];
int dep[200005];
void dfs(int i,int j,vector<int> tree[],int d)
{
	parent[0][i]=j;
	dep[i]=d;
	FOR(k,0,tree[i].size())
	{
		if(tree[i][k]!=j)
		{
			dfs(tree[i][k],i,tree,d+1);
		}
	}
	return ;
}
bool che(int a,int b)
{
	return dep[a]>dep[b];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		int u,v;
		vector<int> tree[n];
		FOR(i,1,n)
		{
			cin>>u>>v;
			tree[u-1].pb(v-1);
			tree[v-1].pb(u-1);
		}
		dfs(0,-1,tree,0);
		int k;
		int z=1;
		int w=2;
		while(w<n)
		{
			FOR(i,0,n)
			parent[z][i]=parent[z-1][parent[z-1][i]];
			z++;
			w*=2;
		}
		FOR(i,0,m)
		{
			cin>>k;
			int v[k];
			FOR(i,0,k)
			{
				cin>>v[i];
				v[i]--;
			}
			sort(v,v+k,che);
			int d=dep[v[0]];
			int p=parent[0][v[0]];
			bool f=1;
			FOR(i,0,k)
			{
//				cout<<v[i]<<' ';
				if(dep[v[i]]==d)
				{
					if(parent[0][v[i]]!=p)
					{
//						cout<<d<<' '<<p<<' '<<v[i]<<'h'<<'\n';
						f=0;
//						break;
					}
				}
				else
				{
					int c;
					d=dep[v[i]];
					i--;
					c=dep[v[i]]-d;
					z=0;
					p=parent[0][v[i]];
					while(c>0)
					{
						if(c%2==1)
						{
							p=parent[z][p];
						}
						z++;
						c>>=1;
					}
				}
			}
			if(f)cout<<"YES"<<'\n';
			else cout<<"NO"<<'\n';
		}
	}
	return 0;
}