#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 105;
char s[maxn];

int main() {
	int t = read;
	while(t --) {
		scanf("%s", s + 1);
		int n = int(strlen(s + 1));

		int l = 1, r = n;
		while(s[l] == '0') ++ l;
		while(s[r] == '0') -- r;

		int ans = 0;
		for(int i = l; i <= r; i ++)
			ans += s[i] == '0';
		printf("%d\n", ans);
	}
}