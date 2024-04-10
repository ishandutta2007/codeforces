#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
ll ncr[251][251];
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		ll a[n]={0},c,o=0,e;
		ll d=0,ans=0;
		FOR(i,0,n)
		{
			cin>>a[i];
			d+=a[i];
		}
		sort(a,a+n);
		c=d/n;
		e=d%n;
		FOR(i,0,n)
		{
			if(i<e)
			o=1;
			ans+=(abs(a[n-i-1]-(c+o)));
			o=0;
		}
		cout<<(ans>>1);
	}
	return 0;
}