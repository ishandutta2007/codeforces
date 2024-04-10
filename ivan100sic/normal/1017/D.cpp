#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, q;
int w[12];
int c[4096];

int r[4096][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=0; i<n; i++)
		cin >> w[i];

	reverse(w, w+n);

	for (int i=0; i<m; i++) {
		string s;
		cin >> s;
		int mask = 0;
		for (char x : s)
			mask = 2*mask + (x - '0');
		c[mask]++;
	}

	// resi unapred
	for (int i=0; i<(1<<n); i++) {
		for (int j=0; j<(1<<n); j++) {

			int it = i, jt = j, wt = 0;

			for (int k=0; k<n; k++) {
				if (((it ^ jt) & 1) == 0)
					wt += w[k];
				it >>= 1;
				jt >>= 1;
			}

			if (wt <= 100)
				r[j][wt] += c[i];
		}
	}

	for (int i=0; i<(1<<n); i++)
		for (int j=1; j<=100; j++)
			r[i][j] += r[i][j-1];

	// radi
	for (int i=0; i<q; i++) {
		string s;
		cin >> s;
		int k;
		cin >> k;
		int mask = 0;
		for (char x : s)
			mask = 2*mask + (x - '0');
		cout << r[mask][k] << '\n';
	}
}