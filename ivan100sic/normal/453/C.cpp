#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[100005], sol;
int a[100005], v[100005];

void dod(int x) {
	sol += x;
	a[x] ^= 1;
}

int root;

void dfs(int x) {
	dod(x);
	int chld = 0;
	v[x] = 1;
	for (int y : e[x]) {
		if (v[y]) continue;
		chld = y;
		dfs(y);
		dod(x);
		if (a[y]) {
			dod(y);
			dod(x);
		}
	}
	if (x == root && a[x]) {
		dod(chld);
		dod(x);
		dod(chld);
	}
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
		e[v] += u;
	}

	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1; i<=n; i++) {
		if (a[i]) {
			root = i;
			dfs(i);
			break;
		}
	}

	if (count(a+1, a+n+1, 1)) {
		cout << "-1\n";
	} else {
		cout << sol.size() << '\n';
		for (int x : sol)
			cout << x << ' ';
		cout << '\n';
	}
}