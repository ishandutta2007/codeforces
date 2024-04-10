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
		int n, T;
		basic_string<int> d;
		cin >> n >> T;
		vector<int> a(n), c(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (a[i]*2 < T) {
				c[i] = 0;
			} else if (a[i]*2 > T) {
				c[i] = 1;
			} else {
				d += i;
			}
		}

		int k = d.size() / 2;
		for (int i=0; i<(int)d.size(); i++) {
			if (i < k) {
				c[d[i]] = 0;
			} else {
				c[d[i]] = 1;
			}
		}

		for (int i=0; i<n; i++) {
			cout << c[i] << " \n"[i == n-1];
		}
	}
}