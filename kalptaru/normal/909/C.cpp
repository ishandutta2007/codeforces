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
		char k;
		vector<int> s;
		int c=0;
		FOR(i,0,n)
		{
			cin>>k;
			if(k=='s')
			{
				s.pb(c);
				c=0;
			}
			else
			c++;
		}
		if(c>0)
		{
			cout<<0;
			return 0;
		}
		ll dp[s.size()+1][n];
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		int m=1;
		ll o;
		FOR(i,0,s.size())
		{
			o=0;
			FORD(j,m,0)
			{
				o+=dp[i][j];
				o%=mod;
				dp[i+1][j+s[i]]+=o;
				dp[i+1][j+s[i]]%=mod;
			}
			m+=s[i];
		}
		o=0;
//		FOR(i,0,s.size()+1)
//		{
//			FOR(j,0,m)
//			cout<<dp[i][j]<<' ';
//			cout<<'\n';
//		}
		FOR(i,0,m)
		o=(o+dp[s.size()][i])%mod;
		cout<<o;
	}
	return 0;
}