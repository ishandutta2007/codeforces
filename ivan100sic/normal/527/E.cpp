#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

multiset<int> e[100005];
int n, m;

list<int> dfs(int x) {
	list<int> v;
	while (e[x].size()) {
		int y = *e[x].begin();
		e[x].erase(e[x].begin());
		e[y].erase(e[y].find(x));
		v.push_back(y);
		x = y;
	}

	for (auto it = v.begin(); it != v.end(); ++it) {
		auto w = dfs(*it);
		v.splice(next(it), w);
	}

	return v;
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
		e[u].insert(v);
		e[v].insert(u);
	}

	int t = 0;
	for (int i=1; i<=n; i++) {
		if (e[i].size() % 2) {
			if (t) {
				e[t].insert(i);
				e[i].insert(t);
				t = 0;
				m++;
			} else {
				t = i;
			}
		}
	}

	if (m % 2) {
		m++;
		e[1].insert(1);
		e[1].insert(1);
	}
	cout << m << '\n';

	auto v = dfs(1);

	v.push_back(*v.begin());
	int q = 0;
	for (auto it = v.begin(); next(it) != v.end(); ++it) {
		if (q)
			cout << *it << ' ' << *next(it) << '\n';
		else
			cout << *next(it) << ' ' << *it << '\n';
		q ^= 1;
	}
}