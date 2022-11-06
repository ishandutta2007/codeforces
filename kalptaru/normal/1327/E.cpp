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
ll mod1=1000000007;
ll mod2=67280421310721;
ll mod3=998244353;
ll INF=1e18;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	
	while(test--)
	{
		int n;
		cin>>n;
		
		ll a,p[n];
		p[0]=1;
		FOR(i,1,n)
		{
			p[i]=(p[i-1]*10)%mod3;
		}
		FOR(i,1,n)
		{
			a=(2*9*p[n-i]+81*p[n-i-1]*(n-i-1))%mod3;
			cout<<a<<' ';
		}
		cout<<10;
	}
	return 0;
}