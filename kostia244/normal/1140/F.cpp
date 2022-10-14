#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mod = (119 << 23) + 1;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
struct node {
	ll r = 0, p = 0, x = 0, y = 0;
	node(int i = -1) {
		p = i;
	}
};
struct rback {
	int i, j;
	node p, q;
	ll ans;
	rback(int i, node p, int j, node q, ll ans) :
			i(i), p(p), j(j), q(q), ans(ans) {
	}
};
struct dsu {
	ll ans = 0;
	vector<node> t;
	vector<rback> rb;
	void init(int n, int x) {
		t.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			t[i] = node(i);
			++(i <= x ? t[i].x : t[i].y);
		}
	}
	int par(int i) {
		if (i == t[i].p)
			return i;
		return par(t[i].p);
	}
	void unite(int i, int j) {
//		cout << "merge " << i << " " << j << "\n";
		i = par(i), j = par(j);
//		cout << "merge " << i << " " << j << "\n";
		if (i == j)
			return;
		rb.emplace_back(i, t[i], j, t[j], ans);
		if (t[i].r < t[j].r)
			swap(i, j);
		t[j].p = i;
		t[i].r += t[j].r == t[i].r;
//		cout << i << " " << j << " " << t[i].x << " " << t[i].y << " " << t[j].x << " " << t[j].y << "\n";
		ans += t[i].x * t[j].y + t[j].x * t[i].y;
		t[i].x += t[j].x, t[i].y += t[j].y;
	}
	void rollback(int c) {
		while (rb.size() > c) {
			t[rb.back().i] = rb.back().p;
			t[rb.back().j] = rb.back().q;
			ans = rb.back().ans;
			rb.pop_back();
		}
	}
};
vpi t[4 * maxn];
ll ans[maxn];
dsu d;
void add(int v, int l, int r, int ql, int qr, pi p) {
//	if(v == 1) {
//		cout << ql << " " << qr << "range\n";
//	}
//	cout << v << " " << l << " " << r << " " << ql << " " << qr << "lrqlr\n";
	if (l > qr || r < ql)
		return;
	if (ql <= l && r <= qr) {
//		cout << l << " " << r << " " << ql << " " << qr << "\n";
		t[v].pb(p);
		return;
	}
	int mid = (l + r) >> 1;
	add(v << 1, l, mid, ql, qr, p);
	add(v << 1 | 1, mid + 1, r, ql, qr, p);
}
void dfs(int v, int l, int r) {
	int state = d.rb.size();
//	cout << v << " " << l << " " << r << "\n";
	for (auto i : t[v]) {
		d.unite(i.first, 300000 + i.second);
//		cout << v << " " << i.first << " " << 300000+i.second << "\n";
	}
	if (l == r) {
		ans[l] = d.ans;
//		cout << l << " " << d.ans << "\n";
	} else {
		int mid = (l + r) >> 1;
		dfs(v << 1, l, mid);
		dfs(v << 1 | 1, mid + 1, r);
	}
//	cout << v << "back\n";
	d.rollback(state);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	d.init(600000, 300000);
	int n;
	pi t;
	map<pi, int> c;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> t.first >> t.second;
		if(c[t]>0) {
			add(1, 1, n, c[t], i-1, t);
			c[t] = 0;
		} else
			c[t] = i;
	}
	for(auto i : c)
		if(i.second != 0)
			add(1, 1,n, i.second, n, i.first);
	dfs(1, 1, n);
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
}