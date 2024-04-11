#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
const int MAXN = 1<<18;
int mod;
struct mulnode {
	int lazy, sm;
	mulnode(int x = 0) : sm(x), lazy(1) {}
};
mulnode merge(mulnode a, mulnode b) {
	return mulnode((a.sm+b.sm)%mod);
}
struct mulsegtree {
	vector<mulnode> t;
	int n = 0;
	mulsegtree(int n = 0) : t(4*n), n(n) {}
	void mul(int &a, int b) {
		a = a*1ll*b%mod;
	}
	void push(int v, int l, int r) {
		mul(t[v].sm, t[v].lazy);
		if(l != r)
			mul(t[2*v].lazy, t[v].lazy),
			mul(t[2*v+1].lazy, t[v].lazy);
		t[v].lazy = 1;
	}
	void set(int p, int x, int v, int l, int r) {
		push(v, l, r);
		if(p < l || p > r) return;
		if(l == r) {
			t[v] = mulnode(x);
			return;
		}
		int mid = (l+r)/2;
		set(p, x, 2*v, l, mid);
		set(p, x, 2*v+1, mid+1, r);
		t[v] = merge(t[2*v], t[2*v+1]);
	}
	void set(int p, int x) {
		set(p, x, 1, 1, n);
	}
	void mul(int ql, int qr, int x, int v, int l, int r) {
		push(v, l, r);
		if(qr < l || r < ql) return;
		if(ql <= l && r <= qr) {
			mul(t[v].lazy, x);
			push(v, l, r);
			return;
		}
		int mid = (l+r)/2;
		mul(ql, qr, x, 2*v, l, mid);
		mul(ql, qr, x, 2*v+1, mid+1, r);
		t[v] = merge(t[2*v], t[2*v+1]);
	}
	void mul(int ql, int qr, int x) {
		mul(ql, qr, x, 1, 1, n);
	}
	mulnode get(int ql, int qr, int v, int l, int r) {
		push(v, l, r);
		if(qr < l || r < ql) return mulnode();
		if(ql <= l && r <= qr) return t[v];
		int mid = (l+r)/2;
		return merge(get(ql, qr, 2*v, l, mid), get(ql, qr, 2*v+1, mid+1, r));
	}
	int query(int ql, int qr) {
		return get(ql, qr, 1, 1, n).sm;
	}
};
struct node
{
	long long sum, lazy;

	node() {sum = 0; lazy = 0;}
	node(int val)
	{
		sum = val;
		lazy = 0;
	}
};

node temp, broken;

node merge(node l, node r)
{
	temp.sum = l.sum + r.sum;
	temp.lazy = 0;
	return temp;
}

struct segment_tree
{
	node tr[4 * MAXN];

	void push(int l, int r, int idx)
	{
		if(tr[idx].lazy)
		{
			tr[idx].sum += (r - l + 1) * tr[idx].lazy;

			if(l != r)
			{
				tr[2 * idx + 1].lazy += tr[idx].lazy;
				tr[2 * idx + 2].lazy += tr[idx].lazy;
			}

			tr[idx].lazy = 0;
		}
	}

	void update(int qL, int qR, int val, int l, int r, int idx)
	{
		push(l, r, idx);

		if(qL > r || l > qR)
			return;

		if(qL <= l && r <= qR)
		{
			tr[idx].lazy += val;
			push(l, r, idx);
			return;
		}

		int mid = (l + r) >> 1;
		update(qL, qR, val, l, mid, 2 * idx + 1);
		update(qL, qR, val, mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}

	node query(int qL, int qR, int l, int r, int idx)
	{
		push(l, r, idx);

		if(l > qR || r < qL)
			return broken;

		if(qL <= l && r <= qR)
			return tr[idx];

		int mid = (l + r) >> 1;
		return merge(query(qL, qR, l, mid, 2 * idx + 1), query(qL, qR, mid + 1, r, 2 * idx + 2));
	}
};
mulsegtree R, C;
segment_tree P[10];
vector<int> primes;
int phi;
void find_primes(int n) {
	phi = n;
	for(int d = 2; d*d <= n; d++) {
		if(n%d) continue;
		while(n%d == 0) n/=d;
		primes.push_back(d);
	}
	if(n > 1) primes.push_back(n);
	for(auto i : primes) phi -= phi/i;
	phi--;
}
int bp(int a, int p) {
	//assert(p>=0);
	int r = 1;
	while(p) {
		if(p&1) r = r*1ll*a%mod;
		a = a*1ll*a%mod, p>>=1;
	}
	return r;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n >> mod;
	find_primes(mod);
	R = mulsegtree(n);
	C = mulsegtree(n);
	for(int i = 1; i <= n; i++) {
		int t;cin >> t;
		R.set(i, t);
		for(int F = 0; F < primes.size(); F++) {
			int p = primes[F];
			int c = 0;
			while(t%p == 0) c++, t /= p;
			P[F].update(i, i, c, 1, n, 0);
		}
		C.set(i, t);
	}
	int q, t, l, r, x;
	for(cin >> q; q--;) {
		cin >> t;
		if(t == 1) {
			cin >> l >> r >> x;
			R.mul(l, r, x);
			for(int F = 0; F < primes.size(); F++) {
				int p = primes[F];
				int c = 0;
				while(x%p == 0) c++, x /= p;
				P[F].update(l, r, c, 1, n, 0);
			}
			C.mul(l, r, x);
		}
		if(t == 2) {
			cin >> l >> x;
			//cout << l << " " << x << " " << P[2].query(5, 5, 1, n, 0).sum << endl;
			int nval = 1;
			for(int F = 0; F < primes.size(); F++) {
				int p = primes[F];
				int c = 0;
				while(x%p == 0) c++, x /= p;
				P[F].update(l, l, -c, 1, n, 0);
				nval = nval*1ll*bp(p, P[F].query(l, l, 1, n, 0).sum)%mod;
			}
			//assert(__gcd(x, mod) == 1);
			C.mul(l, l, bp(x, phi));
			nval = nval*1ll*C.query(l, l)%mod;
			R.set(l, nval);
		}
		if(t == 3) {
			cin >> l >> r;
			cout << R.query(l, r) << '\n';
		}
	}
}