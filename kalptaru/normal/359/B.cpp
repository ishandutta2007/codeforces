#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define pb(a) push_back(a);
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,k;
		cin>>n>>k;
		FOR(i,0,k)
		{
			cout<<2*i+2<<' '<<2*i+1<<' ';
		}
		FOR(i,k,n)
		{
			cout<<2*i+1<<' '<<2*i+2<<' ';
		}
		
	}
	return 0;
}