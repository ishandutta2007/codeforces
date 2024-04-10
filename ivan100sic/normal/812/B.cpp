#include <bits/stdc++.h>
using namespace std;

int n, m;
int l[26], r[26];

int dl[26], dr[26], www;

void of(int& x, int y) {
	if (y < x) {
		x = y;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=n; i>=1; i--) {
		string s;
		cin >> s;
		for (int j=1; j<=m; j++) {
			if (s[j] == '1') {
				l[i] = l[i] ? l[i] : j;
				r[i] = j;
				www = max(www, i);
			}				
		}
	}

	dl[1] = 0;
	dr[1] = m+1;

	fill(dl+2, dl+n+1, 1e9);
	fill(dr+2, dr+n+1, 1e9);

	for (int i=1; i<n; i++) {
		if (r[i]) {
			// LL
			of(dl[i+1], dl[i] + 1 + 2 * r[i]);
			// LR
			of(dr[i+1], dl[i] + m + 2);
			// RL
			of(dl[i+1], dr[i] + m + 2);
			// RR
			of(dr[i+1], dr[i] + 1 + 2 * (m + 1 - l[i]));
		} else {
			of(dl[i+1], dl[i] + 1);
			of(dr[i+1], dr[i] + 1);

			of(dr[i+1], dl[i] + m + 2);
			of(dl[i+1], dr[i] + m + 2);
		}

	}

	for (int i=1; i<=n; i++) {
		cerr << i << ' ' << dl[i] << ' ' << dr[i] << ' ' << l[i] << ' ' << r[i] << '\n';
	}

	int sol = min(dl[www] + r[www], dr[www] + (m + 1 - l[www]));

	cout << sol;
}