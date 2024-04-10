#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void mx(int& x, int y) {
	x = max(x, y);
}

struct grana {
	int v;
	char c;
};

vector<int> masks = {0};
int n;
basic_string<grana> e[500005];
int ans[500005], val[500005], dub[500005];

int h[500005], p[500005];

struct buffer {
	vector<pair<int, int>> a;
	int ts;

	buffer() : a(1 << 22), ts(1) {}

	int operator[] (int x) {
		return a[x].second == ts ? a[x].first : -123123123;
	}

	void add(int x, int y) {
		if (a[x].second == ts) {
			mx(a[x].first, y);
		} else {
			a[x] = {y, ts};
		}
	}

	void reset() {
		ts++;
	}
} b;

int dfs1(int x) {
	int z = -1, h = -1, s = 1;
	for (auto [y, c] : e[x]) {
		val[y] = val[x] ^ (1 << (c - 'a'));
		dub[y] = dub[x] + 1;
		int t = dfs1(y);
		s += t;
		if (t > z) {
			z = t;
			h = y;
		}
	}
	::h[x] = h;
	return s;
}

void dfs4(int x, vector<int>& novi) {
	novi.emplace_back(x);
	for (auto [y, c] : e[x])
		dfs4(y, novi);
}

void dfs3(int x) {
	if (h[x] != -1) {
		dfs3(h[x]);
	}

	for (auto [y, c] : e[x]) {
		if (y != h[x]) {
			vector<int> novi;
			dfs4(y, novi);
			for (int j : masks)
				for (int p : novi)
					mx(ans[x], dub[p] + b[j ^ val[p]] - 2 * dub[x]);
			for (int p : novi)
				b.add(val[p], dub[p]);
		}
	}

	// cerr << "here i stand " << x << ' ' << val[x] << ' ' << dub[x] << '\n';
	b.add(val[x], dub[x]);

	for (int j : masks)
		mx(ans[x], b[j ^ val[x]] - dub[x]);
}

void dfs2(int x) {
	b.reset();
	dfs3(x);

	for (int z=x; z!=-1; z=h[z]) {
		for (auto [t, c] : e[z]) {
			if (t != h[z]) {
				dfs2(t);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<22; i++)
		masks.push_back(1 << i);

	cin >> n;
	for (int i=2; i<=n; i++) {
		int p;
		char c;
		cin >> p >> c;
		e[p] += {i, c};
	}

	// hld
	dfs1(1);

	// for (int i=1; i<=n; i++) {
	// 	cerr << "heavy " << i << ' ' << h[i] << '\n';
	// }

	// solve
	dfs2(1);

	for (int i=n; i>=1; i--)
		for (auto [j, c] : e[i])
			mx(ans[i], ans[j]);

	for (int i=1; i<=n; i++)
		cout << ans[i] << " \n"[i == n];
}