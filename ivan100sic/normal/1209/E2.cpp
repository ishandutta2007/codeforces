#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[12][2005], n, m;
bool u[12][2005];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				cin >> a[i][j];

		memset(u, 0, sizeof u);

		for (int i=0; i<n; i++) {
			vector<int> h(m);
			iota(h.begin(), h.end(), 0);
			int k = min(n, m);
			auto cmp = [&](int x, int y) {
				return a[i][x] > a[i][y];
			};
			nth_element(h.begin(), h.begin()+k, h.end(), cmp);
			h.resize(k);
			for (int x : h)
				u[i][x] = 1;
		}

		vector<int> ol(1<<n, -1e9);
		ol[0] = 0;

		for (int col=0; col<m; col++) {
			int mask = 0;
			for (int i=0; i<n; i++)
				if (u[i][col])
					mask |= 1 << i;
			if (mask == 0)
				continue;
			vector<int> nu = ol;
			vector<int> ins(1<<n, -1e9);
			for (int sm=mask; sm; sm=(sm-1)&mask) {
				int z = 0;
				for (int i=0; i<n; i++)
					if (sm & (1 << i))
						z += a[i][col];
				for (int i=0; i<n; i++) {
					int rot = ((sm | (sm << n)) >> i) & ((1 << n) - 1);
					mx(ins[rot], z);
				}
			}

			for (int rot=0; rot<(1<<n); rot++) {
				int z = ins[rot];
				if (z < 0)
					continue;
				int cmpl = (1<<n) - rot - 1;

				for (int l=cmpl; l; l=(l-1)&cmpl) {
					mx(nu[l | rot], ol[l] + z);
				}
				
				for (int l=0; l<1; l++) {
					mx(nu[l | rot], ol[l] + z);
				}
			}

			swap(ol, nu);
		}

		cout << ol[(1<<n)-1] << '\n';
	}
}