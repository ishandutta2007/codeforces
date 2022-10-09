#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
vector<vector<int>> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	a.resize(n, vector<int>(m));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
			a[i][j]--;
		}
	}
	int sol = 0;
	for (int j=0; j<m; j++) {
		map<int, int> cl;
		for (int i=0; i<n; i++) {
			if (a[i][j] % m == j && a[i][j] < n*m) {
				cl[(i - a[i][j] / m + n) % n]++;
			}
		}
		int lo = n;
		for (auto [c, v] : cl) {
			lo = min(lo, n - v + c);
		}
		sol += lo;
	}
	cout << sol << '\n';
}