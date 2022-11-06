#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
#define pb(a) push_back(a);
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		ll a,b;
		cout<<'?';
		FOR(i,1,101)
		cout<<' '<<i;
		cout<<'\n';
		cin>>a;
		cout<<'?';
		FOR(i,1,101)
		cout<<' '<<i*128;
		cout<<'\n';
		cin>>b;
		cout<<"! "<<((a-(a%128))+(b%128));
	}
}