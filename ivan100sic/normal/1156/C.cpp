#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005], z;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> z;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);

	int l = 1, r = n/2, o = 0;
	while (l <= r) {
		int m = (l+r) >> 1, ok = 1;
		for (int i=0; i<m; i++) {
			if (a[n-m+i] - a[i] < z) {
				ok = 0;
			}
		}
		if (ok) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << o << '\n';
}