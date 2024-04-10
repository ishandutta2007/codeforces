// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, l;
basic_string<int> f[200005], p;
basic_string<int> e[200005];
int d[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		f[v] += u;
		e[u] += v;
	}

	cin >> l;
	for (int i=0; i<l; i++) {
		int x;
		cin >> x;
		p += x;
	}

	{
		memset(d, 0xff, sizeof d);
		basic_string<int> q = {p[l-1]};
		d[p[l-1]] = 0;
		size_t qs = 0;
		while (qs != q.size()) {
			int x = q[qs++];
			for (int y : f[x]) {
				if (d[y] == -1) {
					d[y] = d[x] + 1;
					q += y;
				}
			}
		}
	}

	// najmanji broj, greedy?
	int c = 0;
	for (int i=1; i<l; i++) {
		int x = p[i];
		int y = p[i-1];
		if (d[x] >= d[y]) {
			c++;			
		}
	}
	cout << c << ' ';

	// najveci broj, nesto idk
	c = 0;
	for (int i=1; i<l; i++) {
		int x = p[i];
		int y = p[i-1];
		// ako postoji zaobilazni najkraci put iz y
		int ok = 0;
		for (int z : e[y]) {
			if (d[z] == d[y] - 1 && z != x) {
				ok = 1;
			}
		}
		c += ok;
	}

	cout << c << "\n";
}

// I will still practice daily...