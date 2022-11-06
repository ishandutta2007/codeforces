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
ll fa[250001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	cin>>mod;
	ll ans=0;
	fa[0]=1;
	FOR(i,1,250001)
	fa[i]=(fa[i-1]*i)%mod;
	FOR(i,1,n+1)
	{
		ll o=(((fa[i]*fa[n-i+1])%mod)*(n-i+1));
		ans=(ans+o)%mod;
	}
	cout<<ans;
	return 0;
}