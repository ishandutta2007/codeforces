#if 0
2019.09.04
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

inline int input() { int x; scanf("%d", &x); return x; }

int main() {
	int a = input(), b = input(), n = input();
	printf("%d\n", std::min(a, n) - std::max(0, n - b) + 1);
}