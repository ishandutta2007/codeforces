#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int mr[50505], p[50505];
int idx;

int solve(int n, int r) {
	if (r < mr[n] || r > n*(n+1)/2)
		return -1;

	if (n == 0)
		return 0;

	r -= n;
	int root = ++idx;
	for (int j=0; j<n; j++) {
		int k = n-j-1;
		if (mr[j] + mr[k] <= r && r <= j*(j+1)/2 + k*(k+1)/2) {
			// r = r1 + r2
			int r1 = mr[j];
			int r2 = r - mr[j];
			if (r2 > k*(k+1)/2) {
				int delta = r2 - k*(k+1) / 2;
				r1 += delta;
				r2 -= delta;
			}

			int lc = solve(j, r1);
			int rc = solve(k, r2);

			p[lc] = root;
			p[rc] = root;
			return root;
		}
	}
	return root;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;

	for (int i=1; i<=5555; i++) {
		mr[i] = mr[(i-1)/2] + mr[(i-1) - (i-1)/2] + i;
		// cerr << i << ' ' << mr[i] << '\n';
	}

	while (t--) {
		int n, r;
		cin >> n >> r;
		idx = 0;
		r += n;
		if (solve(n, r) != -1) {
			cout << "YES\n";
			for (int i=2; i<=n; i++)
				cout << p[i] << " \n"[i == n];
		} else {
			cout << "NO\n";
		}
	}
}