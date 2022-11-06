#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
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
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
void dfs(int i,int j,vector<int> tree[],ll& d1,ll& d2,int d)
{
 	if(d%2==0)
 	d2++;
 	else
 	d1++;
 	FOR(k,0,tree[i].size())
 	{
 		if(tree[i][k]!=j)
 		dfs(tree[i][k],i,tree,d1,d2,d+1);
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
		ll n;
		cin>>n;
		vector<int> tree[n];
		int u,v;
		FOR(i,1,n)
		{
			cin>>u>>v;
			tree[u-1].pb(v-1);
			tree[v-1].pb(u-1);
		}
		ll d1=0,d2=0;
		dfs(0,-1,tree,d1,d2,0);
		cout<<((d1*d2)-n+1);
	}
	return 0;
}