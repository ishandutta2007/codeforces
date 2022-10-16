#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

using namespace std;

const int N = 1000100;
string s;
int st[4 * N], lazy[4 * N], m, n, a[N], b[N], op, pos, val, q;

void push(int nod, int l, int r) {
	if(lazy[nod]) {
		st[nod] += lazy[nod];
		if(l < r) {
			lazy[2 * nod] += lazy[nod];
			lazy[2 * nod + 1] += lazy[nod];
		}
		lazy[nod] = 0;
	}
}

int value(int nod) {
	return st[nod] + lazy[nod];
}

void upd_interv(int nod, int l, int r, int x, int y, int val) {
	push(nod, l, r);
	if(l == r) {
		st[nod] += val;
		return ;
	}

	int mid = (l + r) / 2;
	
	if(x <= l && r <= y)
		lazy[nod] = val;
	else{
		if(x <= mid) upd_interv(2 * nod, l, mid, x, y, val);
		if(y > mid) upd_interv(2 * nod + 1, mid + 1, r, x, y, val);
	}

	st[nod] = min(value(2 * nod), value(2 * nod + 1));
}

int que(int nod, int l, int r, int x, int y) {
	push(nod, l, r);

	if(x <= l && r <= y)
		return st[nod];

	int mid = (l + r) / 2, ans = 1e9;

	if(x <= mid) ans = min(que(2 * nod, l, mid, x, y), ans);
	if(y > mid) ans = min(que(2 * nod + 1, mid + 1, r, x, y), ans);
	return ans;
}

int res(int nod, int l, int r) {
	push(nod, l, r);
	if(value(nod) >= 0) return -1;
	if(l == r) return l;

	// dbg(nod);
	// dbg(value(2 * nod + 1));

	int mid = (l + r) / 2;
	if(value(2 * nod + 1) < 0) 
		return res(2 * nod + 1, mid + 1, r);
	return res(2 * nod, l, mid);
}

int main() {
	ios_base::sync_with_stdio(false);

	// n = 10000;
	// upd_interv(1, 1, n, 1, 10, 1);
	// upd_interv(1, 1, n, 2, 31, 3);
	// upd_interv(1, 1, n, 4, 4, 4);
	// upd_interv(1, 1, n, 7, 7, -9);

	// upd_interv(1, 1, n, 17, 17, -91);
	// upd_interv(1, 1, n, 117, 117, -1);
	// cout<< res(1, 1, n);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		upd_interv(1, 1, N, 1, a[i], -1);
	}
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		upd_interv(1, 1, N, 1, b[i], 1);
	}

	cin >> q;
	for(int i = 1; i <= q; i++) {
		cin >> op >> pos >> val;
		if(op == 1) {
			upd_interv(1, 1, N, 1, a[pos], 1);
			a[pos] = val;
			upd_interv(1, 1, N, 1, a[pos], -1);
		} else {
			upd_interv(1, 1, N, 1, b[pos], -1);
			b[pos] = val;
			upd_interv(1, 1, N, 1, b[pos], 1);
		}
		// dbg(que(1, 1, N, 8, 8));
		cout << res(1, 1, N) << '\n';
	}


}