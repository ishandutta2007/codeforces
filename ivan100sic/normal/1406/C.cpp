// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
vector<basic_string<int>> e;
int sz[100005], p[100005], l[100005], r[100005], dt;

void dfs(int x) {
	sz[x] = 1;
	l[x] = dt++;
	for (int y : e[x]) {
		if (y != p[x]) {
			p[y] = x;
			dfs(y);
			sz[x] += sz[y];
		}
	}
	r[x] = dt;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		// hahahahahah
		dt = 0;
		e.resize(n+1);
		for (int i=0; i<=n; i++) e[i].clear();

		for (int i=1; i<n; i++) {
			int x, y;
			cin >> x >> y;
			e[x] += y;
			e[y] += x;
		}

		int rt = 1;
		while (e[rt].size() == 1) rt++;

		p[rt] = rt;
		dfs(rt);
		int j = -1;
		for (int i=1; i<=n; i++) {
			if (sz[i]*2 == n) {
				j = i;
			}
		}

		if (j == -1) {
			cout << "1 " << e[1][0] << '\n';
			cout << "1 " << e[1][0] << '\n';
		} else {
			int f = -1;
			for (int k=1; k<=n; k++) {
				if (sz[k] == 1 && !(l[j] <= l[k] && r[k] <= r[j])) {
					f = k;
				}
			}
			cout << f << ' ' << p[f] << '\n';
			cout << f << ' ' << j << '\n';
		}
	}
}