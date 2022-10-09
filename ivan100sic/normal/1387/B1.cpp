// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
basic_string<int> e[100005];
int a[100005], cost;

void dfs(int x, int p) {
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs(y, x);
		if (a[y] == y) {
			// popni ga gore
			swap(a[x], a[y]);
			cost += 2;
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	for (int i=1; i<=n; i++)
		a[i] = i;

	dfs(1, 1);
	if (a[1] == 1) {
		int y = e[1][0];
		swap(a[1], a[y]);
		cost += 2;
	}


	cout << cost << '\n';
	for (int i=1; i<=n; i++) {
		cout << a[i] << " \n"[i == n];
	}
}