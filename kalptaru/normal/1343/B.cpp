#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
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
		}
		a=(a*a);
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
		ll n;
		cin>>n;
		if(n%4!=0)
		{
			cout<<"NO"<<'\n';
		}
		else
		{
			cout<<"YES\n";
			FOR(i,0,n/2)
			{
				cout<<2*(i+1)<<' ';
			}
			FOR(i,n/2,n-1)
			{
				cout<<1+2*(i-n/2)<<' ';
			}
			cout<<n-1+n/2<<'\n';
		}
	}
	return 0;
}