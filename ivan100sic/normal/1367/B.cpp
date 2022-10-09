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
		for (int& x : a)
			cin >> x;

		int p = 0, m = 0;
		for (int i=0; i<n; i++) {
			if (a[i] % 2 != i % 2) {
				if (a[i] % 2)
					p++;
				else
					m++;
			}
		}

		if (p == m) {
			cout << p << '\n';
		} else {
			cout << "-1\n";
		}
	}
}