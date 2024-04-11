#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 3e5 + 33, maxk = 1<<11, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<array<int, 2>> tree[2*maxn];
int n, m, a[maxn];
vector<array<int, 2>> merge(const vector<array<int, 2>> &a, const vector<array<int, 2>> &b) {
	if(a.empty()) return b;
	if(b.empty()) return a;
	
	//for(auto [x, y] : a) cout << x << " " << y << endl;
	//for(auto [x, y] : b) cout << x << " " << y << endl;

	vector<array<int, 2>> res;
	int i = 0, j = 0, cur = -1;
	while(cur != 1<<30) {
		while(i+1 < a.size() && a[i+1][0] <= cur) i++;
		while(j+1 < b.size() && b[j+1][0] <= cur+a[i][1]) j++;
		//cout << cur << " " << i << " " << j << " " << b[j][0] << endl;
		
		res.push_back({cur, a[i][1]+b[j][1]});
		
		int nxt = 1<<30;
		if(i+1 < a.size()) nxt = min(nxt, a[i+1][0]);
		if(j+1 < b.size()) nxt = min(nxt, b[j+1][0] - a[i][1]);
		cur = nxt;
	}
	return res;
}

int f(int p, int val) {
	//cout << p << " " << val << '\n';
	//for(auto i : tree[p]) cout << i[0] << " " << i[1] << endl;
	int it = upper_bound(all(tree[p]), array<int, 2>{val+1, -(1<<30)}) - tree[p].begin() - 1;
	//cout << it << endl;
	return val + tree[p][it][1];
}

int query(int l, int r) {//[l;r)
	//cout << l << " " << r << '\n';
	vector<int> _cr;
	int val = 0;
	for(l += n, r += n; l < r; l>>=1, r>>=1) {
		if(l&1) val = f(l++, val);
		if(r&1) _cr.push_back(--r);
	}
	reverse(all(_cr));
	for(auto &i : _cr) {
		val = f(i, val);
	}
	//cout << "Fff\n";
	return val;
}

void pre() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];a[i]--;a[i] = i - a[i];
		tree[n+i].push_back({-1, 0});
		if(a[i]>=0) tree[n+i].push_back({a[i], 1});
	}
	//merge(tree[24], tree[25]);
	for(int i = n-1; i; i--) tree[i] = merge(tree[2*i], tree[2*i+1]);
}
void solve() {
	for(int l, r, I = m; I--;) {
		cin >> l >> r;
		r = n-r;
		//cout << l << " " << r << ":\n";
		cout << query(l, r) << '\n';
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	pre();
	//for(int i = 0; i < n; i++) cout << a[i] << ' ';cout << '\n';
	solve();
}