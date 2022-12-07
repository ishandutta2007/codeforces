#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int n, l, r;

ll pow_mod(ll x, ll k) {
	ll ans = 1;
	while (k) {
		if (k&1) ans = ans * x;
		x = x * x;
		k >>= 1;
	}
	return ans;
}

ll cal(int a, int b) {
	ll zi = pow_mod(a, n - 1);
	ll mu = pow_mod(b, n - 1);
	ll up = r * zi / mu;
	if (up < l) return 0;
	return up / zi - (l - 1) / zi;
}

ll gao() {
	if (n == 1) return r - l + 1;
	if (n == 2) return 1ll * (r - l + 1) * (r - l);
	if (n > 25) return 0;
	ll ans = 0;
	for (int i = 1; ;i++) {
		if (pow_mod(i + 1, n - 1) - pow_mod(i, n - 1) > r - l + 1) break;
		for (int j = i + 1; ;j++) {
			if (__gcd(i, j) != 1) continue;
			ll tmp = cal(i, j);
			if (tmp == 0) break;
			ans += tmp;
		}
	}
	return ans * 2;
}

int main() {
	scanf("%d%d%d", &n, &l, &r);
	printf("%lld\n", gao());
	return 0;
}