#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
string a[2005], at[2005];
int z[2005][2005], zt[2005][2005];

template<class T, class U>
void solve(T a, U z) {
	for (int i=0; i<n; i++) {
		int l=-1, r=-1;
		for (int j=0; j<n; j++) {
			if (a[i][j] == 'B') {
				r = j;
				if (l == -1)
					l = j;
			}
		}
		
		if (l == -1) {
			z[0][0] += 1;
		} else if (r-l+1 <= k) {
			int xl = max(0, i-k+1);
			int xr = min(n, i+1);
			int yl = max(0, r-k+1);
			int yr = min(n, l+1);

			z[xl][yl] += 1;
			z[xr][yr] += 1;
			z[xl][yr] -= 1;
			z[xr][yl] -= 1;
		}
	}

	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			z[i+1][j] += z[i][j];

	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			z[i][j+1] += z[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		at[i] = a[i];
	}
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			at[i][j] = a[j][i];
	solve(a, z);
	solve(at, zt);
	int h = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			h = max(h, z[i][j] + zt[j][i]);
	cout << h << '\n';
}