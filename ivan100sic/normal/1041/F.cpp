#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, junk, m;
int a[100005], b[100005], govno[100005];

int c[1 << 20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> junk;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> m >> junk;
	for (int i=0; i<m; i++)
		cin >> b[i];

	int sol = 0;

	if (set_intersection(a, a+n, b, b+m, govno) != govno)
		sol = 2;

	for (unsigned d=1; d!=(1u<<31); d <<= 1) {
		if (d <= (1u << 19)) {
			for (int i=0; i<n; i++)
				sol = max(sol, ++c[a[i] & (2*d-1)]);
			for (int i=0; i<m; i++)
				sol = max(sol, ++c[(b[i]+d) & (2*d-1)]);

			for (int i=0; i<n; i++)
				c[a[i] & (2*d-1)] = 0;
			for (int i=0; i<m; i++)
				c[(b[i]+d) & (2*d-1)] = 0;
		} else {
			if (1000000000 / (int)d + 1 < sol)
				break;

			map<int, int> c;
			for (int i=0; i<n; i++)
				sol = max(sol, ++c[a[i] & (2*d-1)]);
			for (int i=0; i<m; i++)
				sol = max(sol, ++c[(b[i]+d) & (2*d-1)]);
		}
	}

	cout << sol << '\n';
}