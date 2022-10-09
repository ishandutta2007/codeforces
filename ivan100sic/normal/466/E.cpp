#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, doc, pit;
int dsu[100005], ans[100005];
bool isroot[100005];
basic_string<int> e[100005];
basic_string<int> ubaci[100005], izbaci[100005];
basic_string<pair<int, int>> upiti[100005];

int ep(int x) {
	if (x == dsu[x])
		return x;
	return dsu[x] = ep(dsu[x]);
}

void spoji(set<int>& a, set<int>& b) {
	if (a.size() < b.size())
		swap(a, b);
	for (int x : b)
		a.insert(x);

}

set<int> dfs(int x) {
	set<int> br;
	for (int y : e[x]) {
		auto tmp = dfs(y);
		spoji(br, tmp);
	}
	for (int i : ubaci[x])
		br.insert(i);
	for (auto [i, id] : upiti[x])
		ans[id] = br.count(i);
	for (int i : izbaci[x])
		br.erase(i);
	return br;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	iota(dsu, dsu+n+1, 0);
	fill(isroot+1, isroot+n+1, true);
	for (int i=1; i<=m; i++) {
		int t, x, y;
		cin >> t >> x;
		if (t != 2)
			cin >> y;
		if (t == 1) {
			isroot[x] = false;
			dsu[x] = y;
			e[y] += x;
		} else if (t == 2) {
			y = ep(x);
			++doc;
			ubaci[x] += doc;
			izbaci[y] += doc;
		} else {
			++pit;
			upiti[x] += {y, pit};
		}
	}
	for (int i=1; i<=n; i++)
		if (isroot[i])
			dfs(i);
	for (int i=1; i<=pit; i++)
		cout << (ans[i] ? "YES\n" : "NO\n");
}