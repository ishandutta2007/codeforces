#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[120005];

inline bool ima(int x, int l, int r) {
	auto it = lower_bound(a+l, a+r, x);
	return (it != a+r && *it == x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	sort(a, a+n);

	int c = 0;

	for (int i=0; i<n; i++) {
		bool ok = false;
		for (ll j=1; j<=1ll<<30; j*=2) {
			if (ima(j-a[i], 0, i) || ima(j-a[i], i+1, n)) {
				ok = true;
				break;
			}
		}
		if (!ok)
			c++;
	}
	cout << c << '\n';
}