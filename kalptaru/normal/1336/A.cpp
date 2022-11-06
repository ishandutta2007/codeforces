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
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
struct p
{
	ll i,s,d;
} ss[200005];
bool che(p a,p b)
{
//	if((a.d)==(b.d))
//	return (a.s)>(b.s);
	return (a.d-a.s)>(b.d-b.s);
	
}
bool t[200005];
ll ans=0;
int dfs(int i,int j,vector<int> tree[],int d)
{
	ss[i].i=i;
	ss[i].s=0;
	ss[i].d=d;
	FOR(k,0,tree[i].size())
	{
		if(tree[i][k]!=j)
		{
			ss[i].s+=dfs(tree[i][k],i,tree,d+1);
		}
	}
	return ss[i].s+1;
}
ll df(int i,int j,vector<int> tree[])
{
	int s=0;
	FOR(k,0,tree[i].size())
	{
		if(tree[i][k]!=j)
		{
			s+=df(tree[i][k],i,tree);
		}
	}
	if(t[i])
	{
		ans+=s;
	}
	else
	{
		s++;
	}
//	cout<<ans<<' '<<i<<'\n';
	return s;
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
		int n,k;
		cin>>n>>k;
		vector<int> tree[n];
		int u,v;
		FOR(i,1,n)
		{
			cin>>u>>v;
			tree[u-1].pb(v-1);
			tree[v-1].pb(u-1);
		}
		dfs(0,-1,tree,1);
		sort(ss,ss+n,che);
		FOR(i,0,n-k)
		{
			t[ss[n-i-1].i]=1;
		}
//		FOR(i,0,n)
//		cout<<t[i]<<' ';
		ll o=df(0,-1,tree);
		cout<<ans;
	}
	return 0;
}