// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

vector<int> prefsum(vector<pair<int, int>> v) {
	int n = v.size();
	vector<int> a(n + 1);
	for (int i=0; i<n; i++) {
		a[i+1] = a[i] + v[i].first;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, k;
	cin >> n >> k;
	vector<int> a(n), tip(n);

	vector<pair<int, int>> p[4];
	vector<int> ps[4];

	for (int i=0; i<n; i++) {
		int x, u, v;
		cin >> x >> u >> v;
		a[i] = x;
		tip[i] = 2*u + v;
		p[tip[i]].emplace_back(x, i);
	}

	for (int i=0; i<4; i++) {
		sort(begin(p[i]), end(p[i]));
		ps[i] = prefsum(p[i]);
	}

	// koliko iz 3?
	int bestj = -1, bestv = 2.02e9;
	for (int j=0; j<=k; j++) {
		int r = k-j;
		bool radi = true;
		if (j > (int)p[3].size() || r > (int)p[1].size() || r > (int)p[2].size()) {
			radi = false;
		}

		if (radi) {
			int v = ps[3][j] + ps[1][r] + ps[2][r];
			if (v < bestv) {
				bestv = v;
				bestj = j;
			}
		}
	}

	if (bestj == -1) {
		cout << "-1\n";
		return 0;
	}

	cout << bestv << '\n';
}