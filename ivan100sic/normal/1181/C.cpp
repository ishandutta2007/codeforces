#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[26][1005][1005], n, m;
int eqd[1005][1005];
string a[1005];

bool same(int p, int q, int r, int s) {
	auto d = c[a[p][q] - 'a'];
	return d[p][q] + d[r][s] - d[p][s] - d[r][q] == (r-p)*(s-q);
}

bool ok(int i, int j, int w, int r) {
	return same(i, j, i+w, j+r) && same(i+w, j, i+2*w, j+r) &&
		same(i+2*w, j, i+3*w, j+r) && a[i][j] != a[i+w][j] && a[i+w][j] != a[i+2*w][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		for (int j=0; j<m; j++) {
			c[a[i][j] - 'a'][i+1][j+1]++;
		}
	}

	for (int k=0; k<26; k++) {
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				c[k][i][j] += c[k][i-1][j];
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				c[k][i][j] += c[k][i][j-1];
	}

	for (int i=n-1; i>=0; i--) {
		for (int j=m-1; j>=0; j--) {
			eqd[i][j] = 1 + eqd[i+1][j];
			if (i == n-1 || a[i][j] != a[i+1][j])
				eqd[i][j] = 1;
		}
	}

	int z = 0;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int w = eqd[i][j];
			if (i+3*w > n)
				continue;

			int l = 1, r = m-j, o = 0;
			while (l <= r) {
				int mid = (l+r) >> 1;
				if (ok(i, j, w, mid)) {
					o = mid;
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}

			z += o;
		}
	}
	cout << z << '\n';
}