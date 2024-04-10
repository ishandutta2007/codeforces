#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
int tip[100005];
int fc[100005], cc;
basic_string<pair<int, int>> e[100005];
int d[505][505];

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	{
		int u = 0;
		for (int i=1; i<=k; i++) {
			int c;
			cin >> c;
			for (int j=u+1; j<=u+c; j++)
				tip[j] = i;
			u += c;
		}
	}

	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u] += {v, w};
		e[v] += {u, w};
	}

	for (int i=1; i<=n; i++) {
		if (fc[i] == 0) {
			basic_string<int> q;
			fc[i] = ++cc;
			q += i;
			size_t qs = 0;
			while (qs != q.size()) {
				int x = q[qs++];
				for (auto [y, z] : e[x]) {
					if (z)
						continue;
					if (fc[y])
						continue;
					fc[y] = cc;
					q += y;
				}
			}
		}
	}

	for (int i=1; i<=n; i++) {
		if (tip[i] == tip[i-1]) {
			if (fc[i] != fc[i-1]) {
				cout << "No\n";
				return 0;
			}
		}
	}

	memset(d, 63, sizeof(d));
	for (int i=1; i<=k; i++)
		d[i][i] = 0;

	cout << "Yes\n";
	for (int x=1; x<=n; x++) {
		for (auto [y, z] : e[x]) {
			mn(d[tip[x]][tip[y]], z);
		}
	}

	for (int x=1; x<=k; x++)
		for (int y=1; y<=k; y++)
			for (int z=1; z<=k; z++)
				mn(d[y][z], d[y][x] + d[x][z]);

	for (int i=1; i<=k; i++)
		for (int j=1; j<=k; j++)
			cout << (d[i][j] == 1061109567 ? -1 : d[i][j]) << " \n"[j == k];
}