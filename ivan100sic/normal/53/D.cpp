// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[305], b[305];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> b[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	vector<pair<int, int>> sol;

	for (int i=1; i<=n; i++) {
		if (a[i] != b[i]) {
			for (int j=i+1; j<=n; j++) {
				if (a[j] == b[i]) {
					for (int k=j; k>i; k--) {
						sol.emplace_back(k-1, k);
						swap(a[k-1], a[k]);
					}
					break;
				}
			}
		}
	}

	// for (int i=1; i<=n; i++) cerr << a[i] << " \n"[i == n];

	cout << sol.size() << '\n';
	for (auto [x, y] : sol) {
		cout << x << ' ' << y << '\n';
	}
}