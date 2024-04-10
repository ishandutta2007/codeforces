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
		int b,g,n;
		cin>>b>>g>>n;
		cout<<min(min(b+g-n,b),min(g,n))+1;		
	}
	return 0;
}