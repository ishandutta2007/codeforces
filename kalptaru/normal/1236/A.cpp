#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
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
	cin>>t;
	while ( t-- ) 
	{
		int a,b,c;
		cin>>a>>b>>c;
		c>>=1;
		if(b<c)
		cout<<3*b<<'\n';
		else
		{
			b-=c;
			b>>=1;
//			cout<<c<<'\n';
			cout<<3*(min(a,b)+c)<<'\n';
		}
	}
	return 0;
}