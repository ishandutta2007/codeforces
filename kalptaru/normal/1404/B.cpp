#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include<vector>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
//			re%=mod;
		}
		a=(a*a);
//		a%=mod;
		b>>=1;
	}
	return re;
}
int m,op,b,mi;
void dfs(int i,int j,vector<int> tree[],int d)
{
	if(d>m)
	{
		m=d;
		mi=i;
	}
	if(i==(b-1))
	op=d;
	FOR(k,0,tree[i].size())
	{
		if(tree[i][k]!=j)
		{
			dfs(tree[i][k],i,tree,d+1);
		}
	}
	return ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		int n,a,da,db,u,v;
		cin>>n>>a>>b>>da>>db;
		vector<int> tree[n];
		FOR(i,1,n)
		{
			cin>>u>>v;
			tree[u-1].pb(v-1);
			tree[v-1].pb(u-1);
		}
		m=0;
		dfs(a-1,-1,tree,0);
		if(op<=da || db<=(2*da))
		{
			cout<<"Alice\n";
			continue;
		}
		dfs(mi,-1,tree,1);
//		cout<<m;v
		m/=2;
		if(m<=da)
		{
			cout<<"Alice\n";
		}
		else
		{
			cout<<"Bob\n";
		}
	}
	return 0;
}