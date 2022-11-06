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
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll ans=0;
		ll a[n];
		ll b[n];
		set<ll> o;
		int l=0,r=1;
		b[0]=0;
		o.insert(0);
		FOR(i,1,n+1)
		{
			cin>>a[i-1];
			b[i]=a[i-1]+b[i-1];
		}
		while(l<n)
		{
			while(o.find(b[r]) == o.end() && r<=n)
			{
				o.insert(b[r]);
				r++;
			}
			ans+=(r-l-1);
			o.erase(b[l]);
			l++;
		}
		cout<<ans;
	}
	return 0;
}