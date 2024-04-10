#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=998244353;
ll mod=1000000007;
ll INF=1e18;

ll po(ll a,ll b)
{
	ll re=1;
	a%=mod;
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
	int test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a[n],s=0;
		FOR(i,0,n)
		{
			cin>>a[i];
			s+=a[i];
		}
		if(s==0)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
			sort(a,a+n);
			if(s>0)
			{

			FORD(i,n,0)
			cout<<a[i]<<' ';
			}
			else
			{

				FOR(i,0,n)
				cout<<a[i]<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}