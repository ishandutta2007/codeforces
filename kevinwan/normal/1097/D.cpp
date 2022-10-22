#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
ll mod = 1e9 + 7;
int k;
ll po(ll a, ll b) {
	ll ans = 1;
	for (; b; b >>= 1, a = a * a%mod)if (b & 1)ans = ans * a%mod;
	return ans;
}
ll inv(ll x) {
	return po(x, mod - 2);
}
ll arr[100];
ll get(ll a,int p) {
	memset(arr, 0, sizeof(arr));
	arr[p] = 1;
	for (int i = 0; i < k; i++) {
		int j;
		for (j = 0; j <= p; j++)arr[j] = arr[j] * inv(j + 1) % mod;
		for (j = p - 1; j >= 0; j--)arr[j] = (arr[j] + arr[j + 1]) % mod;
	}
	ll ans = 0;
	for (int i = 0; i <= p; i++)ans = (ans + arr[i] * po(a, i))%mod;
	return ans;
}
unordered_map<ll, int> m;
int main() {
	ll n,i;
	scanf("%lld%d", &n,&k);
	for (i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			m[i]++;
			n /= i;
		}
	}
	if (n != 1)m[n]++;
	ll ans = 1;
	for (auto th : m) {
		ans = ans * get(th.first, th.second)%mod;
	}
	printf("%lld", ans);
}