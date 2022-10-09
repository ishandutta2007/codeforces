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
		vector<pair<int, int>> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}

		// inverzije?
		int inv = 0;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if (a[i] > a[j]) {
					inv++;
				}
			}
		}

		vector<int> sol;

		auto mv = [&](int j) {
			sol.push_back(j);
			auto x = a[j], y = a[j+1], z = a[j+2];
			a[j] = z;
			a[j+1] = x;
			a[j+2] = y;
		};

		if (inv % 2) {
			// nadji dva ista, ako ne moze, cao
			bool found = false;
			for (int i=0; i<n && !found; i++) {
				for (int j=i+1; j<n && !found; j++) {
					if (a[i].first == a[j].first) {
						swap(a[i], a[j]);
						found = true;
					}
				}
			}

			if (!found) {
				cout << "-1\n";
				continue;
			}
		}

		for (int i=0; i<n; i++) {
			int j = min_element(a.begin() + i, a.end()) - a.begin();
			while (j > i) {
				if (j == n-1) {
					mv(j-2);
					j -= 2;
				} else {
					mv(j-1);
					mv(j-1);
					j -= 1;
				}
			}
		}

		while (!is_sorted(a.end()-3, a.end())) {
			mv(n-3);
		}

		cout << sol.size() << '\n';
		for (int x : sol) {
			cout << x+1 << ' ';
		}
		cout << '\n';
	}
}