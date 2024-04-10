#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int H = 300005;

struct node {
	int nx[26];
} b[3*H]; int sz;

int n;
vector<pair<int, int>> e[H];
int h[H], d[H], s[H], ans[H], sol[H];
bool dete[H];

void dfs1(int x) {
	int w = -1;
	s[x] = 1;
	for (auto [y, c] : e[x]) {
		d[y] = d[x] + 1;
		dfs1(y);
		s[x] += s[y];
		if (s[y] > w) {
			w = s[y];
			h[x] = y;
		}
	}
}

int newnode() {
	sz++;
	memset(b+sz, 0, sizeof b[0]);
	return sz;
}

// x je nenula
void dfs3(int& r, int x) {
	if (!r)
		r = newnode();
	for (auto [y, c] : e[x])
		dfs3(b[r].nx[c], y);
}

// x je nenula
int dfs4(int x) {
	int r = 0;
	dfs3(r, x);
	return r;
}

int velicina(int r) {
	if (!r)
		return 0;
	int z = 1;
	for (int i=0; i<26; i++)
		z += velicina(b[r].nx[i]);
	return z;
}

int preklop(int r1, int r2) {
	if (!r1 || !r2)
		return 0;
	int zz = 1;
	for (int i=0; i<26; i++)
		zz += preklop(b[r1].nx[i], b[r2].nx[i]);
	return zz;
}

int dfs2(int x) {
	if (!h[x])
		return newnode();
	int hr = dfs2(h[x]);
	int hehe = 0;
	for (auto [y, c] : e[x]) {
		if (y != h[x]) {
			dfs3(hehe, y);
		}
	}

	int s1 = s[h[x]];
	int s2 = velicina(hehe); 
	int s12 = preklop(hr, hehe);

	// cerr << "burazz " << x << ' ' << s1 << ' ' << s2 << ' ' << s12 << '\n';

	ans[x] = s1 + s2 - s12;

	int r = newnode();
	for (auto [y, c] : e[x])
		b[r].nx[c] = (y == h[x] ? hr : dfs4(y));
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		e[u].emplace_back(v, c-'a');
	}

	dfs1(1);
	for (int i=1; i<=n; i++)
		dete[h[i]] = 1;
	for (int i=1; i<=n; i++) {
		if (!dete[i]) {
			sz = 0;
			dfs2(i);
		}
	}

	// for (int i=1; i<=n; i++) {
	// 	cerr << "info " << i << ' ' << ans[i] << '\n';
	// }

	fill(sol, sol+n, n);
	for (int i=1; i<=n; i++)
		if (s[i] > 1)
			sol[d[i]] -= s[i] - ans[i];

	// for (int i=0; i<n; i++)
	// 	cerr << i << ' ' << sol[i] << '\n';

	auto it = min_element(sol, sol+n);
	cout << *it << "\n" << it-sol+1 << "\n";
}