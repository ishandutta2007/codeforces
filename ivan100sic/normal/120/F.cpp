#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
vector<int> e[105];
int d[105];

void dfs(int x, int p) {
	for (int y : e[x]) {
		if (y != p) {
			d[y] = d[x] + 1;
			dfs(y, x);
		}
	}
}

int main() {
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");

	int t, s=0;
	ifs >> t;
	while (t--) {
		ifs >> n;
		for (int i=1; i<=n; i++)
			e[i].clear();
		fill(d+1, d+n+1, 0);
		for (int i=1; i<n; i++) {
			int u, v;
			ifs >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1, 1);
		int a = max_element(d, d+n+1) - d;
		d[a] = 0;
		dfs(a, a);
		s += *max_element(d, d+n+1);
	}
	ofs << s << '\n';
}