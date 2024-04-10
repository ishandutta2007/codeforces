#include <bits/stdc++.h>
using namespace std;

// #define FILE
// #define DEBUG

template <typename T>
inline void read(T &x) {
	x = 0; int f = 1, c = getchar();
	while (c <= 32) c = getchar();
	if (c == 45) f = 0, c = getchar();
	while (c > 32) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	!f && (x *= -1);
}

typedef long long ll;
const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const ll linf = 1LL * inf * inf;

int n; ll k;
int a[N];
ll sum[N];
ll ans1, ans2;

template <typename T>
struct BIT {
	T sum[N];
	BIT() {memset(sum, 0, sizeof(sum));}
	void init() {memset(sum, 0, sizeof(sum));}
	void upd(int x, T v) {for (; x < N; x += x & -x) sum[x] += v;}
	T qry(int x) {T ans = 0; for (; x; x -= x & -x) ans += sum[x]; return ans;}
};

struct BIT0 {
	ll mn[N];
	BIT0() {memset(mn, 0x3f, sizeof(mn));}
	void init() {memset(mn, 0x3f, sizeof(mn));}
	void upd(int x, ll v) {for (; x < N; x += x & -x) mn[x] = min(mn[x], v);}
	ll qry(int x) {ll ans = linf; for (; x; x -= x & -x) ans = min(ans, mn[x]); return ans;}
};

vector <ll> vx;
int F(ll x) {
	return upper_bound(vx.begin(), vx.end(), x) - vx.begin();
}

BIT <int> bit;
BIT <ll> bit1; BIT0 bit0;

// find how many [l,r] sum >= S
ll check(ll S) {
	bit.init(); ll ans = 0;
	bit.upd(F(0), 1);
	for (int i = 1; i <= n; ++ i) {
		ans += bit.qry(F(sum[i] - S));
		bit.upd(F(sum[i]), 1);
	}
	return ans;
}

int cover[N];

// fill [l,r] sum >= S
void fill(ll S) {
	bit.init(); bit1.init(); bit0.init();
	bit.upd(F(0), 1); bit1.upd(F(0), 0); bit0.upd(F(0), 0);
	for (int i = 1; i <= n; ++ i) {
		ans1 += bit.qry(F(sum[i] - S)) * sum[i] - bit1.qry(F(sum[i] - S));
		ll l = bit0.qry(F(sum[i] - S));
		if (l <= i) {
			cover[l + 1] ++; cover[i + 1] --;
		}
		bit.upd(F(sum[i]), 1);
		bit1.upd(F(sum[i]), sum[i]);
		bit0.upd(F(sum[i]), i);
	}
}

vector <pair <int, int> > rem;
vector <int> occ[N];
set <int> nempty;

// get [l,r] sum >= Sl and <= Sr
void get(ll Sl, ll Sr) {
	for (int i = 0; i <= vx.size(); ++ i)
		occ[i].clear();
	nempty.insert(F(0));
	occ[F(0)].push_back(0);
	for (int i = 1; i <= n; ++ i) {
		int l = F(sum[i] - Sr - 1) + 1, r = F(sum[i] - Sl);
		set <int> :: iterator it = nempty.lower_bound(l);
		while (it != nempty.end() && *it <= r) {
			int j = *it;
			for (int l = 0; l < occ[j].size(); ++ l)
				rem.push_back(make_pair(occ[j][l] + 1, i));
			++ it;
		}
		nempty.insert(F(sum[i]));
		occ[F(sum[i])].push_back(i);
	}
}

// fill cnt [l,r] sum = S
void fill_corner(ll S, ll cnt) {
	for (int i = 0; i <= vx.size(); ++ i)
		occ[i].clear();
	ans1 += S * cnt;
	occ[F(0)].push_back(0);
	for (int i = 1; i <= n; ++ i) {
		vector <int> &v = occ[F(sum[i] - S)];
		if (!v.empty() && sum[i] - sum[v[0]] == S) {
			if (v.size() >= cnt) {
				for (int j = 0; j < v.size() - cnt && rem.size() < k - max(k - n, 0LL); ++ j)
					rem.push_back(make_pair(v[j] + 1, i));
				if (cnt) {
					cover[v[v.size() - cnt] + 1] ++;
					cover[i + 1] --;
				}
				cnt = 0;
			} else {
				cover[v[0] + 1] ++;
				cover[i + 1] --;
				cnt -= v.size();
			}
		}
		occ[F(sum[i])].push_back(i);
	}
}

set <int> uncover;

// find the largest k [l,r] pairs and cover max(k - n, 0) of them
void precalc() {
	for (int i = 0; i <= n; ++ i) vx.push_back(sum[i]);
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	ll lb = -linf, rb = linf;
	while (lb < rb) {
		ll md = lb + (rb - lb + 1) / 2;
		if (check(md) >= max(k - n, 0LL))
			lb = md;
		else
			rb = md - 1;
	}
	fill(lb + 1);
	fill_corner(lb, max(k - n, 0LL) - check(lb + 1));
	for (int i = 1; i <= n; ++ i) cover[i] += cover[i - 1];
	for (int i = 1; i <= n; ++ i) if (!cover[i]) uncover.insert(i);
	ll S = lb;
	lb = -linf, rb = S;
	while (lb < rb) {
		ll md = lb + (rb - lb + 1) / 2;
		if (check(md) >= k)
			lb = md;
		else
			rb = md - 1;
	}
	get(lb + 1, S - 1);
	fill_corner(lb, 0);
}

int myrand() {
	return rand() << 15 | rand();
}

struct Treap {
	ll val[N], sum[N];
	int fix[N], siz[N];
	int lson[N], rson[N];
	int que[N + 5], lb, rb;
	
	Treap() {
		root = 0;
		val[0] = sum[0] = 0;
		fix[0] = 0;
		siz[0] = 0;
		lson[0] = rson[0] = 0;
		lb = rb = 0;
		for (int i = 1; i < N; ++ i)
			que[rb ++] = i;
	}
	
	int new_node(ll v) {
		int x = que[lb ++];
		if (lb == N + 5) lb = 0;
		val[x] = sum[x] = v;
		fix[x] = myrand();
		siz[x] = 1;
		lson[x] = rson[x] = 0;
		return x;
	}
	
	void del_node(int x) {
		que[rb ++] = x;
		if (rb == N + 5) rb = 0;
	}
	
	void pushup(int x) {
		siz[x] = siz[lson[x]] + 1 + siz[rson[x]];
		sum[x] = sum[lson[x]] + val[x] + sum[rson[x]];
	}
	
	void split(int x, int k, int &a, int &b) {
		if (!x) {a = b = 0; return ;}
		if (siz[lson[x]] + 1 <= k) {
			a = x;
			split(rson[x], k - siz[lson[x]] - 1, rson[a], b);
			pushup(a);
		} else {
			b = x;
			split(lson[x], k, a, lson[b]);
			pushup(b);
		}
	}
	
	void split0(int x, int v, int &a, int &b) {
		if (!x) {a = b = 0; return ;}
		if (val[x] <= v) {
			a = x;
			split0(rson[x], v, rson[a], b);
			pushup(a);
		} else {
			b = x;
			split0(lson[x], v, a, lson[b]);
			pushup(b);
		}
	}
	
	int merge(int a, int b) {
		if (!a || !b) return a + b;
		if (fix[a] < fix[b]) {
			rson[a] = merge(rson[a], b);
			pushup(a);
			return a;
		} else {
			lson[b] = merge(a, lson[b]);
			pushup(b);
			return b;
		}
	}
	
	int root;
	
	void ins(ll x) {
		int a, b;
		split0(root, x, a, b);
		root = merge(merge(a, new_node(x)), b);
	}
	
	void del(ll x) {
		int a, b, c;
		split0(root, x, b, c);
		split0(b, x - 1, a, b);
		del_node(b);
		b = merge(lson[b], rson[b]);
		root = merge(merge(a, b), c);
	}
	
	ll kth(int k) {
		if (k > siz[root])
			return -linf;
		int a, b;
		split(root, k, a, b);
		ll ans = sum[a];
		root = merge(a, b);
		return ans;
	}
	
	void dbg(int x) {
		if (!x) return ;
		dbg(lson[x]);
		cerr << val[x] << " ";
		dbg(rson[x]);
	}
};

struct ST {
	ll mx[N][18], mn[N][18]; int ln[N];
	
	void build(ll *a, int n) {
		for (int i = 2; i <= n + 1; ++ i)
			ln[i] = ln[i >> 1] + 1;
		for (int i = 0; i <= n; ++ i)
			mx[i][0] = mn[i][0] = a[i];
		for (int j = 1; j < 18; ++ j)
			for (int i = 0; i + (1 << j) - 1 <= n; ++ i) {
				mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
				mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
			}
	}
	
	ll qry_max(int l, int r) {
		int k = ln[r - l + 1];
		return max(mx[l][k], mx[r - (1 << k) + 1][k]);
	}
	
	ll qry_min(int l, int r) {
		int k = ln[r - l + 1];
		return min(mn[l][k], mn[r - (1 << k) + 1][k]);
	}
	
	ll qry(int l, int r) {
		if (l > r) return 0;
		return qry_min(l - 1, r - 1) - qry_max(l, r);
	}
};

ST st;
Treap treap;

set <int> :: iterator Find(int x) {return uncover.lower_bound(x);}
int Pre(int x) {set <int> :: iterator i = Find(x); if (i == uncover.begin()) return -inf; -- i; return *i;}
int Suf(int x) {set <int> :: iterator i = Find(x); ++ i; if (i == uncover.end()) return inf; return *i;}
int Fir() {return *uncover.begin();}
int Lst() {return *uncover.rbegin();}

// cover x
void Del(int x) {
	if (x != Fir()) {
		int y = Pre(x);
		treap.del(st.qry(y, x));
	}
	if (x != Lst()) {
		int y = Suf(x);
		treap.del(st.qry(x, y));
	}
	if (x != Fir() && x != Lst()) {
		int y = Pre(x), z = Suf(x);
		treap.ins(st.qry(y, z));
	}
}

bool cmp(const pair <int, int> &a, const pair <int, int> &b) {
	ll sa = sum[a.second] - sum[a.first - 1];
	ll sb = sum[b.second] - sum[b.first - 1];
	if (sa == sb) return a < b;
	return sa > sb;
}

ll pre[N], suf[N];

// iterate over the rest [l,r] sum = S
// find the maximum sum covering all the uncovered index.
void solve() {
	set <int> :: iterator it;
	st.build(sum, n);
	pre[0] = 0; suf[n + 1] = -linf;
	for (int i = 1; i <= n; ++ i) pre[i] = min(pre[i - 1], sum[i]);
	for (int i = n; i; -- i) suf[i] = max(suf[i + 1], sum[i]);
	if (!uncover.empty()) {
		int lst = -1;
		for (it = uncover.begin(); it != uncover.end(); ++ it) {
			if (~lst) treap.ins(st.qry(lst, *it));
			lst = *it;
		}
	}
	ans2 = -linf;
	ll base = 0;
	sort(rem.begin(), rem.end(), cmp);
	for (int x = 0; x <= rem.size() && x + max(k - n, 0LL) <= k; ++ x) {
		int q = k - x - max(k - n, 0LL);
		ll cur;
		if (!q) {
			if (uncover.empty()) cur = 0;
			else cur = -linf;
		} else {
			if (uncover.empty()) cur = -linf;
			else {
				ll w = treap.kth(q - 1);
				if (w <= -linf) cur = -linf;
				else cur = suf[Lst()] - pre[Fir() - 1] - w;
			}
		}
#ifdef DEBUG
		cerr << "uncovered: ";
		for (it = uncover.begin(); it != uncover.end(); ++ it)
			cerr << *it << " "; cerr << endl;
		cerr << "treap: "; treap.dbg(treap.root); cerr << endl;
		cerr << ans1 << " + " << base << " + " << cur << endl;
#endif
		ans2 = max(ans2, base + cur);
		if (x == rem.size()) break;
		int l = rem[x].first, r = rem[x].second;
#ifdef DEBUG
		cerr << "	" << l << " " << r << endl;
#endif
		base += sum[r] - sum[l - 1];
		it = Find(l);
		while (it != uncover.end() && *it <= r) {
			Del(*it);
			set <int> :: iterator nit = it; ++ nit;
			uncover.erase(it); it = nit;
		}
	}
}

int main() {
#ifdef FILE
	assert(freopen("in", "r", stdin));
#endif
	read(n); read(k);
	for (int i = 1; i <= n; ++ i) {
		read(a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	precalc(); solve();
	printf("%lld\n", ans1 + ans2);
	return 0;
}