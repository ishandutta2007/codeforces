#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) ;for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		ll a[n],s=0;
		FOR(i,0,n)
		{
			cin>>a[i];
			s+=a[i];
		}
		sort(a,a+n);
		int m=n/2;
		ll k=0;
		FOR(i,0,m)
		{
			k+=a[i];
		}
		s-=k;
		cout<<s*s+k*k;
	}
	return 0;
}