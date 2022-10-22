#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long lolong;

inline int input() { int x; scanf("%d", &x); return x; }
inline lolong linput() { lolong x; scanf("%lld", &x); return x; }

int main() {
	int T = input();
	while(T --) {
		int a = input(), b = input(), c = input(), d = input(), k = input();
		int x = (a + c - 1) / c;
		int y = (b + d - 1) / d;
		if(x + y <= k)
			printf("%d %d\n", x, y);
		else
			puts("-1");
	}
}