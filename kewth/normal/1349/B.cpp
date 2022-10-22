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

const int maxn = 100005;
int s1[maxn], s2[maxn], sp;

void update () {
	if (sp == 1) return;
	int a = s2[sp - 1], b = s2[sp - 2] + s2[sp];
	if (b > a) {
		sp = std::max(sp - 3, 0);
		s1[++ sp] = 1;
		s2[sp] = a + b;
		update();
	}
}

int a[maxn];

int main () {
	// XXX:
	int T = read;
	while (T --) {
		int n = read, k = read, tot = 0;
		for (int i = 1; i <= n; i ++) {
			int x = read;
			if (x == k) a[i] = 1, ++ tot;
			if (x < k) a[i] = -1;
			if (x > k) a[i] = 1;
		}

		if (!tot) {
			puts("no");
			goto shit;
		}

		if (n == 1) {
			puts("yes");
			goto shit;
		}

		for (int i = 1; i + 1 <= n; i ++)
			if (a[i] == 1 and a[i + 1] == 1) {
				puts("yes");
				goto shit;
			}

		for (int i = 1; i + 2 <= n; i ++)
			if (a[i] == 1 and a[i + 2] == 1) {
				puts("yes");
				goto shit;
			}

		puts("no");

		/* sp = 1; */
		/* s1[1] = a[1]; */
		/* s2[1] = 1; */
		/* for (int i = 2; i <= n; i ++) */
		/* 	if (a[i] == 1) { */
		/* 		if (s1[sp] == 1) { */
		/* 			++ s2[sp]; */
		/* 		} else { */
		/* 			s1[++ sp] = 1; */
		/* 			s2[sp] = 1; */
		/* 		} */
		/* 		update(); */
		/* 	} else { */
		/* 		if (s1[sp] == -1) { */
		/* 			++ s2[sp]; */
		/* 		} else { */
		/* 			if (s2[sp] == 1) { */
		/* 				s1[++ sp] = -1; */
		/* 				s2[sp] = 1; */
		/* 			} else { */
		/* 				++ s2[sp]; */
		/* 				update(); */
		/* 			} */
		/* 		} */
		/* 	} */

		/* if (s1[1] == 1 and s2[1] == n) puts("yes"); */
		/* else puts("no"); */

shit:;
	}
}