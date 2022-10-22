#if 0
date


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

const int maxn = 100005;
int a[maxn];

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++)
		a[i] = read;

	for(int k = 30; k >= 0; k --) {
		int tot = 0, p = 0;
		for(int i = 1; i <= n; i ++)
			if(a[i] >> k & 1) {
				p = i;
				++ tot;
			}
		if(tot == 1) {
			std::swap(a[p], a[1]);
			break;
		}
	}

	for(int i = 1; i <= n; i ++)
		printf("%d ", a[i]);
	puts("");
}