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
		vector<int> a(n), b(2*n);
		set<int> un;
		for (int i=1; i<=2*n; i++) {
			un.insert(i);
		}
		for (int& x : a) {
			cin >> x;
			un.erase(x);
		}

		int ok = 1;

		auto dopuni = [&](int j) {
			vector<int> o(n-j);
			iota(begin(o), end(o), j);
			sort(begin(o), end(o), [&](int x, int y) {
				return a[x] > a[y];
			});

			auto un1 = un;
			for (int t=0; t<(int)o.size(); t++) {
				int i = o[t];
				auto it = un1.lower_bound(a[i]);
				if (it == un1.end()) {
					return false;
				}
				un1.erase(it);
			}
			return true;
		};

		for (int i=0; i<n; i++) {
			for (int l=a[i]+1; l<=2*n; l++) {
				if (un.count(l)) {
					un.erase(l);
					if (dopuni(i+1)) {
						b[2*i+0] = a[i];
						b[2*i+1] = l;
						break;
					} else {
						un.insert(l);
					}
				}
			}
			if (b[2*i] == 0) {
				ok = 0;
				break;
			}
		}

		if (ok) {
			for (int x : b) cout << x << ' ';
			cout << '\n';
		} else {
			cout << "-1\n";
		}
	}
}