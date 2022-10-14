#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;

struct edge {
	int to, i, cost;
	edge(int _to, int _i, int _cost) :
			to(_to), i(_i), cost(_cost) {
	}
};

int n, m, v, u, c;
vector<vector<edge>> g;
vector<int> in, topsort, order;

void sort(int mn) {
	in.assign(n + 1, 0);
	topsort.clear();
	for (int u = 1; u <= n; u++)
		for (auto& v : g.at(u))
			if (v.cost > mn)
				in[v.to]++;
	for (int u = 1; u <= n; u++)
		if (in.at(u) == 0)
			topsort.push_back(u);
	int pos = 0;
	while (pos < topsort.size()) {
		for (auto& u : g.at(topsort.at(pos++)))
			if (u.cost > mn)
				if (--in.at(u.to) == 0)
					topsort.push_back(u.to);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	g.resize(n + 1);
	in.resize(n + 1);
	order.resize(n + 1);
	int lo = 0, hi = 0, mid;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> c;
		g.at(u).emplace_back(v, i, c);
		if (hi < c)
			hi = c;
	}

	sort(0);
	if (topsort.size() == n) {
		cout << "0 0\n";
		return 0;
	}

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		sort(mid);
		if (topsort.size() == n) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	sort(hi);
	set<int> opt;
	for (int i = 0; i < n; i++)
		order.at(topsort.at(i)) = i;

	for (int u = 1; u <= n; u++)
		for (auto& v : g.at(u))
			if (order.at(u) > order.at(v.to))
				opt.insert(v.i);
	if (opt.size() == 0)
		hi = 0;
	cout << hi << " " << opt.size() << "\n";
	for (auto& i : opt)
		cout << i << " ";

}