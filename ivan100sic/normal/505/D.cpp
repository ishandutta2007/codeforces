#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[100005], f[100005];
bool u[100005], inst[100005];
bool v[100005];
basic_string<int> w;

void dfs(int x) {
	w += x;
	v[x] = 1;
	for (int y : f[x]) {
		if (!v[y]) {
			dfs(y);
		}
	}
}

bool ok;

void topo(int x) {
	u[x] = 1;
	inst[x] = 1;
	for (int y : e[x]) {
		if (inst[y]) {
			ok = false;
		} else if (!u[y]) {
			topo(y);
		}
	}
	inst[x] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		f[u] += v;
		f[v] += u;
	}

	int sol = 0;

	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			w = {};
			dfs(i);
			ok = true;
			for (int x : w) {
				if (!u[x]) {
					topo(x);
				}
			}
			if (ok) {
				sol += w.size() - 1;
			} else {
				sol += w.size();
			}
		}
	}

	cout << sol << '\n';
}