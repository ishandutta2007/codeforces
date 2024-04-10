#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 501000

int a[maxN], p[maxN], n;
array<int, 2> b[maxN];
void solve() {
	scanf("%d", &n);
	int t = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i == 1 || a[i] != a[i - 1]) {
			b[++t] = {a[i], 1};
		} else {
			b[t][1]++;
		}
	}
	for (int k = 1; k < n; k++) {
		int t2 = 0;
		int cnt = 0;
		for (int i = 1; i <= t; i++) {
			cnt += b[i][1] - 1;
			if (i > 1) p[t2++] = b[i][0] - b[i - 1][0];
		}
		sort(p, p + t2);
		t = 0;
		if (cnt > 0) {
			b[++t] = {0, cnt};
		}
		for (int j = 0; j < t2; j++) {
			if (t == 0 || p[j] != b[t - 1][0]) {
				b[++t] = {p[j], 1};
			} else {
				b[t][1]++;
			}
		}
	}
	printf("%d\n", b[1][0]);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int T = 0 ; T < tc; T++) {
		solve();
	}
}