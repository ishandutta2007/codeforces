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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}

		int d = 0;
		for (int i=1; i<n; i++) {
			d = max(d, abs(a[i] - a[i-1]));
		}
		if (d > 0) {
			cout << "1\n";
		} else {
			cout << n << '\n';
		}
	}
}