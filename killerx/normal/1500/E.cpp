#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long ll;

const int mxn = 400005;

int n, q;
ll ini[mxn];

struct Query {
	int tp;
	ll x;
} qry[mxn];

std::vector <ll> vec;

ll v[mxn];
int b[mxn];
ll p0[mxn];
ll s0[mxn];

int rnk(int x) {
	int ans = 0;
	for (++ x; x; x -= x & -x) ans += b[x];
	return ans - 1;
}

int kth(int k) {
	++ k;
	int x = 0;
	for (int stp = 1 << 18; stp; stp >>= 1)
		if (x + stp < mxn && k - b[x + stp] > 0)
			k -= b[x += stp];
	return x;
}

struct Item {
	int sz;
	ll s, sp, ss;

	Item(): sz(), s(), sp(), ss() {}
	Item(int a, ll b, ll c, ll d): sz(a), s(b), sp(c), ss(d) {}

	Item operator + (const Item &oth) const {
		return Item(sz + oth.sz, s + oth.s, sp + oth.sp + oth.sz * s, ss + oth.ss + sz * oth.s);
	}
};

const int mxsz = 1 << 19;
Item seg[mxsz << 1];

void update(int x, Item v) {
	seg[x += mxsz] = v;
	for (; x >>= 1; seg[x] = seg[x << 1] + seg[x << 1 | 1]);
}

Item query(int l, int r) {
	Item lef, rig;
	for (l += mxsz, r += mxsz; l < r; l >>= 1, r >>= 1) {
		if (l & 1) lef = lef + seg[l ++];
		if (r & 1) rig = seg[-- r] + rig;
	}
	return lef + rig;
}

void insert(ll x) {
	int ps = std::lower_bound(vec.begin(), vec.end(), x) - vec.begin(), p;
	v[ps] = x;
	update(ps, Item(1, x, x, x));
	p = ps;
	for (++ p; p < mxn; p += p & -p) b[p] ++, p0[p] += x;
	p = vec.size() - 1 - ps;
	for (++ p; p < mxn; p += p & -p) s0[p] += x;
}

void erase(ll x) {
	int ps = std::lower_bound(vec.begin(), vec.end(), x) - vec.begin(), p;
	v[ps] = 0;
	update(ps, Item(0, 0, 0, 0));
	p = ps;
	for (++ p; p < mxn; p += p & -p) b[p] --, p0[p] -= x;
	p = vec.size() - 1 - ps;
	for (++ p; p < mxn; p += p & -p) s0[p] -= x;
}

ll P(int x) {
	ll ans = 0;
	for (++ x; x; x -= x & -x) ans += p0[x];
	return ans;
}

ll S(int x) {
	ll ans = 0;
	for (++ x; x; x -= x & -x) ans += s0[x];
	return ans;
}

int cur;

ll V(int x) {
	int s = kth(x);
	return S(vec.size() - 1 - s) - P(kth(cur - 1 - x)) - v[s];
}

ll SP(int l, int r) {
//	ll ans = 0;
//	for (int i = l; i < r; ++ i) ans += P(kth(i));
//	return ans;
	return query(kth(l), kth(r)).sp + (r - l) * query(0, kth(l)).s;
}

ll SS(int l, int r) {
//	ll ans = 0;
//	for (int i = l; i < r; ++ i) ans += S(vec.size() - 1 - kth(cur - 1 - i));
//	return ans;
	return query(kth(cur - r), kth(cur - l)).ss + (r - l) * query(kth(cur - l), kth(cur)).s;
}

ll query() {
	cur = rnk(vec.size() - 1) + 1;
	if (cur == 0) return 0;
	int lb = 0, rb = cur - 1;
//	while (lb < rb) {
//		int md = (lb + rb) >> 1;
//		if (V(md) < V(md + 1)) lb = md + 1;
//		else rb = md;
//	}
	lb = (cur - 1) >> 1;
	int mx = lb;
	lb = 0, rb = mx;
	while (lb < rb) {
		int md = (lb + rb) >> 1;
		if (V(md) < 0) lb = md + 1;
		else rb = md;
	}
	int L = lb;
	lb = mx, rb = cur;
	while (lb < rb) {
		int md = (lb + rb) >> 1;
		if (V(md) < 0) rb = md;
		else lb = md + 1;
	}
	int R = lb;
	ll ans = 0;
	ans += P(R ? kth(R - 1) : -1) - P(L ? kth(L - 1) : -1);
	ans += SS(cur - L, cur) - SP(0, L);
	ans += SS(0, cur - R) - SP(R, cur);
	return ans;
}

int main() {
	scanf("%d %d", &n, &q);
	rep(i, n) scanf("%lld", &ini[i]);
	rep(i, q) scanf("%d %lld", &qry[i].tp, &qry[i].x);
	rep(i, n) vec.push_back(ini[i]);
	rep(i, q) vec.push_back(qry[i].x);
	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	rep(i, n) insert(ini[i]);
	printf("%lld\n", query());
	rep(i, q) {
		if (qry[i].tp == 1) insert(qry[i].x);
		else erase(qry[i].x);
		printf("%lld\n", query());
	}
	return 0;
}