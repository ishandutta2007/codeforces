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

const int maxn = 400005, maxk = 25;
int a[maxn];
int a0[maxn], a1[maxn];

int cmp_k;
bool cmp(int x, int y) {
	return (x & cmp_k) < (y & cmp_k);
}

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++)
		a[i] = read;

	int ans = 0;
	for(int k = 0; k < maxk; k ++) {
		int p0 = 0, p1 = 0;
		for(int i = 1; i <= n; i ++)
			if(a[i] >> k & 1)
				a1[++ p1] = a[i];
			else
				a0[++ p0] = a[i];

		cmp_k = (1 << k) - 1;
		std::sort(a0 + 1, a0 + p0 + 1, cmp);
		std::sort(a1 + 1, a1 + p1 + 1, cmp);

		ll t = 0;

		for(int i = 1, j = p0; i <= p0; i ++) {
			while(j > i and (a0[i] & cmp_k) + (a0[j] & cmp_k) > cmp_k)
				-- j;
			t += p0 - std::max(i, j);
		}

		for(int i = 1, j = p1; i <= p1; i ++) {
			while(j > i and (a1[i] & cmp_k) + (a1[j] & cmp_k) > cmp_k)
				-- j;
			t += p1 - std::max(i, j);
		}

		for(int i = 1, j = p1; i <= p0; i ++) {
			while(j > 0 and (a0[i] & cmp_k) + (a1[j] & cmp_k) > cmp_k)
				-- j;
			t += j;
		}

		if(t & 1) ans |= 1 << k;
	}

	printf("%d\n", ans);
}