#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int k, n, a, b;
	scanf("%I64d %I64d %I64d %I64d", &k, &n, &a, &b);
	int tmp = k - n * b;
	if (tmp < 1) {
		puts("-1"); return;
	}
	int res = (k - n * b - 1) / (a - b);
	printf("%d\n", min(res, n));
}

signed main() {
	int Tests;
	scanf("%I64d", &Tests);
	while (Tests--) solve();
  return 0;
}