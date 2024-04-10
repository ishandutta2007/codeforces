#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
using namespace std;

vector<int> e[200005];
int c[200005];

int n, k;
int best_v, best_x;

int dfs(int x, int p) {
	int z = c[x];
	int v = 0;

	for (int y : e[x]) {
		if (y != p) {
			int zy = dfs(y, x);
			v = max(v, zy);
			z += zy;
		}
	}

	v = max(v, 2*k - z);

	if (v < best_v) {
		best_v = v;
		best_x = x;
	}

	return z;
}

void solve(int x, int p, vector<int>& v) {
	if (c[x]) {
		v.push_back(x);
	}

	for (int y : e[x]) {
		if (y != p) {
			solve(y, x, v);
		}
	}
}

void solve(int x) {

	vector<int> v;

	for (int y : e[x]) {
		solve(y, x, v);
	}

	if (c[x]) {
		v.push_back(x);
	}

	for (int i=0; i<k; i++) {
		cout << v[i] << ' ' << v[i+k] << ' ' << best_x << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i=0; i<2*k; i++) {
		int x;
		cin >> x;
		c[x] = 1;
	}

	best_v = 2*k;

	cerr << "here comes nothin\n";

	dfs(1, 1);

	cout << "1\n" << best_x << '\n';

	solve(best_x);

}