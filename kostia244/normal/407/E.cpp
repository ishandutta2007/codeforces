#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<18, mod = 1e9 + 7, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct node {
	ll lazy, val;
	node(ll x = 1ll<<40) :val(x), lazy(0) {}
};
node merge(node a, node b) {
	return a.val < b.val ? a : b;
}
struct segtree {
	vector<node> t;
	int n;
	void init(int _n) {
		n = _n;
		t.resize(4*n);
		init(0, n, 1);
	}
	void init(int l, int r, int v) {
		if(l == r) {
			t[v] = node(1ll<<40);
			return;
		}
		int mid = (l+r)>>1;
		init(l, mid, v<<1);
		init(mid+1,r,v<<1|1);
		t[v] = merge(t[v<<1], t[v<<1|1]);
	}
	void push(int v, int l, int r) {
		if(!t[v].lazy) return;
		t[v].val += t[v].lazy;
		if(l!=r) {
			t[v<<1].lazy += t[v].lazy;
			t[v<<1|1].lazy += t[v].lazy;
		}
		t[v].lazy = 0;
	}
	void set(int l, int r, int i, ll x, int v) {
		push(v, l, r);
		if(i < l || i > r) return;
		if(l == r) {
			t[v] = node(x);
			return;
		}
		int mid = (l+r)/2;
		set(l, mid, i, x, v<<1);
		set(mid+1, r, i, x, v<<1|1);
		t[v] = merge(t[v<<1], t[v<<1|1]);
	}
	void add(int l, int r, int ql, int qr, int x, int v) {
		push(v, l, r);
		if(qr < l || r < ql) return;
		if(ql <= l && r <= qr) {
			t[v].lazy = x;
			push(v, l, r);
			return;
		}
		int mid = (l+r)/2;
		add(l, mid, ql, qr, x, v<<1);
		add(mid+1, r, ql, qr, x, v<<1|1);
		t[v] = merge(t[v<<1], t[v<<1|1]);
	}
	int find(int l, int r, int k, int v = 1) {
		push(v, l, r);
		if(t[v].val>k) return -1;
		if(l == r) return l;
		int mid = (l+r)/2;
		if(int t= find(l, mid, k, v<<1); t == -1) return find(mid+1, r, k, v<<1|1);
		else return t;
	}
	ll get(int l, int r, int i, int v) {
		push(v, l, r);
		if(l == r) return t[v].val;
		int mid = (l+r)/2;
		if(i <= mid)
			return get(l, mid, i, v<<1);
		return get(mid+1,r,i,v<<1|1);
	}
	void set(int i, ll x) {
		set(0, n, i, x, 1);
	}
	void add(int l, int r, int x) {
		add(0, n, l, r, x, 1);
	}
	int find(int k) {return find(0, n, k);}
};
int n, k, d, bias = 1;
pi ans = {1, 1};
map<int, vi> r;
void upd(int l, int r) {
	if(r-l>ans.second-ans.first)
		ans = {l+bias, r+bias};
}
void solve(vi &a) {
	int n = a.size();
	if(!n) return;
	segtree st;
	st.init(n);
	vi mx, mn;
	map<int, int> lst;
	for(int l = 0, i = 0; i < n; i++) {
		if(lst.count(a[i])) {
			while(l <= lst[a[i]]) {
				st.set(l++, 1ll<<40);
			}
		}
		while(!mx.empty()&&a[mx.back()]<=a[i]) {
			int t = mx.back();
			mx.pop_back();
			st.add(mx.empty()?0:(mx.back()+1), t, -a[t]+a[i]);
		}
		mx.push_back(i);
		while(!mn.empty()&&a[mn.back()]>=a[i]) {
			int t = mn.back();
			mn.pop_back();
			st.add(mn.empty()?0:(mn.back()+1), t, a[t]-a[i]);
		}
		mn.push_back(i);
		st.set(i, i);
		int T = i-st.find(k+i)+1;
		upd(i-T+1, i);
		lst[a[i]] = i;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> d;
	if(d == 0) {
		int cur = 0, lst = -1;
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			if(t==lst) cur++;
			else cur = 1;
			lst = t;
			upd(i-cur+1, i);
		}
		cout << ans.first << " " << ans.second << '\n';
		return 0;
	}
	vi t;
	for(int l = -1, x, i = 0; i < n; i++) {
		cin >> x;
		int r = (d + x%d)%d;
		if(r!=l) solve(t), bias = i+1, t.clear();
		if(x>=0)
			t.pb(x/d);
		else
			t.pb((x-d+1)/d);
		l = r;
	}
	solve(t);
	cout << ans.first << " " << ans.second << '\n';
	return 0;
}