#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
typedef long long int ll;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,v;
		cin>>n;
		pair<int ,int > a[n];
		FOR(i,0,n)
		{
			cin>>v;
			a[i]={v,i+1};
		}
		sort(a,a+n);
		ll ans=n;
		FOR(i,0,n)
		{
			ans+=(a[n-i-1].first*i);
		}
		cout<<ans<<'\n';
		FOR(i,0,n)
		{
			cout<<a[n-i-1].second<<' ';
		}
	}
	return 0;
}