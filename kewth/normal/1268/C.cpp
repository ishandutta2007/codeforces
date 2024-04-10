#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 200005;
int bit[maxn];

int query(int l, int r) {
	int res = 0;
	for(int k = r; k; k -= k & -k)
		res += bit[k];
	for(int k = l - 1; k; k -= k & -k)
		res -= bit[k];
	return res;
}

void modify(int p, int n) {
	for(int k = p; k <= n; k += k & -k)
		++ bit[k];
}

int a[maxn], p[maxn];
std::set<int> set;

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++)
		p[a[i] = read] = i;

	int cen = p[1];
	ll ans = 0;
	modify(cen, n);
	set.insert(cen);
	printf("0");

	for(int x = 2; x <= n; x ++) {
		int np = p[x];
		modify(np, n);
		set.insert(np);
		ans += query(np + 1, n);
		int l = query(1, cen - 1), r = query(cen + 1, n);
		if(np > cen) {
			ans += np - cen + 1 - query(cen, np);
			ans -= query(np + 1, n);
			while(r > l) {
				int to = *set.upper_bound(cen);
				++ l;
				ans += 1ll * (to - cen - 1) * (l - r);
				-- r;
				cen = to;
				/* debug("%d -> %d\n", cen, to); */
			}
		}
		else {
			ans += cen - np + 1 - query(np, cen);
			ans -= query(1, np - 1);
			while(l > r) {
				int to = *(-- set.lower_bound(cen));
				++ r;
				ans += 1ll * (cen - to - 1) * (r - l);
				-- l;
				cen = to;
				/* debug("%d -> %d\n", cen, to); */
			}
		}
		printf(" %lld", ans);
		/* debug("cen = %d (%d %d)\n", cen, l, r); */
	}
	puts("");
}