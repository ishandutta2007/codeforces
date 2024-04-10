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

const int maxk = 60;
int tot[maxk + 1];

int main() {
	int t = read;
	while(t --) {
		for(int k = 0; k < maxk; k ++)
			tot[k] = 0;

		ll n = read, sum = 0;
		int m = read;
		while(m --) {
			int x = read;
			sum += x;
			for(int k = 0; k < maxk; k ++)
				if(x == (1 << k)) {
					++ tot[k];
					break;
				}
		}

		if(sum < n) {
			puts("-1");
			continue;
		}

		int ans = 0;
		for(int i = 0; i < maxk; i ++) {
			if(n >> i & 1)
				-- tot[i];
			if(tot[i] < 0) {
				-- tot[i + 1];
				tot[i] += 2;
				++ ans;
			}
			tot[i + 1] += tot[i] >> 1;
			tot[i] &= 1;
		}

		printf("%d\n", ans);
	}
}