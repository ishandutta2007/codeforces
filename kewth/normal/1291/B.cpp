#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 300005;
int a[maxn];

int main() {
	int T = read;
	while(T --) {
		int n = read;
		for(int i = 1; i <= n; i ++)
			a[i] = read;

		for(int i = 1; i <= n; i ++)
			if(a[i] < i - 1) {
				if(n % 2 == 0 and i == n / 2 + 1 and
						a[i - 1] < i - 1) {
					puts("No");
					goto OK;
				}
				for(int j = i; j <= n; j ++)
					if(a[j] < n - j) {
						puts("No");
						goto OK;
					}
				puts("Yes");
				goto OK;
			}
		puts("Yes");
OK:;
	}
}