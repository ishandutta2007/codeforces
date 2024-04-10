#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[1000005], p[1000005];
basic_string<int> e[1000005], st;

int l[1000005], r[1000005], dub[1000005], lrt;

void dfs(int x) {
	l[x] = ++lrt;
	for (int y : e[x]) {
		dub[y] = dub[x] + 1;
		dfs(y);
	}
	r[x] = lrt;
}

const int MAXN = 1 << 20;
int b[2*MAXN];

void update(int x, int v) {
	x += MAXN;
	b[x] = v;
	while (x > 1) {
		x >>= 1;
		b[x] = max(b[2*x], b[2*x+1]);
	}
}

int query(int l, int r, int x=1, int xl=0, int xr=MAXN-1) {
	if (r < xl || xr < l)
		return 0;
	if (l <= xl && xr <= r)
		return b[x];
	int xm = (xl+xr) >> 1;
	return max(query(l, r, 2*x, xl, xm), query(l, r, 2*x+1, xm+1, xr));
}

bool alive[1000005];
multiset<int> root_vals;
set<pair<int, int>> root_ls;

void add_node(int x) {
	for (int y : e[x]) {
		if (alive[y]) {
			int v = query(l[y], r[y]) - dub[y];
			root_vals.erase(root_vals.find(v));
			root_ls.erase({l[y], y});
		}
	}
	update(l[x], dub[x]);
	int v = query(l[x], r[x]) - dub[x];
	root_vals.insert(v);
	root_ls.insert({l[x], x});
	alive[x] = 1;
}

void remove_node(int x) {
	auto it = prev(root_ls.upper_bound({l[x], 123123123}));
	int root = it->second;

	int v = query(l[root], r[root]) - dub[root];
	root_vals.erase(root_vals.find(v));
	update(l[x], 0);
	if (x != root) {
		v = query(l[root], r[root]) - dub[root];
		root_vals.insert(v);
	} else {
		root_ls.erase({l[x], x});
	}
	alive[x] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	n++;
	a[n] = n;

	for (int i=1; i<=n; i++) {
		while (st.size() && a[st.back()] < a[i]) {
			p[st.back()] = i;
			st.pop_back();
		}
		st += i;
	}

	for (int i=1; i<n; i++)
		e[p[i]] += i;

	dfs(n);

	for (int i=1; i<=k; i++)
		add_node(i);
	cout << *root_vals.rbegin() + 1 << ' ';
	for (int i=2; i<=n-k; i++) {
		add_node(i+k-1);
		remove_node(i-1);
		cout << *root_vals.rbegin() + 1 << ' ';
	}
	cout << '\n';
}