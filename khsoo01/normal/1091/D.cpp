#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll n, ans;

int main()
{
	scanf("%lld",&n);
	ll C = 1, D = 1;
	for(ll i=1;i<=n;i++) {
		C = C * i % mod;
	}
	ans += C;
	for(ll i=n;i>=1;i--) {
		D = D * i % mod;
		ans = (ans + C + mod - D) % mod;
	}
	printf("%lld\n",ans);
}