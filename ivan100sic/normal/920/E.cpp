#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

set<int> u, e[200005];
int n, m;

int dfs(int x) {
	u.erase(x);
	int y = 0, z = 1;
	while (1) {
		auto it = u.upper_bound(y);
		if (it == u.end())
			return z;
		y = *it;
		if (!e[x].count(y))
			z += dfs(y);
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		u.insert(i);
	for (int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].insert(y);
		e[y].insert(x);
	}
	vector<int> s;

	for (int i=1; i<=n; i++) {
		if (u.count(i)) {
			s.push_back(dfs(i));
		}
	}

	cout << s.size() << '\n';
	sort(s.begin(), s.end());
	for (int x : s)
		cout << x << ' ';
	cout << '\n';

}