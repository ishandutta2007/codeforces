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
		string s;
		cin>>s;
		vector< vector< pair<char,int> > > dp;
		vector< pair<char,int> > k;
		dp.pb(k);
		char p='`';
		int l=-1,r=0,ans=0;
		bool f;
		FOR(i,0,s.size())
		{
			if(s[i]==p)
			{
				dp[0][l].second++;
//				cout<<'k';
			}
			else
			{
				p=s[i];
				dp[0].pb(mp(p,1));
				l++;
			}
//			FOR(i,0,dp[0].size())
//			cout<<dp[0][i].second<<' ';
//			cout<<'\n';
		}
		while(dp[r].size()>1)
		{
			f=1;
//			cout<<dp[r].size()<<' ';
			while(f)
			{
//				cout<<dp[r][0].second<<' ';
				FOR(i,1,dp[r].size())
				{
//					cout<<dp[r][i].second<<' ';
					dp[r][i].second--;
					dp[r][i-1].second--;
					if(dp[r][i-1].second<1)
					{
						f=0;
//						cout<<dp[r][i-1].second<<'i';
					}
				}
				if(dp[r][dp[r].size()-1].second<1)
				{
					f=0;
				}
//				cout<<'\n';
				ans++;
			}
			p='`';
			dp.pb(k);
			l=-1;
			FOR(i,0,dp[r].size())
			{
//				cout<<dp[r][i].second<<dp[r][i].first<<' ';
				if(dp[r][i].second>0)
				{
					if(dp[r][i].first==p)
					dp[r+1][l].second+=dp[r][i].second;
					else
					{
						p=dp[r][i].first;
						dp[r+1].pb(mp(p,dp[r][i].second));
						l++;
					}
				}
			}
//			cout<<'\n';
			r++;
//			cout<<ans<<' ';
		}
		cout<<ans;
	}
	return 0;
}