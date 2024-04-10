#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
basic_string<int> e[250005], backedges[250005];
int parent[250005], dubina[250005], br_dece[250005];

void dfs(int x) {
	for (int y : e[x]) {
		if (dubina[y]) {
			if (y != parent[x]) {
				backedges[x] += y;
			}
		} else {
			br_dece[x] += 1;
			parent[y] = x;
			dubina[y] = dubina[x] + 1;
			dfs(y);
		}
	}
}

basic_string<int> get_path(int x, int y) {
	basic_string<int> v;
	for (; x != y; x = parent[x])
		v += x;
	v += y;
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dubina[1] = 1;
	dfs(1);

	for (int i=1; i<=n; i++) {
		if (dubina[i] * 1ll * k >= n) {
			cout << "PATH\n";
			auto v = get_path(i, 1);
			cout << v.size() << '\n';
			for (int x : v)
				cout << x << ' ';
			cout << '\n';
			return 0;
		}
	}

	// ciklusi
	cout << "CYCLES\n";
	for (int i=1; i<=n; i++) {
		if (br_dece[i] == 0) {
			int u = backedges[i][0];
			int v = backedges[i][1];

			if (dubina[u] < dubina[v])
				swap(u, v);

			basic_string<int> w;
			if ((dubina[i] - dubina[u] + 1) % 3) {
				w = get_path(i, u);
			} else if ((dubina[i] - dubina[v] + 1) % 3) {
				w = get_path(i, v);
			} else {
				w = get_path(u, v);
				w += i;
				reverse(w.begin(), w.end());
			}

			cout << w.size() << '\n';
			for (int x : w)
				cout << x << ' ';
			cout << '\n';

			k--;
			if (k == 0)
				return 0;
		}
	}

}