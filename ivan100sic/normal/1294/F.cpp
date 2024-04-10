#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[200005];
int dn[200005], up[200005], p[200005];

void dfs1(int x, int p) {
	::p[x] = p;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs1(y, x);
		dn[x] = max(dn[x], dn[y] + 1);
	}
}

void dfs2(int x, int p) {
	multiset<int> vals;
	if (x != p)
		vals.insert(up[x] + 1);
	for (int y : e[x]) {
		if (y == p)
			continue;
		vals.insert(dn[y] + 1);
	}
	for (int y : e[x]) {
		if (y == p)
			continue;
		vals.erase(vals.find(dn[y] + 1));
		if (vals.size())
			up[y] = *vals.rbegin();
		vals.insert(dn[y] + 1);
	}
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs2(y, x);
	}
}

void dfs3(int x, int p, int cd, int& d, int& z) {
	if (cd > d)
		d = cd, z = x;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs3(y, x, cd+1, d, z);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}
	dfs1(1, 1);
	dfs2(1, 1);
	int sol = 0, xs = 0;
	for (int x=1; x<=n; x++) {
		multiset<int> sus;
		if (x != 1)
			sus.insert(up[x] + 1);
		for (int y : e[x]) {
			if (y == p[x])
				continue;
			sus.insert(dn[y] + 1);
		}
		if (sus.size() >= 3) {
			int t = 0;
			auto it = sus.rbegin();
			t += *it;
			it++;
			t += *it;
			it++;
			t += *it;
			if (t > sol)
				sol = t, xs = x;
		} else if (sus.size() == 2) {
			int t = accumulate(sus.begin(), sus.end(), 0);
			if (t > sol)
				sol = t, xs = x;
		}
	}
	cout << sol << '\n';
	vector<pair<int, int>> gg;
	for (int y : e[xs]) {
		int dub = -1, at = 0;
		dfs3(y, xs, 0, dub, at);
		gg.emplace_back(-dub, at);
	}
	sort(gg.begin(), gg.end());
	if (gg.size() == 2) {
		int t = 1;
		while (t == gg[0].second || t == gg[1].second)
			t++;
		cout << gg[0].second << ' ' << gg[1].second << ' ' << t << '\n';
	} else {
		for (int i=0; i<3; i++)
			cout << gg[i].second << ' ';
		cout << '\n';
	}
}