#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define maxN 323456
int n, m;
int a[maxN];

bool check(int c) {
	int premin = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] + c < m) {
			if (a[i] + c < premin) {
				return 0;
			} else {
				premin = max(premin, a[i]);
			}
		} else {
			if (a[i] + c - m < premin)
				premin = max(premin, a[i]);
		}
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int l = -1, r = m;
	while (l + 1 < r) {
		int c = (l + r) / 2;
		if (check(c))
			r = c;
		else
			l = c;
	}
	printf("%d\n", r);
}