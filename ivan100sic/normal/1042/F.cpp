#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
vector<int> e[1000005];
int sol = 0;

struct dumb_set {
	int extra;
	multiset<int> v;
};

void mergee(dumb_set& a, dumb_set& b) {
	if (a.v.size() < b.v.size()) {
		swap(a.v, b.v);
		swap(a.extra, b.extra);
	}

	for (int x : b.v) {
		a.v.insert(x - a.extra + b.extra);
	}
}

dumb_set dfs(int x, int p) {

	dumb_set ja;
	if (e[x].size() == 1) {
		ja.extra = 0;
		ja.v = {0};
		return ja;
	}

	for (int y : e[x]) {
		if (y != p) {
			dumb_set t = dfs(y, x);
			mergee(ja, t);
		}
	}

	ja.extra++; // povecaj svima dubinu za 1

	/*
	cerr << x << " set: ";
	for (int x : ja.v)
		cerr << x + ja.extra << ' ';
	cerr << '\n';
	*/
	
	if (ja.v.size() <= 1) {
		return ja;
	}

	// mogu da spojim sve
	if (*prev(ja.v.end()) + *prev(prev(ja.v.end())) + 2*ja.extra <= k) {
		dumb_set tmp;
		tmp.extra = 0;
		tmp.v = {ja.extra + *prev(ja.v.end())};
		return tmp;
	}

	// ne mogu ni prva dva da spojim
	if (*ja.v.begin() + *next(ja.v.begin()) + 2*ja.extra > k) {
		return ja;
	}

	// mogu prvih bla
	auto it1 = ja.v.begin();
	auto it2 = next(it1);

	while (1) {
		if (next(it2) != ja.v.end() && *it2 + *next(it2) + 2*ja.extra <= k) {
			++it1;
			++it2;
		} else {
			auto it = ja.v.begin();
			auto nit2 = next(it2);
			int dodaj = *it2;
			while (it != nit2) {
				it = ja.v.erase(it);
			}
			ja.v.insert(dodaj);
			return ja;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	int root = 1;
	while (e[root].size() == 1)
		root++;

	auto ja = dfs(root, root);

	/*
	cerr << root << " set: ";
	for (int x : ja.v)
		cerr << x + ja.extra << ' ';
	cerr << '\n';
	*/

	sol += ja.v.size();

	cout << sol << '\n';
}