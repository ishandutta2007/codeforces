#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string a[500005];
int rs[500005], cs[500005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=0; i<n; i++)
			cin >> a[i];
		fill(rs, rs+n, 0);
		fill(cs, cs+m, 0);
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++) {
				int x = a[i][j] == '*';
				rs[i] += x;
				cs[j] += x;
			}
		int sol = 123131321;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				int t = rs[i] + cs[j] - (a[i][j] == '*');
				sol = min(sol, n+m-1-t);
			}
		}
		cout << sol << '\n';
	}
}