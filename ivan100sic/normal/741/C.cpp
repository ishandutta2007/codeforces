#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> e[200005];
int x[100005], y[100005];
int n, f[200005];

void dfs(int x, int p, int c) {
	f[x] = c;
	for (int y : e[x]) {
		if (y != p && !f[y]) {
			dfs(y, x, 3-c);
		}
	}
}

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		int u, v;
		cin >> u >> v;
		x[i] = u;
		y[i] = v;
		e[u].push_back(v);
		e[v].push_back(u);

		int a = 2*i-1;
		int b = 2*i;

		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (int i=1; i<=2*n; i++) {
		if (f[i] == 0) {
			dfs(i, i, 1);
		}
	}
	for (int i=1; i<=n; i++) {
		cout << f[x[i]] <<  ' ' << f[y[i]] << '\n';
	}
}