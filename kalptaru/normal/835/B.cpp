#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
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
		a=(a*a)%mod;
		b>>=1;
	}
	return re;
}
vector<pair<int,int> > ver[200005],hor[200005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		ll k,su=0,q;
		string s;
		cin>>k;
		cin>>s;
		ll f[10]={0};
		FOR(i,0,s.size())
		{
			f[s[i]-'0']++;
			su+=(s[i]-'0');
		}
		k-=su;
		int ans=0;
		FOR(i,0,10)
		{
			if(k<=0)
			break;
			q=(k-1)/(9-i) +1;
			if(f[i]<q)
			{
				k-=((9-i)*f[i]);
				ans+=f[i];
			}
			else
			{
				k-=((9-i)*q);
				ans+=q;
			}
		}
		cout<<ans;
	}
	return 0;
}