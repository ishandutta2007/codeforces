#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC

const int maxn = 1e5+10;
vii child[maxn];
int par[maxn];
int a[maxn];
int subsize[maxn];
bool visited[maxn];
int mxsum[maxn];
int dfs(int node)
{
	visited[node] = 1;
	int sm = 1;
	for(int i = 0;i<child[node].size();i++)
	{
		int nnode = child[node][i].F;
		if(!visited[nnode]){
			par[nnode] = node;
			sm += dfs(nnode);
		}
	}
	subsize[node] = sm;
	return sm;
}

int dfs2(int node,ll mxval)
{
	int sm = 0;
	visited[node] = 1;
	if(mxval > a[node])
		return subsize[node];
	for(int i = 0;i<child[node].size();i++)
	{
		int nnode = child[node][i].F;
		if(!visited[nnode])
		{
			ll mxval1 = max(0LL,(ll)child[node][i].S + mxval);
			sm += dfs2(nnode,mxval1);
		}
	}
	return sm;
}
int main()
{
	memset(visited,0,sizeof visited);
	int n;
	scanf("%d",&n);
	for(int i =1;i<=n;i++)
		scanf("%d",&a[i]);
	int p,c;
	for(int i = 1;i<n;i++)
	{
		scanf("%d%d",&p,&c);
		child[i+1].pb(mp(p,c));
		child[p].pb(mp(i+1,c));
	}
	dfs(1);
	memset(visited,0,sizeof visited);
	cout<<dfs2(1,0);
}