#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
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
		string s;
		cin>>s;
		int i=n;
		while(i<(2*n) && s[n-1]==s[i%n])
		i++;
		if(i==2*n)
		{
			cout<<(n-1)/3+1<<'\n';
			continue;
		}
		int c=0,ans=0;
		FOR(j,0,n+1)
		{
			if(s[(i-1)%n]!=s[i%n])
			{
				ans+=(c/3);
				c=1;
			}
			else
			c++;
			i++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}