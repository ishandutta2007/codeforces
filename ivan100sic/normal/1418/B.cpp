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
		vector<int> a(n), l(n), p;
		for (int& x : a) cin >> x;
		for (int& x : l) cin >> x;
		for (int i=0; i<n; i++) {
			if (!l[i]) {
				p.push_back(i);
			}
		}
		sort(begin(p), end(p), [&](int x, int y) {
			return a[x] > a[y];
		});

		for (int i=0, j=0; i<n; i++) {
			if (l[i]) {
				cout << a[i];
			} else {
				cout << a[p[j++]];
			}
			cout << " \n"[i == n-1];
		}
	}
}