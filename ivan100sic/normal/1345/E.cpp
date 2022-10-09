// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
basic_string<int> e[200005], f[200005], o;
char v[200005];
int a[200005], b[200005];

void no() {
	cout << "-1\n";
	exit(0);
}

void dfs(int x) {
	v[x] = 2;
	for (int y : e[x]) {
		if (v[y] == 2) {
			no();
		} else if (v[y] == 0) {
			dfs(y);
		}
	}
	v[x] = 1;
	o += x;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		f[v] += u;
	}

	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			dfs(i);
		}
	}

	iota(a+1, a+n+1, 1);
	iota(b+1, b+n+1, 1);

	reverse(begin(o), end(o));
	for (int x : o) {
		for (int y : e[x]) {
			b[y] = min(b[y], b[x]);
		}
	}

	reverse(begin(o), end(o));
	for (int x : o) {
		for (int y : f[x]) {
			a[y] = min(a[y], a[x]);
		}
	}

	string sol;
	for (int i=1; i<=n; i++) {
		sol += (a[i] == i && b[i] == i ? "A" : "E");
	}

	cout << count(begin(sol), end(sol), 'A') << '\n' << sol << '\n';
}