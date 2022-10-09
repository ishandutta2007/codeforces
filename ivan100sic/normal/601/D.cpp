#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[300005];
int c[300005];
string s;

struct node {
	int nx[26], f, z;
} b[1800005]; int sz;

int leaf(int x) {
	int r = ++sz;
	int p = ++sz;
	b[p].z = b[r].f = b[r].z = 1;
	b[p].nx[x] = r;
	return p;
}

int extend(int x, int c) {
	int r = ++sz;
	b[r].nx[c] = x;
	b[r].z = b[x].z;
	return r;
}

int merge(int x, int y) {
	if (!x) return y;
	if (!y) return x;
	b[x].f |= b[y].f;
	b[x].z = b[x].f;
	for (int i=0; i<26; i++) {
		b[x].nx[i] = merge(b[x].nx[i], b[y].nx[i]);
		b[x].z += b[b[x].nx[i]].z;
	}
	return x;
}

int dfs(int x, int p) {
	int l = s[x-1] - 'a';
	int nd = leaf(l);
	for (int y : e[x]) {
		if (y == p)
			continue;
		int tmp = dfs(y, x);
		nd = merge(nd, extend(tmp, l));
	}
	c[x] += b[nd].z;
	return nd;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> c[i];
	cin >> s;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dfs(1, 1);
	int h = *max_element(c+1, c+n+1);
	cout << h << '\n' << count(c+1, c+n+1, h) << '\n';
}