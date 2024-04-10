#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	int minv = INF;
	for (int i = 0; i < n; ++i) minv = min(minv, a[i]);
	int add = 0, now = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == minv) {
			add = max(add, now);
			now = 0;
		} else ++now;
	}
	int i = 0;
	while (a[i] > minv) {
		++i;
		++now;
	}
	add = max(add, now);
	cout << (ll)n * minv + add << '\n';
}