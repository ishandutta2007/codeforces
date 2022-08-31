#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll lcm(ll a, ll b)
{
	return (a*(b/__gcd(a,b)));
}
ll lcm3(ll a, ll b, ll c)
{
	return lcm(a,lcm(b,c));
}
int main()
{
	int n;
	cin>>n;
	ll ans = 1;
	for(ll i = n;i>=max(1,n-100);i--)
	{
		for(ll j = i;j>=max(1,n-100);j--)
			for(ll k = j;k>=max(1,n-100);k--)
				ans = max(ans,lcm3(i,j,k));
	}
	cout<<ans;
}