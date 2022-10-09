#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s, p;
int a[5005][5005];
int b[5005][5005];
int c[5005][5005];

int r[5005], q[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> p;
	n = s.size();
	m = p.size();

	for (int i=n-1; i>=0; i--) {
		for (int j=n-1; j>=0; j--) {
			a[i][j] = a[i+1][j+1] + 1;
			if (s[i] != s[j])
				a[i][j] = 0;
		}
	}

	for (int i=m-1; i>=0; i--) {
		for (int j=m-1; j>=0; j--) {
			b[i][j] = b[i+1][j+1] + 1;
			if (p[i] != p[j])
				b[i][j] = 0;
		}
	}

	for (int i=n-1; i>=0; i--) {
		for (int j=m-1; j>=0; j--) {
			c[i][j] = c[i+1][j+1] + 1;
			if (s[i] != p[j])
				c[i][j] = 0;
		}
	}

	for (int i=0; i<n; i++) {
		// najmanje non-unique?
		int lo = 0;
		for (int j=0; j<n; j++)
			if (i != j)
				lo = max(lo, a[i][j]);
		r[i] = lo + 1;
	}

	for (int i=0; i<m; i++) {
		int lo = 0;
		for (int j=0; j<m; j++)
			if (i != j)
				lo = max(lo, b[i][j]);
		q[i] = lo + 1;
	}

	int sol = 123123123;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (c[i][j] >= r[i] && c[i][j] >= q[j]) {
				sol = min(sol, max(r[i], q[j]));
			}
		}
	}

	if (sol == 123123123)
		sol = -1;

	cout << sol << '\n';

}