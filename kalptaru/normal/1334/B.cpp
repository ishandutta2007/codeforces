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
ll mod1=1000000007;
ll mod2=67280421310721;
ll mod3=998244353;
ll INF=1e18;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		ll n,x;
		cin>>n>>x;
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		sort(a,a+n);
		ll t=0;
		FOR(i,1,n+1)
		{
			t+=a[n-i];
			if(x>(t/i))
			{
				cout<<i-1<<'\n';
				break;
			}
		}
		if(x<=(t/n))
		cout<<n<<'\n';
	}
	return 0;
}