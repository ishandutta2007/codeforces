#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class A, class B, class C>
void dfs(int x, A& e, B& vis, C& rez) {
	rez += x;
	vis[x] = 1;
	for (int y : e[x])
		if (!vis[y])
			dfs(y, e, vis, rez);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		vector<tuple<int, int, int>> tri;
		map<array<int, 3>, int> idx;
		cin >> n;
		set<pair<int, int>> ee;

		auto xr = [&](int x, int y) {
			if (x > y)
				swap(x, y);
			if (ee.count({x, y}))
				ee.erase({x, y});
			else
				ee.insert({x, y});
		};

		for (int i=0; i<n-2; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			tri.emplace_back(a, b, c);
			xr(a, b);
			xr(b, c);
			xr(c, a);

			array<int, 3> w = {a, b, c};
			sort(w.begin(), w.end());
			idx[w] = i+1;
		}

		set<pair<int, int>> pq;
		vector<set<int>> adj(n+1);
		vector<basic_string<int>> e(n+1);

		for (auto [a, b, c] : tri) {
			adj[a].insert(b);
			adj[a].insert(c);
			adj[b].insert(c);
			adj[b].insert(a);
			adj[c].insert(a);
			adj[c].insert(b);
		}

		for (int i=1; i<=n; i++)
			pq.insert({adj[i].size(), i});

		for (auto [x, y] : ee)
			e[x] += y, e[y] += x;

		string vis(n+1, 0);
		basic_string<int> rez, sol;
		dfs(1, e, vis, rez);

		for (int x : rez)
			cout << x << ' ';
		cout << '\n';

		auto decr = [&](int a, int b) {
			auto it = pq.find({adj[b].size(), b});
			if (it == pq.end())
				return;
			pq.erase(it);
			adj[b].erase(a);
			if (adj[b].size())
				pq.insert({adj[b].size(), b});
		};

		while (pq.size()) {
			auto it = pq.begin();
			auto [x, y] = *it;
			if (x < 2)
				break;
			pq.erase(it);

			int a = y;
			int b = *adj[y].begin();
			int c = *next(adj[y].begin());

			array<int, 3> w = {a, b, c};
			sort(w.begin(), w.end());
			sol.push_back(idx[w]);

			decr(a, b);
			decr(a, c);
		}

		for (int x : sol)
			cout << x << ' ';
		cout << '\n';
	}	
}