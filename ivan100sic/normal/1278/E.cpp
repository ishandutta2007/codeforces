#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[500005], ans[500005];

list<int> dfs(int x, int p) {
	list<int> t;
	list<int>::iterator it;
	for (int y : e[x]) {
		if (y == p)
			continue;
		auto z = dfs(y, x);
		if (t.empty()) {
			t = move(z);
			it = prev(t.end());
		} else {
			auto nit = next(it);
			t.splice(it, z);
			it = prev(prev(nit));
		}
	}
	if (t.empty()) {
		t.push_front(x);
		t.push_front(x);
	} else {
		t.insert(it, x);
		t.push_back(x);
	}
	return t;
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
		e[u] += v;
		e[v] += u;
	}

	auto v = dfs(1, 1);
	int j = 1;
	for (int x : v)
		ans[x] += j++;
	for (int i=1; i<=n; i++)
		cout << ans[i][0] << ' ' << ans[i][1] << '\n';
}