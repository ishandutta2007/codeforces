#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int c[1005];
int used[1005], uu = 1;

void no() {
	cout << "NO\n";
	exit(0);
}

int get(int x) {
	while (used[uu])
		uu++;
	if (uu >= x)
		no();
	used[uu] = 1;
	return uu;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		if (u > v)
			swap(u, v);
		if (v != n)
			no();
		if (u == n)
			no();
		c[u]++;
	}

	vector<pair<int, int>> sol;
	
	for (int i=1; i<n; i++) {
		if (c[i] == 0)
			continue;
		int take = c[i] - 1;

		int root = n;
		while (take--) {
			int tmp = get(i);
			sol.push_back({tmp, root});
			root = tmp;
		}
		used[i] = 1;
		sol.push_back({i, root});
	}

	cout << "YES\n";
	for (auto e : sol)
		cout << e.first << ' ' << e.second << '\n';
}