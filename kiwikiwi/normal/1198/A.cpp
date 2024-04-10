#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n, k, z[423456];
map<int, int> cnt;

int main() {
	scanf("%d%d", &n, &k);
	k = k * 8 / n;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x] += 1;
	}
	if (k > 30) {
		printf("%d\n", 0);
		return 0;
	}
	int m = 0;
	for (auto p : cnt) {
		z[++m] = p.second;
	}
	if (m <= (1 << k)) {
		printf("%d\n", 0);
		return 0;
	}
	for (int i = 1; i <= m; i++)
		z[i] += z[i - 1];
	int answer = 0;
	for (int i = (1 << k); i <= m; i++) {
		answer = max(answer, z[i] - z[i - (1 << k)]);
	}
	printf("%d\n", n - answer);
}