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
		string s;
		cin >> s;
		int n = s.size();
		vector<vector<int>> z(3, vector<int>(n+1));
		for (int i=0; i<3; i++) {
			for (int j=0; j<n; j++) {
				z[i][j+1] = z[i][j];
				if (s[j] == '1' + i)
					z[i][j+1]++;
			}
		}

		auto ok = [&](int l, int r) {
			for (int i=0; i<3; i++)
				if (z[i][l] == z[i][r])
					return false;
			return true;
		};

		int r = 0, w = n+1;
		for (int l=0; l<n; l++) {
			while (r < n && !ok(l, r))
				r++;
			if (ok(l, r)) {
				w = min(w, r-l);
			}
		}

		cout << (w == n+1 ? 0 : w) << '\n';
	}
}