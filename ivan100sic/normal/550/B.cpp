#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, l, r, x, y;
int c[15];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> l >> r >> x;
	for (int i=0; i<n; i++)
		cin >> c[i];

	for (int mask=0; mask<(1<<n); mask++) {
		int lo = 1e9, hi = -1e9, tot = 0;
		for (int i=0; i<n; i++)
			if (mask & (1 << i)) {
				lo = min(lo, c[i]);
				hi = max(hi, c[i]);
				tot += c[i];
			}
		if (l <= tot && tot <= r && hi - lo >= x)
			y++;
	}
	cout << y << '\n';
}