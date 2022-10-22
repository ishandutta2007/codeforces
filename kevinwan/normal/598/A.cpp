#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n,ans;
		scanf("%lld", &n);
		ans = n * (n + 1) / 2;
		for (ll i = 1; i <= n; i <<= 1)ans -= i<<1;
		printf("%lld\n", ans);
	}
}