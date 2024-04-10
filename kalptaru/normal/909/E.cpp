#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
//ll mod=163577857;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a)%mod;
		}
		a=(a*a)/mod;
		b>>=1;
	}
	return re;
}
void mulpro(int i,vector<int> out[],bool co[],queue<int>& muli,queue<int>& coi,int inc[])
{
	int u;
	FOR(j,0,out[i].size())
	{
		u=out[i][j];
		if(co[u])
		{
			inc[u]--;
			if(inc[u]==0)
			coi.push(u);
		}
		else
		{
			inc[u]--;
			if(inc[u]==0)
			muli.push(u);
		}
	}
}
void copro(int i,vector<int> out[],bool co[],queue<int>& muli,queue<int>& coi,int inc[])
{
	int u;
	FOR(j,0,out[i].size())
	{
		u=out[i][j];
		if(co[u])
		{
			inc[u]--;
			if(inc[u]==0)
			coi.push(u);
		}
		else
		{
			inc[u]--;
			if(inc[u]==0)
			muli.push(u);
		}
	}
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		bool co[n],vis[n]={0};
		FOR(i,0,n)cin>>co[i];
		int inc[n]={0};
		vector<int> out[n];
		queue<int> muli,coi;
		int u,v;
		FOR(i,0,m)
		{
			cin>>u>>v;
			out[u].pb(v);
			inc[v]++;
		}
		FOR(i,0,n)
		{
			if(inc[i]==0)
			{
				if(co[i])
				coi.push(i);
				else
				muli.push(i);
			}
//			cout<<inc[i]<<' ';
		}
		int ans=0;
		bool d=0;
		while(n>0)
		{
			d=1;
			while(!muli.empty())
			{
				u=muli.front();
				mulpro(u,out,co,muli,coi,inc);
				muli.pop();
//				cout<<u<<'m';
				n--;
			}
			while(!coi.empty())
			{
				d=0;
				u=coi.front();
				copro(u,out,co,muli,coi,inc);
				coi.pop();
				n--;
			}
			if(d==0)
			ans++;
		}
		cout<<ans;
	}
	return 0;
}