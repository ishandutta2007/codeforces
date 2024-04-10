/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  echo -n '  ' && date +%Y.%m.%d

 * Solution:
  

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 200005;
par po[maxn];
int tmp[maxn], tp;
int a[maxn];
int seg[maxn << 2];
#define ls (now << 1)
#define rs (now << 1 | 1)

void modify (int now, int L, int R, int p) {
	if (L == R)
		return seg[now] = 1, void();
	int M = (L + R) >> 1;
	if (p <= M) modify(ls, L, M, p);
	else modify(rs, M + 1, R, p);
	seg[now] = seg[ls] + seg[rs];
}

int query (int now, int L, int R, int l, int r) {
	if (r < L or l > R) return 0;
	if (l <= L and R <= r) return seg[now];
	int M = (L + R) >> 1;
	return query(ls, L, M, l, r) + query(rs, M + 1, R, l, r);
}

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) {
		tmp[++ tp] = po[i].second = read;
		read(po[i].first);
	}

	std::sort(tmp + 1, tmp + tp + 1);
	std::sort(po + 1, po + n + 1);

	for (int i = 1; i <= n; i ++)
		a[i] = int(std::lower_bound(tmp + 1, tmp + tp + 1, po[i].second) - tmp);

	ll ans = 0;
	for (int r = n, l; r; r = l - 1) {
		l = r;
		while (l > 1 and po[l - 1].first == po[l].first) -- l;
		std::sort(a + l, a + r + 1);
		for (int i = l; i <= r; i ++)
			modify(1, 1, tp, a[i]);
		for (int i = l; i <= r; i ++) {
			int x = query(1, 1, tp, i == l ? 1 : a[i - 1] + 1, a[i]);
			int y = query(1, 1, tp, a[i], tp);
			ans += 1ll * x * y;
		}
	}

	printf("%lld\n", ans);
}