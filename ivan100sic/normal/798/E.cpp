#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NODES = 500005 * 22;

struct node {
	int l, r;
} b[NODES]; int bsz;

int newnode(int l=0, int r=0) {
	b[++bsz] = {l, r};
	return bsz;
}

int clone(int x) {
	b[++bsz] = b[x];
	return bsz;
}

int full_set(int l, int r, int xl=1, int xr=500000) {
	if (r < xl || xr < l)
		return 0;
	if (xl == xr)
		return xl;
	int xm = (xl+xr) >> 1;
	int u = full_set(l, r, xl, xm);
	int v = full_set(l, r, xm+1, xr);
	return newnode(u, v);
}

int set_erase(int p, int x, int xl=1, int xr=500000) {
	if (xl == xr)
		return 0;
	x = clone(x);
	int xm = (xl+xr) >> 1;
	if (p <= xm)
		b[x].l = set_erase(p, b[x].l, xl, xm);
	else
		b[x].r = set_erase(p, b[x].r, xm+1, xr);
	return x;
}

basic_string<int> e[NODES];

void add_edges(int from, int l, int r, int x, int xl=1, int xr=500000) {
	if (r < xl || xr < l || !x)
		return;
	if (l <= xl && xr <= r) {
		e[from] += x;
		return;
	}
	int xm = (xl+xr) >> 1;
	add_edges(from, l, r, b[x].l, xl, xm);
	add_edges(from, l, r, b[x].r, xm+1, xr);
}

int n;
int a[500005], ans[500005];
vector<int> q;

bool vis[NODES];

void dfs(int x) {
	vis[x] = 1;
	for (int y : e[x])
		if (!vis[y])
			dfs(y);
	if (b[x].l && !vis[b[x].l])
		dfs(b[x].l);
	if (b[x].r && !vis[b[x].r])
		dfs(b[x].r);

	if (x <= n)
		q.push_back(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	bsz = n;
	int root = full_set(1, n);

	for (int i=1; i<=n; i++) {
		int j = a[i];
		if (j == -1) {
			add_edges(i, 1, i-1, root);
			add_edges(i, i+1, n, root);
		} else {
			if (i < j) {
				add_edges(i, 1, i-1, root);
				add_edges(i, i+1, j-1, root);
			} else {
				add_edges(i, 1, j-1, root);
			}
			e[j] += i;
			root = set_erase(j, root);
		}
	}

	for (int i=1; i<=bsz; i++)
		if (!vis[i])
			dfs(i);

	for (int i=0; i<n; i++)
		ans[q[i]] = i+1;

	for (int i=1; i<=n; i++)
		cout << ans[i] << " \n"[i == n];
}