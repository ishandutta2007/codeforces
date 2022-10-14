#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using oset = tree<int, null_type, T, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<18, mod = 1e9 + 7, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int ll
const int mx = maxn-1;
struct segtree {
	struct node {
		node *l, *r;
		int lazy;
		pi val;
		node(int x = 0, int p = -1) : val(x, p), lazy(0), l(0), r(0) {};
	};
	using pnode = node*;
	pnode rt= nullptr;
	void clear() {
		rt = nullptr;
	}
	void push(pnode &v, int l, int r) {
		if(!v) return;
		v->val.first += v->lazy;
		if(l != r) {
		if(!v->l) v->l = new node(0, l);
		if(!v->r) v->r = new node(0, 1 + (l+r)/2);
		v->l->lazy += v->lazy;
		v->r->lazy += v->lazy;
		}
		v->lazy = 0;
	}
	pi get(int l, int r) {
		if(l>r) return {1ll<<59, -1};
		return get(0, mx, l, r, rt);
	}
	pi get(int l, int r, int ql, int qr, pnode &v) {
		push(v, l, r);
		if(r < ql || qr < l) return {1ll<<59, -1};
		if(!v) v = new node(0, l);
		if(ql <= l && r <= qr) return v->val;
		int mid = (l+r)/2;
		return min(get(l, mid, ql, qr, v->l), get(mid+1, r, ql, qr, v->r));
	}
	void upd(int l, int r, int x) {
		if(l>r) return;
		upd(0, mx, l, r, x, rt);
	}
	void upd(int l, int r, int ql, int qr, int x, pnode &v) {
		push(v, l, r);
		if(r < ql || qr < l) return;
		//cout << l << " " << r << " " << ql << " " << qr << '\n';
		if(!v) v = new node(0, l);
		if(ql <= l && r <= qr) {
			v->lazy = x;
			push(v, l, r);
			return;
		}
		int mid = (l+r)/2;
		upd(l, mid, ql, qr, x, v->l);
		upd(mid + 1, r, ql, qr, x, v->r);
		v->val = min(v->l?v->l->val:pi{1<<30, -1}, v->r?v->r->val:pi{1<<30, -1});
	}
};
segtree x;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m,l,r,v;
	cin >> n;
	for(int t, i = 0; i < n; i++) cin >> t, x.upd(i, i, t);
	cin >> m;
	string t;
	getline(cin, t);
	while(m--) {
		getline(cin, t);
		istringstream in(t);
		if(count(all(t), ' ')==1) {
			in >> l >> r;
			if(l<=r) cout << x.get(l, r).first << '\n';
			else cout << min(x.get(0, r), x.get(l, n-1)).first << '\n';
		} else {
			in >> l >> r >> v;
			if(l<=r) x.upd(l, r, v);
			else x.upd(0, r, v), x.upd(l, n-1, v);
		}
		//for(int i = 0; i < n; i++) cout << x.get(i, i).first << " "; cout << "\n=======\n";
	}
	return 0;
}