#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 500100;
int n, k, a, b, x, q, m, t, l, r;

int st[4 * N];

void upd(int node, int l, int r, int pos, int val) {
	if(l == r)
		return st[node] = val, void();

	int mid = (l + r) / 2;
	if(pos <= mid)
		upd(2 * node, l, mid, pos, val);
	else
		upd(2 * node + 1, mid + 1, r, pos, val);
	st[node] = __gcd(st[2 * node], st[2 * node + 1]);
}

int que(int node, int l, int r, int x, int y) {
	if(x <= l && r <= y)
		return st[node];
	int mid = (l + r) / 2;
	int g = 0;
	if(x <= mid) g = __gcd(g, que(2 * node, l, mid, x, y));
	if(y > mid) g = __gcd(g, que(2 * node + 1, mid + 1, r, x, y));
	return g;
}

int cnt(int node, int l, int r, int x, int y, int g) {
	if(l == r)
		return (st[node] % g != 0);
	if(x <= l && r <= y){
		int mid = (l + r) / 2;
		if(st[node] % g == 0)
			return 0;
		else if(st[2 * node] % g == 0)
			return cnt(2 * node + 1, mid + 1, r, x, y, g);
		else if(st[2 * node + 1] % g == 0)
			return cnt(2 * node, l, mid, x, y, g);
		return 2;
	}
	int mid = (l + r) / 2;
	int nr = 0;

	if(x <= mid && mid < y) {
		int g1 = que(2 * node, l, mid, x, y);
		int g2 = que(2 * node + 1, mid + 1, r, x, y);
		if(g1 %g != 0 && g2 % g != 0)
			return 2;
		if(g1 % g != 0)
			return cnt(2 * node, l, mid, x, y, g);
		if(g2 % g != 0)
			return cnt(2 * node + 1, mid + 1, r, x, y, g);
		return 0;
	}

	if(x <= mid) return cnt(2 * node, l, mid, x, y, g);
	if(y > mid) return cnt(2 * node + 1, mid + 1, r, x, y, g);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> x;
		upd(1, 1, n, i, x);
	}

	cin >> q;
	for(int i = 1; i <= q; i++) {
		cin >> t;
		if(t == 1) {
			cin >> l >> r >> x;
			cout << (cnt(1, 1, n, l, r, x) <= 1 ? "YES\n" : "NO\n");
		}
		else {
			cin >> a >> b;
			upd(1, 1, n, a, b);
		}
	}

}