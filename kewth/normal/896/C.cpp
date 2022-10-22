#if 0
date +%Y.%m.%d

 odt  odt 
 odt k  O(n / k) 

#endif
#include <cstdio>
#include <algorithm>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	/* inline operator ll () { ll x; return scanf("%lld", &x), x; } */
	/* template<class T> inline void operator () (T &x) { x = *this; } */
	/* template<class T, class ...A> inline void operator () (T &x, A &...a) */
	/* { x = *this; this -> operator ()(a...); } */
} read;

inline ll power(ll x, int k, int mod) {
	ll res = 1;
	while(k) {
		if(k & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return res;
}

struct Node {
	int l, r;
	mutable ll v;
	Node(int l = 0, int r = 0, ll v = 0): l(l), r(r), v(v) { }
};
bool operator < (Node x, Node y) { return x.l < y.l; }

typedef std::set<Node>::iterator iter;
std::set<Node> odt;

iter split(int x) {
	iter it = -- odt.upper_bound(x);
	if(it -> l == x) return it;
	if(x > it -> r) return odt.end();
	int l = it -> l, r = it -> r;
	ll v = it -> v;
	odt.erase(it);
	odt.insert(Node(l, x - 1, v));
	return odt.insert(Node(x, r, v)).first;
}

const int maxn = 100005;
Node tmp[maxn];
int main() {
	int n = read, q = read, seed = read, max = read;

	auto rnd = [&]() {
		int res = seed;
		seed = (seed * 7ll + 13) % 1000000007;
		return res;
	};

	for(int i = 1; i <= n; i ++)
		odt.insert(Node(i, i, rnd() % max + 1));

	while(q --) {
		int op = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1;
		if(l > r) std::swap(l, r);
		// It's quite import! Otherwise the iterator "begin" may be gangerous
		/* iter begin = split(l), end = split(r + 1); */
		iter end = split(r + 1), begin = split(l);

		if(op == 1) {
			int x = rnd() % max + 1;
			for(iter it = begin; it != end; ++ it)
				it -> v += x;
		}

		if(op == 2) {
			odt.erase(begin, end);
			odt.insert(Node(l, r, rnd() % max + 1));
		}

		if(op == 3) {
			int p = 0;
			for(iter it = begin; it != end; ++ it)
				tmp[++ p] = *it;
			int k = rnd() % (r - l + 1) + 1;
			std::sort(tmp + 1, tmp + p + 1, [](Node x, Node y) {
						return x.v > y.v;
					});
			while(p and k > tmp[p].r - tmp[p].l + 1) {
				k -= tmp[p].r - tmp[p].l + 1;
				-- p;
			}
			printf("%lld\n", tmp[p].v);
		}

		if(op == 4) {
			int x = rnd() % max + 1, mod = rnd() % max + 1;
			ll ans = 0;
			for(iter it = begin; it != end; ++ it)
				(ans += power(it -> v % mod, x, mod) * (it -> r - it -> l + 1)) %= mod;
			printf("%lld\n", ans);
		}
	}
}