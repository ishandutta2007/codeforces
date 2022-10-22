#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 200005;
int b[maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read;
		std::fill(b, b + n, 0);
		for (int i = 0; i < n; i ++) {
			int x = read, y = (i + x) % n;
			if (y < 0) y += n;
			b[y] = 1;
		}
		for (int i = 0; i < n; i ++)
			if (!b[i]) {
				puts("NO");
				goto done;
			}
		puts("YES");
done:;
	}
}