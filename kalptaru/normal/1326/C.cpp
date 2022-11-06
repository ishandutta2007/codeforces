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
		int n,k;
		cin>>n>>k;
		ll p[n],b[k];
		ll ans1=0;
		FOR(i,0,n)
		{
			cin>>p[i];
			if(i>=(n-k))
			{
				ans1+=(i+1);
			}
		}
		ll ans2=1;
		ll c=0;
		bool f=0;
		FOR(i,0,n)
		{
			if(p[i]>(n-k))
			{
				b[c]=i;
				c++;
			}
		}
		FOR(i,1,k)
		{
			ans2*=(b[i]-b[i-1]);
			ans2%=mod3;
		}
		cout<<ans1<<' '<<ans2;
	}
	return 0;
}