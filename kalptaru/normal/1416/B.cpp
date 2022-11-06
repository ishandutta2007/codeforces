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
// ll mod=1000000007;
ll mod=67280421310721;
// ll mod=998244353;
ll INF=1e9;
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
	#ifndef ONLINE_JUDGE 
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1,gt=0;
	cin>>test;
	// cout<<fixed<<setprecision(10);
	while(test--)
	{
		int n;
		cin>>n;
		ll a[n],s=0;
		FOR(i,0,n)
		{
			cin>>a[i];
			s+=a[i];
		}
		if((s%n)!=0)
		{
			cout<<-1<<'\n';
			continue;
		}
		s/=n;
		vector<int> ans;
		FOR(i,1,n)
		{
			int o=a[i]/(i+1);
			if((a[i]%(i+1))!=0)
			{
				ans.pb(1);
				ans.pb(i+1);
				ans.pb(i+1-(a[i]%(i+1)));
				o++;
			}
			ans.pb(i+1);
			ans.pb(1);
			ans.pb(o);
		}
		FOR(i,1,n)
		{
			ans.pb(1);
			ans.pb(i+1);
			ans.pb(s);
		}
		int o=ans.size()/3;
		cout<<o<<'\n';
		FOR(i,0,o)
		{
			cout<<ans[3*i]<<' '<<ans[3*i+1]<<' '<<ans[3*i+2]<<'\n';
		}
	}
	return 0;
}