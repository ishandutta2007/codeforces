#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll m1=1000000007;
ll m2=67280421310721;
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		ll n,g,b,k;
		cin>>n>>g>>b;
		k=(n/2)+(n%2);
		ll ans=(k/g);
		ans*=(g+b);
		if(k%g==0)
		ans-=b;
		else
		ans+=(k%g);
		ans=max(n,ans);
		cout<<ans<<'\n';
	}
	return 0;
}