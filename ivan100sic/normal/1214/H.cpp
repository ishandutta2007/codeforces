#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
basic_string<int> e[200005];
int up[200005], dn[200005], p[200005];

void dfs1(int x) {
	for (int y : e[x]) {
		if (y == p[x])
			continue;
		p[y] = x;
		dfs1(y);
		dn[x] = max(dn[x], dn[y] + 1);
	}
}

void dfs2(int x) {
	multiset<int> ms;
	ms.insert(-1);
	if (x != p[x])
		ms.insert(up[x]);
	for (int y : e[x]) {
		if (y == p[x])
			continue;
		ms.insert(dn[y]);
	}
	for (int y : e[x]) {
		if (y == p[x])
			continue;
		ms.erase(ms.find(dn[y]));
		up[y] = *ms.rbegin() + 1;
		ms.insert(dn[y]);
		dfs2(y);
	}
}

void dfs3(int x, vector<int>& c) {
	c[x] = x == p[x] ? 1 : c[p[x]] ^ 3;
	for (int y : e[x]) {
		if (y == p[x])
			continue;
		dfs3(y, c);
	}
}

void k2() {
	vector<int> c(n+1);
	dfs3(1, c);
	cout << "Yes\n";
	for (int i=1; i<=n; i++)
		cout << c[i] << " \n"[i == n];
}

vector<pair<int, int>> desc(int x) {
	vector<pair<int, int>> r;
	if (x == 1) {
		for (int y : e[x]) {
			r.emplace_back(dn[y] + 1, y);
		}
	} else {
		for (int y : e[x]) {
			if (y == p[x])
				continue;
			r.emplace_back(dn[y] + 1, y);
		}
		r.emplace_back(up[x] + 1, p[x]);
	}
	sort(r.begin(), r.end(), greater<pair<int, int>>());
	return r;
}

vector<pair<int, int>> ad[200005];

int ecc(int x) {
	int z = 0;
	for (auto [p, q] : ad[x])
		z = max(z, p);
	return z;
}

int sol[200005];

void dfs4(int x, int p, int c, int d) {
	// cerr << x << ' ' << p << ' ' << c << ' ' << d << "!\n";
	sol[x] = c;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs4(y, x, (c+d+k+k-1)%k+1, d);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	p[1] = 1;
	dfs1(1);
	dfs2(1);

	if (k == 2) {
		k2();
		return 0;
	}

	for (int i=1; i<=n; i++)
		ad[i] = desc(i);

	int c = 1, v = ecc(1);
	for (int i=2; i<=n; i++) {
		int z = ecc(i);
		if (z < v) {
			v = z;
			c = i;
		}
	}

	for (int i=1; i<=n; i++) {
		// ima resenja?
		if (ad[i].size() <= 2)
			continue;
		if (ad[i][1].first + ad[i][2].first >= k-1) {
			// zajeb
			cout << "No\n";
			return 0;
		}
	}

	sol[c] = 1;
	dfs4(ad[c][0].second, c, 2, 1);
	for (int i=1; i<(int)ad[c].size(); i++) {
		dfs4(ad[c][i].second, c, k, -1);
	}

	cout << "Yes\n";
	for (int i=1; i<=n; i++)
		cout << sol[i] << " \n"[i == n];

}