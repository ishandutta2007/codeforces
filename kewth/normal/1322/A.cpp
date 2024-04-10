#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 1000005;
char s[maxn];

int main() {
	int n = read;
	scanf("%s", s + 1);

	int ans = 0;
	for(int l = 1, r; l <= n; l = r + 1) {
		int t = s[l] == '(' ? 1 : -1;
		r = l;
		while(r < n and t > 0)
			t += s[++ r] == '(' ? 1 : -1;

		if(t < 0) {
			while(r < n and t < 0)
				t += s[++ r] == '(' ? 1 : -1;
			ans += r - l + 1;
		}

		if(t) return puts("-1"), 0;
	}

	printf("%d\n", ans);
}