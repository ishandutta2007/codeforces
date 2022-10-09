// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, a[40005], b[40005], k;
int p[40005], q[40005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++)
		cin >> a[i], p[i+1] = p[i] + a[i];
	for (int j=0; j<m; j++)
		cin >> b[j], q[j+1] = q[j] + b[j];

	ll sol = 0;
	for (int x=1; x<=n; x++) {
		int y;
		if (k % x == 0 && (y = k / x) <= m) {
			int u=0, v=0;
			for (int i=0; i<=n-x; i++)
				u += p[i+x] - p[i] == x;
			for (int j=0; j<=m-y; j++)
				v += q[j+y] - q[j] == y;
			sol += u*1ll*v;
		}
	}

	cout << sol << '\n';
}

// I will still practice daily...