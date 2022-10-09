// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int c[205];
basic_string<int> dep[205];
bool solved[205];

int solve(int c0) {
	memset(solved, 0, sizeof solved);
	int cc = 0, t = 0;
	while (cc < n) {
		bool found = false;
		for (int i=1; i<=n; i++) {
			if (c[i] != c0 || solved[i]) {
				continue;
			}

			// deps?
			bool ok = true;
			for (int d : dep[i]) {
				if (!solved[d]) {
					ok = false;
					break;
				}
			}

			if (ok) {
				found = true;
				t++;
				cc++;
				solved[i] = true;
				break;
			}
		}

		if (!found) {
			t++;
			c0 = c0%3 + 1;
		}
	}

	return t;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> c[i];
	for (int i=1; i<=n; i++) {
		int k;
		cin >> k;
		for (int j=0; j<k; j++) {
			int x;
			cin >> x;
			dep[i] += x;
		}
	}

	int sol = 1e9;

	for (int c0=1; c0<=3; c0++) {
		sol = min(sol, solve(c0));
	}

	cout << sol << '\n';
}