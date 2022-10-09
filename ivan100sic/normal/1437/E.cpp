// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k;
int a[500005];
bool c[500005];
int d[500005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a[i] = x - i;
	}

	for (int i=0; i<k; i++) {
		int x;
		cin >> x;
		c[x-1] = 1;
	}

	d[0] = -123123123;
	int l = 0, r = 1;

	for (int i=0; i<n; i++) {
		int x = a[i];
		if (c[i]) {
			while (l < r && d[r-1] > x) {
				r--;
			}

			if (l == r) {
				cout << "-1\n";
				return 0;
			}

			l = r-1;
			d[l] = x;
		} else {
			auto i = upper_bound(d+l, d+r, x) - d;
			if (i == r) {
				d[r++] = x;
			} else if (i > l) {
				d[i] = x;
			}
		}

	}

	cout << n-k-(r-1) << '\n';
}