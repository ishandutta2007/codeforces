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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		string s;
		cin>>s;
		ll n=s.size();
		ll pre[n]={0},suf[n]={0};
		if(s[0]=='Q')
		pre[0]=1;
		if(s[n-1]=='Q')
		suf[n-1]=1;
		FOR(i,1,n)
		{
			if(s[i]=='Q')
			pre[i]++;
			pre[i]+=pre[i-1];
			if(s[n-i-1]=='Q')
			suf[n-i-1]++;
			suf[n-i-1]+=suf[n-i];
		}
		ll ans=0;
		FOR(i,0,n)
		{
			if(s[i]=='A')
			{
				ans+=(pre[i]*suf[i]);
			}
		}
		cout<<ans;
	}
	return 0;
}