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

int main() {
	int t = read;
	while(t --) {
		int n = read, m = read, L = m, R = m, T = 0;
		bool ans = 1;
		while(n --) {
			int t = read, l = read, r = read;
			L = std::max(l, L - (t - T));
			R = std::min(r, R + (t - T));
			T = t;
			if(L > R)
				ans = 0;
		}
		puts(ans ? "YES" : "NO");
	}
}