#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int maxN = 2234567;
int n, x;
int e[maxN], cnt[maxN], p[maxN], cc[maxN];
bool st[maxN];

void add(int x) {
	int y = x;
	while (y != 1) {
		int p1 = p[y];
		int e1 = 0;
		while (y % p1 == 0) {
			y /= p1;
			e1++;
		}
		if (e[p1] < e1) {
			e[p1] = e1;
			cc[p1] = 0;
		}
		if (e[p1] == e1) cc[p1]++;
	}
}

bool check(int x) {
	int y = x;
	while (y != 1) {
		int p1 = p[y];
		int e1 = 0;
		while (y % p1 == 0) {
			y /= p1;
			e1++;
		}
		if (e[p1] == e1 && cc[p1] == 1) return 0;
	}
	return 1;
}

bool checkMixed() {
	for (int i = 2000000; i >= 2; i--) {
		if (cnt[i] == 0 || st[i] == 0) continue;
		if (cnt[i] >= 3) return 1;
		if (check(i - 1)) return 1;
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		cnt[x]++;
	}
	for (int i = 2; i <= 2000000; i++) {
		if (p[i] == 0) {
			for (int j = i; j <= 2000000; j += i) {
				if (p[j] == 0) {
					p[j] = i;
				}
			}
		}
	}
	for (int i = 2000000; i >= 2; i--) {
		if (cnt[i] == 0) continue;
		if (e[i] == 0) {
			if (cnt[i] >= 2) add(i), add(i - 1), st[i] = 1;
			else add(i);
		} else {
			add(i - 1), st[i] = 1;
		}
	}
	i64 ans = 1;
	for (int i = 2; i <= 2000000; i++) {
		for (int j = 0; j < e[i]; j++) ans = ans * i % 1000000007;
	}
	if (checkMixed()) ans = (ans + 1) % 1000000007;
	printf("%lld\n", ans);
}