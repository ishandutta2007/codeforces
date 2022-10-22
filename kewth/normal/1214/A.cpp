#if 0
2019.09.04

 O(n)  DP 
#endif
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 100000005;
bool f[maxn + 1000];

int main() {
	int n = input(), a = input(), b = input() * 5;
	f[n] = true;
	int ans = n;
	for(int i = n - 1; i >= 0; i --)
		if(f[i + a] or f[i + b]) {
			f[i] = true;
			ans = i;
		}
	printf("%d\n", ans);
}