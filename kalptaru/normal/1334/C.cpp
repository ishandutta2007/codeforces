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
		ll n;
		cin>>n;
		ll a[n],b[n];
		FOR(i,0,n)
		{
			cin>>a[i]>>b[i];
		}
		ll m=b[0],in=0;
		FOR(i,0,n)
		{
			b[i]=min(b[i],a[(i+1)%n]);
			if(b[i]<m)
			{
				in=i;
				m=b[i];
			}
		}
		in++;
		ll ans=0;
		FOR(i,0,n)
		{
			if(a[(i+in)%n]>0)
			{
				ans+=a[(i+in)%n];
			}
			a[(i+in+1)%n]-=b[(i+in)%n];
		}
		cout<<ans<<'\n';
	}
	return 0;
}