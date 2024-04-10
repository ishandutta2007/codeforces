#include <bits/stdc++.h>
using namespace std;

int n, m, a[110];

bool check(int mid) {
	for (int i = 1; i <= n; i++) {
		if (abs(a[i] - mid) > m) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	int val = 1e9;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		val = min(val, a[i]);
	}
	int x = val + m;
	if (check(x)) {
		printf("%d\n", x);
	} else {
		printf("%d\n", -1);
	}
}

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		solve();
	}
  return 0;
}