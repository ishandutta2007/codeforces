#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		ll a,b=0;
		FOR(i,0,n)
		{cin>>a;
		b+=a;
		}
		a=b/n;
		if(b%n>0)
		a++;
		cout<<a<<'\n';
	}
	return 0;
}