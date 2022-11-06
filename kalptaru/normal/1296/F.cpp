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
ll m1=1000000007;
ll m2=67280421310721;
pair<int,int> parent[5005];
vector<pair<int,int> > tree[5005];
struct q
{
	int a,b,g;
};
int dep[5005];
void dfs(int i,int j,int in,int d)
{
	parent[i]=mp(j,in);
	dep[i]=d;
	FOR(k,0,tree[i].size())
	{
		if(tree[i][k].first!=j)
		{
			dfs(tree[i][k].first,i,tree[i][k].second,d+1);
		}
	}
	return;
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
		int n;
		cin>>n;
		int x,y;
		int ans[n-1];
		FOR(i,0,n-1)
		{
			ans[i]=1;
			cin>>x>>y;
			tree[x-1].pb(mp(y-1,i));
			tree[y-1].pb(mp(x-1,i));
		}
		dfs(0,-1,-1,0);
		int m;
		cin>>m;
		q qu[m];
		int a,b,g;
		FOR(i,0,m)
		{
			cin>>a>>b>>g;
			a--;
			b--;
			if(dep[a]<dep[b])
			swap(a,b);
			qu[i].a=a;
			qu[i].b=b;
			qu[i].g=g;
			while(dep[a]!=dep[b])
			{
				ans[parent[a].second]=max(ans[parent[a].second],g);
				a=parent[a].first;
			}
			while(a!=b)
			{
				ans[parent[a].second]=max(ans[parent[a].second],g);
				ans[parent[b].second]=max(ans[parent[b].second],g);
				a=parent[a].first;
				b=parent[b].first;
			}
		}
		bool f=1;
		FOR(i,0,m)
		{
			int mi=1000000;
			a=qu[i].a;
			b=qu[i].b;
			g=qu[i].g;
			while(dep[a]!=dep[b])
			{
				mi=min(ans[parent[a].second],mi);
				a=parent[a].first;
			}
			while(a!=b)
			{
				mi=min(ans[parent[a].second],mi);
				mi=min(ans[parent[b].second],mi);
				a=parent[a].first;
				b=parent[b].first;
			}
			if(mi!=g)
			{
				f=0;
				break;
			}
		}
		if(f)
		{
			FOR(i,0,n-1)
			cout<<ans[i]<<' ';
		}
		else
		{
			cout<<-1;
		}
	}
	return 0;
}