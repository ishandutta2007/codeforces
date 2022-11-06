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
vector<int> ans;
vector<int> a1,a2;
int co;
int dep[100005];
bool st[100005];
int wuf;
int k;
void dfs(int i,int j,vector<int> gra[],int d)
{
	if(dep[i]==0)
	{
		st[i]=1;
		dep[i]=d;
		FOR(k,0,gra[i].size())
		{
			if(gra[i][k]!=j)
			dfs(gra[i][k],i,gra,d+1);
			if(wuf!=0)
			{
				if(wuf<d)
				ans.pb(i);
				break;
			}
		}
		st[i]=0;
	}
	else
	{
//		cout<<i<<' '<<d<<' '<<dep[i]<<' '<<k<<'\n';
		if((d-dep[i])<=k && st[i]==1)
		{
			wuf=dep[i];
			ans.pb(i);
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
		int n,m;
		cin>>n>>m>>k;
		vector<int> gra[n];
		int u,v;
		FOR(i,0,m)
		{
			cin>>u>>v;
			u--;
			v--;
			gra[u].pb(v);
			gra[v].pb(u);
		}
		dfs(0,-1,gra,1);
		if(ans.size()!=0)
		{
			cout<<2<<'\n';
			cout<<ans.size()<<'\n';
			FOR(i,0,ans.size())
			cout<<ans[i]+1<<' ';
			return 0;
		}
		FOR(i,0,n)
		{
			if((dep[i]%2)==0)
			{
				a1.pb(i);
//				cout<<i<<' ';
			}
			else
			{
				a2.pb(i);
			}
		}
		k=(k+1)/2;	
		if(a1.size()>=k)
		{
			cout<<1<<'\n';
			FOR(i,0,k)
			cout<<a1[i]+1<<' ';
		}
		else
		{
			cout<<1<<'\n';
			FOR(i,0,k)
			cout<<a2[i]+1<<' ';
		}
	}
	return 0;
}