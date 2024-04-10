#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[100005];

int p[100005][17];
int dub[100005], idx[100005], dt;

void dfs1(int x, int pa) {
	p[x][0] = pa;
	idx[x] = ++dt;
	for (int i=1; i<17; i++)
		p[x][i] = p[p[x][i-1]][i-1];
	for (int y : e[x]) {
		if (y == pa)
			continue;
		dub[y] = dub[x] + 1;
		dfs1(y, x);
	}
}

int dizi(int x, int k) {
	for (int i=0; i<17; i++) {
		if (k & (1 << i)) {
			x = p[x][i];
		}
	}
	return x;
}

int lca(int x, int y) {
	if (dub[x] > dub[y])
		swap(x, y);
	y = dizi(y, dub[y] - dub[x]);
	if (x == y)
		return x;
	for (int i=16; i>=0; i--) {
		int xx = p[x][i], yy = p[y][i];
		if (xx != yy)
			x = xx, y = yy;
	}
	return p[x][0];
}

template<class A, class B>
int dfs2(int x, int& sol, A& e, B& mark) {
	int c = 0;
	for (int y : e[x]) {
		c += dfs2(y, sol, e, mark);
	}
	if (mark[x]) {
		sol += c;
		return 1;
	} else if (c > 1) {
		sol++;
		return 0;
	} else {
		return c;
	}
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

	dfs1(1, 1);

	int q;
	cin >> q;
	while (q--) {
		vector<int> a;
		int k;
		cin >> k;
		a.resize(k);
		for (int i=0; i<k; i++)
			cin >> a[i];
		sort(a.begin(), a.end(), [&](int x, int y) {
			return idx[x] < idx[y]; });

		vector<int> p, l;
		string mark;
		if (a[0] == 1) {
			p.resize(1);
			l.resize(1);
			mark.resize(1);
			p[0] = -1;
			l[0] = 0;
			mark[0] = 1;
		} else {
			p.resize(2);
			l.resize(2);
			mark.resize(2);
			p[0] = -1;
			l[0] = 0;
			mark[0] = 0;
			p[1] = 0;
			l[1] = dub[a[0]];
			mark[1] = 1;
		}
		int pos = p.size() - 1;

		for (int i=1; i<k; i++) {
			int z = lca(a[i-1], a[i]);
			int q = dub[a[i-1]] - dub[z];
			int r = dub[a[i]] - dub[z];

			while (pos) {
				if (l[pos] <= q) {
					q -= l[pos];
					pos = p[pos];
				} else {
					break;
				}
			}

			if (q) {
				int t = p.size();
				p.emplace_back();
				l.emplace_back();
				mark.push_back(0);
				p[t] = p[pos];
				l[t] = l[pos] - q;
				p[pos] = t;
				l[pos] = q;
				pos = t; // , q = 0
			}

			if (r > 0) {
				p.push_back(pos);
				l.push_back(r);
				mark.push_back(0);
				pos = p.size() - 1;
			}

			mark[pos] = 1;				
		}

		vector<vector<int>> e(p.size());
		bool ok = true;
		for (int i=1; i<(int)p.size(); i++) {
			// cerr << "grana " << i << ' ' << p[i] << ' ' << mark[i] << '\n';
			e[p[i]].push_back(i);
			if (mark[i] && mark[p[i]] && l[i] == 1)
				ok = false;
		}

		int sol = 0;
		dfs2(0, sol, e, mark);
		cout << (ok ? sol : -1) << '\n';
	}
}