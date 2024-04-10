#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const ll mod = 998244353;
const int mn = 1000005;
ll ans;
ll fact[mn];
ll inv(ll x) {
	ll ans = 1;
	for (ll i = mod - 2; i; i >>= 1, x = x * x%mod)if (i & 1)ans = ans * x%mod;
	return ans;
}
int main() {
	ll n;
	int i;
	scanf("%lld", &n);
	fact[0] = 1;
	for (i = 1; i <= n; i++)fact[i] = fact[i - 1] * i%mod;
	ans = fact[n];
	for (i = 1; i <= n; i++)ans += fact[n] * (fact[n - i] - 1) % mod*inv(fact[n - i]) % mod, ans %= mod;
	printf("%lld", ans);
}