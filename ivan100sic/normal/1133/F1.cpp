#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
size_t qs;
basic_string<int> e[200005], q;
int vis[200005];

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

	int root = 1;
	for (int i=2; i<=n; i++)
		if (e[i].size() > e[root].size())
			root = i;

	q += root;
	vis[root] = 1;
	while (qs != q.size()) {
		int x = q[qs++];
		for (int y : e[x]) {
			if (!vis[y]) {
				vis[y] = 1;
				cout << x << ' ' << y << '\n';
				q += y;
			}
		}
	}

}