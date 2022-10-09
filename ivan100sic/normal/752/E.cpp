#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

int n, k;
int a[1000005];

inline int eval(int x, int p, int j) {
	int x0 = x >> j;
	int x1 = x0 + 1;
	int f1 = x1 & ((1 << j) - 1);
	int f0 = (1 << j) - f1;

	int z = 0;
	if (x0 >= p) z += f0;
	if (x1 >= p) z += f1;

	return z;
}

int d[10'000'005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	sort(a, a+n);

	int l = 1, r = 10'000'000, o = -1;

	while (l <= r) {

		int m = (l+r) >> 1;
		long long zb = 0;

		if (m == 1) {
			zb = accumulate(a, a+n, 0ll);
		} else {
			for (int i=1; i<=10'000'000; i++) {
				if (i >= m) {
					d[i] = 1;
					int h = i >> 1;
					d[i] = max(d[i], d[h] + d[i-h]);
				} else {
					d[i] = 0;
				}
			}
			for (int i=0; i<n; i++) {
				zb += d[a[i]];
			}
		}

		cerr << m << ' ' << zb << '\n';

		if (zb >= k) {
			o = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}

	cout << o;

}