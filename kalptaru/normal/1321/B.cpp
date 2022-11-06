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
ll INF=1e18;
ll b[700001];
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
		int a[n];
		FOR(i,0,n)
		{
			cin>>a[i];
			b[a[i]-i+250000]+=a[i];
		}
		ll ans=0;
		FOR(i,0,700001)
		{
			ans=max(ans,b[i]);
		}
		cout<<ans;
	}
	return 0;
}