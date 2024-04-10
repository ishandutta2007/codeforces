#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 1000005, mod = 1000000007;
char s[maxn];

int main() {
	int T = read;
	while(T --) {
		int m = read;
		scanf("%s", s + 1);
		int n = int(strlen(s + 1));
		ll las = n;
		bool mark = 0;
		for(int i = 1; i <= m; i ++) {
			ll tmp = (las + mod - i) % mod;
			ll now = (i + tmp * (s[i] - '0')) % mod;
			if(las >= m) mark = 1;
			if(!mark)
				for(int j = 1; j <= now - las and las + j <= m; j ++)
					s[las + j] = s[las + j - tmp];
			las = now;
		}
		printf("%lld\n", las);
	}
}