#include <bits/stdc++.h>
using namespace std;

int n, root, q;
int p[100005][18];
int tip[100005];

int part[100005], spec[100005], dub[100005];

int lca(int a, int b) {
	if (dub[a] > dub[b]) {
		swap(a, b);
	}

	// svedi ih na istu
	for (int i=17; i>=0; i--) {
		if ((1<<i) <= (dub[b] - dub[a])) {
			b = p[b][i];
		}
	}

	if (a == b) {
		return a;
	}

	// trazi
	for (int i=17; i>=0; i--) {
		int aa = p[a][i];
		int bb = p[b][i];

		if (aa != bb) {
			a = aa;
			b = bb;
		}
	}

	return p[a][0];
}

// jeste sam sa sobom
bool is_spec(int u, int v) {
	if (p[u][17] != p[v][17]) {
		return false;
	}

	if (u == v) {
		return false;
	}

	int uv = lca(u, v);
	if (uv != u) {
		return false;
	}

	return spec[u] - spec[v] == dub[u] - dub[v];
}

bool is_part(int u, int v) {
	if (p[u][17] != p[v][17]) {
		return false;
	}

	if (u == v) {
		return false;
	}

	int uv = lca(u, v);	

	if (u == uv) {
		return part[u] - part[v] == dub[u] - dub[v];
	} else if (v == uv) {
		return false;
	} else {
		return 
			part[v] - part[uv] == dub[v] - dub[uv] &&
			spec[u] - spec[uv] == dub[u] - dub[uv];
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x, y;
		cin >> x >> y;
		if (x == -1) {
			for (int j=0; j<18; j++) {
				p[i][j] = i;
			}
			dub[i] = part[i] = spec[i] = 0;
		} else {
			p[i][0] = x;
			tip[i] = y;

			for (int j=1; j<18; j++) {
				p[i][j] = p[p[i][j-1]][j-1];
			}

			if (tip[i] == 0) {
				part[i] = part[x];
				spec[i] = spec[x] + 1;
			} else {
				part[i] = part[x] + 1;
				spec[i] = spec[x];
			}

			dub[i] = dub[x] + 1;
		}
	}

	cin >> q;
	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;

		if (t == 1) {
			if (is_spec(u, v)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}

		} else {
			if (is_part(u, v)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

}