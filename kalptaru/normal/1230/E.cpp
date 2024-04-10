#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;
ll inf=1000000000000000002;
ll mod=1000000007;
vector<int > tree[100001];
ll x[100001];
ll ans=0;
ll gcd(ll a,ll b)
{
	if(a<b)swap(a,b);
	if(b==0)return a;
	if(a%b==0)return b;
	return gcd(b,a%b);
}
void dfs(int i,int p,vector<pair<ll,int> > dp)
{
	ll g;
	int s=0;
	vector<pair<ll,int> >tdp;
	tdp.push_back({x[i],1});
	FOR(k,0,dp.size())
	{
		g=gcd(dp[k].first,x[i]);
		if(g==tdp[s].first)
		{
			tdp[s].second+=dp[k].second;
		}
		else
		{
			tdp.push_back({g,dp[k].second});
			s++;
		}
	}
	FOR(k,0,tree[i].size())
	{
		if(tree[i][k]!=p)
		dfs(tree[i][k],i,tdp);
		
	}
	s++;
	FOR(k,0,s)
	{
		ans=((ans+((tdp[k].first%mod)*tdp[k].second)%mod)%mod);
	}
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,u,v;
		cin>>n;
		FOR(i,0,n)
		cin>>x[i];
		FOR(i,1,n)
		{
			cin>>u>>v;
			tree[u-1].push_back(v-1);
			tree[v-1].push_back(u-1);
		}
		vector<pair<ll,int> > dp;
		dfs(0,-1,dp);
		cout<<ans;
	}
	return 0;
}