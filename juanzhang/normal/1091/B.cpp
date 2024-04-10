#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n; pair <int, int> a[maxn], b[maxn];

bool check(int pos) {
	pair <int, int> p = make_pair(a[1].first + b[pos].first, a[1].second + b[pos].second);
	for (int i = 1; i <= n; i++) {
		int l = 1, r = n, mid, res;
		while (l <= r) {
			if (make_pair(p.first - b[i].first, p.second - b[i].second) <= a[mid = l + r >> 1]) {
				r = (res = mid) - 1;
			} else {
				l = mid + 1;
			}
		}
		if (a[res] != make_pair(p.first - b[i].first, p.second - b[i].second)) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &b[i].first, &b[i].second);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (check(i)) return printf("%d %d", a[1].first + b[i].first, a[1].second + b[i].second), 0;
	}
	return 0;
}