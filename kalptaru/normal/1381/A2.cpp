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
//ll mod=1000000007;
//ll mod=67280421310721;
ll mod=998244353;
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
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		vector<int> ans;
		bool fl=0;
		int j=0,f=0;
		FORD(i,n,0)
		{
			if(fl==0)
			{
				if(b[i]==a[n-j-1])
				{
					j++;
					continue;
				}
				if(b[i]!=a[f])
				{
					ans.pb(i+1);
				}
				else
				{
					ans.pb(1);
					ans.pb(i+1);
				}
				f++;
				fl=1;
			}
			else
			{
				if(b[i]!=a[f])
				{
					f++;
					continue;
				}
				if(b[i]==a[n-j-1])
				{
					ans.pb(i+1);
				}
				else
				{
					ans.pb(1);
					ans.pb(i+1);
				}
				j++;
				fl=0;
			}
		}
		cout<<ans.size()<<' ';
		FOR(i,0,ans.size())
		{
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}