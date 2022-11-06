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
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int p[n];
		cin>>p[0];
		vector<int> ans;
		ans.pb(p[0]);
		cin>>p[1];
		bool f=(p[0]<p[1]);
		FOR(i,2,n)
		{
			cin>>p[i];
			if(f)
			{
				if(p[i]<p[i-1])
				{
					ans.pb(p[i-1]);
					f=0;	
				}
				
			}
			else
			{
				if(p[i]>p[i-1])
				{
					ans.pb(p[i-1]);
					f=1;
				}
			}			
		}
		ans.pb(p[n-1]);
		cout<<ans.size()<<'\n';
		FOR(i,0,ans.size())
		cout<<ans[i]<<' ';
		cout<<'\n';
	}
	return 0;
}