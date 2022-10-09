#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 2048;

struct node {
	int pref, suff, any, len;
	
	node operator+ (const node& b) const {
		return {
			pref + (pref == len ? b.pref : 0),
			b.suff + (b.suff == b.len ? suff : 0),
			max({any, b.any, suff + b.pref}),
			len + b.len
		};
	}
};

node single(int x) {
	return {x, x, x, 1};
}

struct seg {
	vector<node> b;

	seg() : b(2*maxn, single(0)) {}

	void update(int x, int y) {
		x += maxn;
		b[x] = single(y);
		while (x > 1) {
			x >>= 1;
			b[x] = b[2*x] + b[2*x+1];
		}
	}

	int query() {
		return b[1].any;
	}
};

struct solver {

	vector<int> a;
	int val;
	vector<vector<pair<int, int>>> ch;
	seg tree;
	vector<vector<int>> hasval;

	solver(vector<int> a) : a(a), val(maxn-1), ch(maxn), hasval(maxn) {
		for (int i=0; i<(int)a.size(); i++)
			hasval[a[i]].push_back(i);
	}

	void add_change(int t, int x, int v) {
		ch[t].emplace_back(x, v);
	}

	vector<int> solve(int k) {
		vector<int> w(k);
		for (int i=0; i<k; i++) {
			// uradi sve registrovane izmene
			for (auto [x, v] : ch[i]) {
				if (a[x] >= val && v < val)
					tree.update(x, 0);
				a[x] = v;
				hasval[a[x]].push_back(x);
			}
			// spusti stablo sve dok ne valja
			while (tree.query() < val) {
				val--;
				for (int i : hasval[val]) {
					if (a[i] == val) {
						tree.update(i, 1);
					}
				}
			}
			w[i] = val;
		}
		return w;
	}
};

int n, m, k;
string a[2005];
int v[2005][2005];
vector<tuple<int, int, int>> ch[2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (i == 0)
				v[i][j] = 1;
			else
				v[i][j] = v[i-1][j] + 1;
			if (a[i][j] == 'X')
				v[i][j] = 0;
		}
	}

	for (int i=0; i<k; i++) {
		int x0, y0;
		cin >> x0 >> y0;
		x0--, y0--;
		for (int x=x0; x<n; x++) {
			if (a[x][y0] == 'X')
				break;
			ch[x].emplace_back(i, y0, x-x0);
		}
		a[x0][y0] = 'X';
	}

	vector<int> sol(k, 0);

	for (int i=0; i<n; i++) {
		solver eng(vector<int>(v[i], v[i]+m));
		for (auto [t, x, v] : ch[i])
			eng.add_change(t, x, v);
		auto w = eng.solve(k);
		for (int j=0; j<k; j++)
			sol[j] = max(sol[j], w[j]);
	}

	for (int i=0; i<k; i++)
		cout << sol[i] << '\n';
}