#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, m, cnt[maxn];

bool check(int x) {
	if (!x) {
		return 1;
	}
	int now = 0;
	for (int i = 1; i < 101; i++) {
		now += cnt[i] / x;
	}
	return now >= n;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1, x; i <= m; i++) {
		scanf("%d", &x), cnt[x]++;
	}
	int l = 0, r = 100;
	for (int mid; l <= r; ) {
		mid = l + r >> 1;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%d", l + r >> 1);
	return 0;
}