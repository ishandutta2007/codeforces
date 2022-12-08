#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;
long double eps = 1e-8;

struct Tree_max {
	vector<ll> tree;
	vector<ll> ar;
	vector<ll> upd;

	Tree_max() {}
	Tree_max(vector<ll> _ar) {
		ar = _ar;
		tree.resize(4 * ar.size());
		upd.assign(4 * ar.size(), INF);
		build(0, 0, ar.size());
	}

	void build(int pos, int l, int r) {
		if (r - l == 1) {
			tree[pos] = ar[l];
			return;
		}
		build(2 * pos + 1, l, (l + r) / 2);
		build(2 * pos + 2, (l + r) / 2, r);
		tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
	}

	void push(int pos, int l, int r) {
		if (upd[pos] == INF) return;
		if (r - l == 1) {
			tree[pos] = upd[pos];
			upd[pos] = INF;
			return;
		}
		upd[2 * pos + 1] = upd[2 * pos + 2] = upd[pos];
		tree[pos] = upd[pos];
		upd[pos] = INF;
	}

	void upd_seg(int pos, int l, int r, int vl, int vr, ll delta) {
		push(pos, l, r);
		if (r <= vl || vr <= l) {
			return;
		}
		if (vl <= l && r <= vr) {
			upd[pos] = delta;
			push(pos, l, r);
			return;
		}
		upd_seg(2 * pos + 1, l, (l + r) / 2, vl, vr, delta);
		upd_seg(2 * pos + 2, (l + r) / 2, r, vl, vr, delta);
		tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
	}

	int find(int pos, int l, int r, ll k) {
		push(pos, l, r);
		if (tree[pos] < k) return ar.size();
		if (r - l == 1) return l;
		int f1 = find(2 * pos + 1, l, (l + r) / 2, k);
		if (f1 == ar.size()) return find(2 * pos + 2, (l + r) / 2, r, k);
		else return f1;
	}
};

struct Tree_sum {
	vector<ll> tree;
	vector<ll> ar;
	vector<ll> upd;

	Tree_sum() {}
	Tree_sum(vector<ll> _ar) {
		ar = _ar;
		tree.resize(4 * ar.size());
		upd.assign(4 * ar.size(), INF);
		build(0, 0, ar.size());
	}

	void build(int pos, int l, int r) {
		if (r - l == 1) {
			tree[pos] = ar[l];
			return;
		}
		build(2 * pos + 1, l, (l + r) / 2);
		build(2 * pos + 2, (l + r) / 2, r);
		tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
	}

	void push(int pos, int l, int r) {
		if (upd[pos] == INF) return;
		if (r - l == 1) {
			tree[pos] = upd[pos];
			upd[pos] = INF;
			return;
		}
		upd[2 * pos + 1] = upd[2 * pos + 2] = upd[pos];
		tree[pos] = (r - l) * upd[pos];
		upd[pos] = INF;
	}

	void upd_seg(int pos, int l, int r, int vl, int vr, ll delta) {
		push(pos, l, r);
		if (r <= vl || vr <= l) {
			return;
		}
		if (vl <= l && r <= vr) {
			upd[pos] = delta;
			push(pos, l, r);
			return;
		}
		upd_seg(2 * pos + 1, l, (l + r) / 2, vl, vr, delta);
		upd_seg(2 * pos + 2, (l + r) / 2, r, vl, vr, delta);
		tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
	}
	
	ll get_sum(int pos, int l, int r, int vl, int vr) {
		push(pos, l, r);
		if (r <= vl || vr <= l) return 0;
		if (vl <= l && r <= vr)  return tree[pos];
		return get_sum(2 * pos + 1, l, (l + r) / 2, vl, vr) + get_sum(2 * pos + 2, (l + r) / 2, r, vl, vr);
	}

};


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> k(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> t(n);
	vector<ll> b(n);
	vector<ll> pref(n);
	b[0] = a[0];
	for (int i = 1; i < n; i++) {
		cin >> k[i - 1];
		t[i] = t[i - 1] + k[i - 1];
		b[i] = a[i] - t[i];
		pref[i] = pref[i - 1] + t[i];
	}
	int q;
	cin >> q;
	char ask;
	ll t1, t2;
	/*for (int i = 0; i < n; i++) {
		cout << b[i] << endl;
	}*/
	//cout << "flex\n";
	Tree_max treem = Tree_max(b);
	Tree_sum trees = Tree_sum(b);
	while (q--) {
		cin >> ask >> t1 >> t2; t1--;
		if (ask == '+') {
			a[t1] = trees.get_sum(0, 0, n, t1, t1 + 1);
			ll f = treem.find(0, 0, n, a[t1] + t2);
			//cout << f << " " << a[t1] << endl;
			treem.upd_seg(0, 0, n, t1, f, a[t1] + t2);
			trees.upd_seg(0, 0, n, t1, f, a[t1] + t2);
		}
		else {
			ll ans = pref[t2 - 1];
			if (t1 != 0) ans -= pref[t1 - 1];
			//cout << trees.get_sum(0, 0, n, 0, 1) << " " << trees.get_sum(0, 0, n, 1, 2) << " " << trees.get_sum(0, 0, n, 2, 3) << endl;
			ans += trees.get_sum(0, 0, n, t1, t2);
			cout << ans << endl;
		}
	}
	//system("pause");
	return 0;
}