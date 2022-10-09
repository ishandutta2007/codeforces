// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0, x; i<n; i++)
		cin >> x, a[i] -= x;

	sort(a, a+n);
	ll z = 0, c = 0;
	for (int i=0; i<n; i++) {
		z += a + n - upper_bound(a, a+n, -a[i]);
		c += a[i] > 0;
	}
	cout << (z - c) / 2 << '\n';
}

// I will still practice daily...