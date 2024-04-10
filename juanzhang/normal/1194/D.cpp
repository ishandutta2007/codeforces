#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;

void solve() {
	bool ans = 0;
	scanf("%I64d %I64d", &n, &k);
	if (k % 3 == 0) {
		ll t = k / 3 - 1;
		ll s = t * 3 + 4;
		n = n % s;
		if (!n) n = s;
		if (n <= s - 4) {
			ans = n % 3;
		} else {
			n -= s - 4;
			ans = n < 4;
		}
	} else {
		ans = n % 3;
	}
	puts(ans ? "Alice" : "Bob");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) solve();
  return 0;
}