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

const int maxn = 3505;
int a[maxn];
bool b[maxn];

bool check(int n, int m, int k) {
	for(int l = 1; l <= k + 1; l ++) {
		int r = l + n - k - 1;
		int d = n - m;
		for(int i = l; i + d <= r; i ++)
			if(!b[i] and !b[i + d])
				goto FAIL;
		return 1;
FAIL:;
	}
	return 0;
}

int main() {
	int T = read;
	while(T --) {
		int n = read, m = read, k = std::min(int(read), m - 1);
		for(int i = 1; i <= n; i ++)
			a[i] = read;

		int l = 1, r = 1000000000;
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			for(int i = 1; i <= n; i ++)
				b[i] = a[i] >= mid;
			if(check(n, m, k))
				l = mid;
			else
				r = mid - 1;
		}

		printf("%d\n", l);
	}
}