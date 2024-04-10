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
		string s,t;
		cin>>s>>t;
		int z=0,o=0;
		FOR(i,0,n)
		{
			if(s[i]=='0')
			{
				z++;
			}
			if(t[i]=='0')
			{
				z--;
			}
		}
		if(z!=0)
		{
			cout<<-1;
			return 0;
		}
		int p=-1,u=0,c=1;
		bool f=1;
		int ans=0;
		vector<int> dp,tp;
		FOR(i,0,n)
		{
			if(s[i]==t[i])
			continue;
			f=0;
			if((s[i]-'0')==p)
			{
				u++;
			}
			else
			{
				if(p==-1)
				{
					u=1;
					p=(s[i]-'0');
				}
				else
				{
					dp.pb(u);
					u=1;
					p=p^1;
					c++;
				}
			}
		}
		if(f)
		{
			cout<<0;
			return 0;
		}
		if((c%2)==0)
		{
			dp.pb(u);
		}
		else
		{
			dp[0]+=u;
		}
		while(dp.size())
		{
			int m=dp[0],k=dp.size();
			FOR(i,1,k)
			{
				m=min(m,dp[i]);
			}
			ans+=m;
			p=-1;
			u=0;
			FOR(i,0,k)
			{
				dp[i]-=m;
				if(dp[i]==0)
				continue;
				int h=(i%2);
				if(h==p)
				{
					u+=dp[i];
				}
				else
				{
					if(p==-1)
					{
						u=dp[i];
						p=h;
					}
					else
					{
						tp.pb(u);
						u=dp[i];
						p=h;
					}
				}
			}
			if(tp.size()==0)
			break;
			if((tp.size()%2)==1)
			{
				tp.pb(u);
			}
			else
			{
				tp[0]+=u;
			}
			dp=tp;
			tp.clear();
		}
		cout<<ans;
	}
	return 0;
}