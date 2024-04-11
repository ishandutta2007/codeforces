#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 5e5 + 33, mod = (119 << 23) + 1;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
struct node {
	int r = 0, p = 0, x = 0;
	node(int i = -1) {
		p = i;
	}
};
struct rback {
	int i, j;
	node p, q;
	rback(int i, node p, int j, node q) :
			i(i), p(p), j(j), q(q) {
	}
};
struct dsu {
	vector<node> t;
	vector<rback> rb;
	void init(int n) {
		t.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			t[i] = node(i);
			t[i].x = 1;
		}
	}
	int par(int i) {
		if (i == t[i].p)
			return i;
		return par(t[i].p);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if (i == j)
			return;
		rb.emplace_back(i, t[i], j, t[j]);
		if (t[i].r < t[j].r)
			swap(i, j);
		t[j].p = i;
		t[i].r += t[j].r == t[i].r;
		t[i].x += t[j].x;
	}
	void rollback(int c) {
		while (rb.size() > c) {
			t[rb.back().i] = rb.back().p;
			t[rb.back().j] = rb.back().q;
			rb.pop_back();
		}
	}
};
vpi t[4 * maxn];
int qq[maxn];
vector<int> ans;
dsu d;
void add(int v, int l, int r, int ql, int qr, pi p) {
	if (l > qr || r < ql)
		return;
	if (ql <= l && r <= qr) {
		t[v].pb(p);
		return;
	}
	int mid = (l + r) >> 1;
	add(v << 1, l, mid, ql, qr, p);
	add(v << 1 | 1, mid + 1, r, ql, qr, p);
}
void dfs(int v, int l, int r) {
	//cout << l << " " << r << endl;
	int state = d.rb.size();
	for (auto i : t[v]) {
		d.unite(i.first, i.second);
	}
	if (l == r) {
	//cout << l << " : ";
	//for(int i = 1; i <= 5; i++) cout << d.t[d.par(i)].x << ' '; cout << endl;
		if(qq[l]) ans.push_back(d.t[d.par(qq[l])].x);
	} else {
		int mid = (l + r) >> 1;
		dfs(v << 1, l, mid);
		dfs(v << 1 | 1, mid + 1, r);
	}
	d.rollback(state);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k, q;
	cin >> n >> q >> k;
	vector<array<int, 3>> Q(q);
	vector<int> days {-1};
	for(int p = 0; p < q; p++) {
		auto &i = Q[p];
		cin >> i[0];
		if(i[0] == 1) cin >> i[1] >> i[2];
		else if(i[0] == 2) cin >> i[1];
		else days.push_back(p);
	}
	days.push_back(q);
	int day = 0, moment = 0;
	for(auto [t, x, y] : Q) {
		if(t == 3) day++;
		if(t == 2) cin >> x, qq[moment] = x;//, cout << moment << endl;
		else {
			cin >> x >> y;
			add(1, 0, q, moment, days[min((int)days.size()-1, day+k)], {x, y});
		}
		moment++;
	}
	d.init(n+2);
	dfs(1, 0, q);
	for(auto i : ans) cout << i << '\n';
}