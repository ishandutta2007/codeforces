// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		vector<int> a(n);
		for (int& x : a) {
			cin >> x;
		}

		for (int i=1; i<n; i++) {
			int r = min(a[i], d/i);
			a[i] -= r;
			d -= i*r;
			a[0] += r;
		}

		cout << a[0] << '\n';
	}
}