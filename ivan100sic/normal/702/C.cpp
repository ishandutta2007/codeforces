#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005], b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<m; i++) {
		cin >> b[i];
	}
	int r = 0;
	for (int i=0; i<n; i++) {
		auto it = lower_bound(b, b+m, a[i]);
		int d = 2'000'000'000;
		if (it != b) {
			d = min(d, a[i] - *prev(it));
		}
		if (it != b+m) {
			d = min(d, *it - a[i]);
		}
		r = max(r, d);
	}
	cout << r;
}