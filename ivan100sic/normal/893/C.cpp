// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
basic_string<int> e[100005];
bool v[100005];
int c[100005];

int w;
void dfs(int x) {
	w = min(w, c[x]);
	v[x] = 1;
	for (int y : e[x]) {
		if (!v[y]) {
			dfs(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> c[i];
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	ll z = 0;
	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			w = c[i];
			dfs(i);
			z += w;
		}
	}

	cout << z << '\n';
}