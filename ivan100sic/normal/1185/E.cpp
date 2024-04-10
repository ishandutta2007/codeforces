#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n), b(n, string(m, '.'));
		for (int i=0; i<n; i++)
			cin >> a[i];

		char hi = '.';
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				hi = max(hi, a[i][j]);
		if (hi == '.') {
			cout << "YES\n0\n";
		} else {
			bool ok = true;
			vector<vector<int>> sol;
			for (char x='a'; x<=hi; x++) {
				int ilo = 123123, ihi = -123123;
				int jlo = 123123, jhi = -123123;
				for (int i=0; i<n; i++) {
					for (int j=0; j<m; j++) {
						if (a[i][j] == x) {
							ilo = min(ilo, i);
							ihi = max(ihi, i);
							jlo = min(jlo, j);
							jhi = max(jhi, j);							
						}
					}
				}
				if (ilo != 123123) {
					if (ihi != ilo && jhi != jlo) {
						ok = false;
					} else {
						sol.push_back({ilo, jlo, ihi, jhi});
						for (int i=ilo; i<=ihi; i++)
							for (int j=jlo; j<=jhi; j++)
								b[i][j] = x;
					}
				} else {
					sol.push_back({-1, -1, -1, -1});
				}
			}

			if (ok && a == b) {
				for (int i=(int)sol.size()-2; i>=0; i--) {
					if (sol[i][0] == -1) {
						sol[i] = sol[i+1];
					}
				}

				cout << "YES\n";
				cout << sol.size() << '\n';
				for (auto v : sol) {
					cout << v[0]+1 << ' ' << v[1]+1 << ' ' << v[2]+1
						<< ' ' << v[3]+1 << '\n';
				}

			} else {
				cout << "NO\n";
			}
		}
	}
}