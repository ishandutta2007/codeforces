// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int d[5005];
bool u[5005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	d[0] = 0;
	for (int k=1; k<=5000; k++) {
		memset(u, 0, sizeof u);
		for (int j=0; j<k; j++) {
			int l = max(0, j-1);
			int r = max(0, k-j-2);
			u[d[l] ^ d[r]] = 1;
		}
		while (u[d[k]]) d[k]++;
	}

	string s;
	vector<pair<int, int>> v;

	cin >> s;
	int n = s.size();
	int l = -1, r = -1;
	for (int i=1; i+1<n; i++) {
		if (s[i-1] == s[i+1]) {
			if (l == -1) {
				l = i;
			}
			r = i+1;
		} else {
			if (l != -1) {
				v.emplace_back(l, r);
				l = r = -1;
			}
		}
	}

	if (l != -1) {
		v.emplace_back(l, r);
	}

	int g = 0;
	for (auto [l, r] : v) {
		// cerr << "grupa " << l << ' ' << r << ' ' << d[r-l] << '\n';
		g ^= d[r-l];
	}

	if (g == 0) {
		cout << "Second\n";
	} else {
		cout << "First\n";
		for (auto [l, r] : v) {
			int k = r-l;
			for (int j=0; j<k; j++) {
				int u = max(0, j-1);
				int v = max(0, k-j-2);
				if (!(d[u] ^ d[v] ^ d[k] ^ g)) {
					cout << l+j+1 << '\n';
					return 0;
				}
			}
		}
	}

}