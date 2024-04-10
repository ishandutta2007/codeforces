// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int c, n;
pair<int, int> a[22];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> c >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].second >> a[i].first;
	}

	sort(a, a+n);
	reverse(a, a+n);

	ll z = 0;
	for (int i=0; i<n; i++) {
		int t = min(c, a[i].second);
		z += 1ll*t*a[i].first;
		c -= t;
	}
	cout << z << '\n';
}