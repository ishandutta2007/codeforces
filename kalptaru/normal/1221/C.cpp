#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while ( t-- ) 
	{
		ll c,m,x,ans=0;
		cin>>c>>m>>x;
		ll n=(m+c+x)/3;
		cout<<min(min(c,m),n)<<'\n';
	}
	return 0;
}