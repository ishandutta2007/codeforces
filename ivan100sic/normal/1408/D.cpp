// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
int a[2005], b[2005], c[2005], d[2005];

int fy[2000005];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i] >> b[i];
	for (int i=0; i<m; i++) cin >> c[i] >> d[i];

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (a[i] <= c[j] && b[i] <= d[j]) {
				int dx = c[j] - a[i] + 1;
				int dy = d[j] - b[i] + 1;
				mx(fy[dx-1], dy);
			}
		}
	}

	for (int i=2000003; i>=0; i--)
		mx(fy[i], fy[i+1]);

	int sol = 2e9;
	for (int i=0; i<2000004; i++)
		sol = min(sol, i + fy[i]);
	cout << sol << '\n';
}