#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[100009];
int d[100009];

void dfs(int n, int p)
{
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (tn == p) continue;
		d[tn] = d[n] + 1;
		dfs(tn, n);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, a, b, da, db; cin >> n >> a >> b >> da >> db;
		for (int i = 1; i <= n; i++)
			v[i].clear();
		for (int i = 0; i < n - 1; i++) {
			int p, q; cin >> p >> q;
			v[p].push_back(q); v[q].push_back(p);
		}
		if (db < da * 2 + 1) {
			cout << "Alice" << '\n';
			continue;
		}
		d[a] = 0;
		dfs(a, -1);
		if (d[b] <= da) {
			cout << "Alice" << '\n';
			continue;
		}
		int mi = 1;
		for (int i = 1; i <= n; i++)
			if (d[mi] < d[i])
				mi = i;
		d[mi] = 0;
		dfs(mi, -1);
		int ds = 0;
		for (int i = 1; i <= n; i++)
			ds = max(ds, d[i]);
		ds = (ds + 1) / 2;
		if (ds <= da) {
			cout << "Alice" << '\n';
			continue;
		}
		cout << "Bob" << '\n';
	}
	return 0;
}