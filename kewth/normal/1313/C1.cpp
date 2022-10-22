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

const int maxn = 500005;
int a[maxn], b[maxn];
ll pre[maxn], suf[maxn];
int st[maxn], sp;

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++)
		a[i] = read;

	st[sp = 0] = 0;
	for(int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + a[i];
		while(sp and a[st[sp]] > a[i]) {
			pre[i] -= 1ll * (st[sp] - st[sp - 1]) * (a[st[sp]] - a[i]);
			-- sp;
		}
		st[++ sp] = i;
	}

	st[sp = 0] = n + 1;
	for(int i = n; i; i --) {
		suf[i] = suf[i + 1] + a[i];
		while(sp and a[st[sp]] > a[i]) {
			suf[i] -= 1ll * (st[sp - 1] - st[sp]) * (a[st[sp]] - a[i]);
			-- sp;
		}
		st[++ sp] = i;
	}

	ll ans = 0;
	for(int i = 1; i <= n; i ++)
		ans = std::max(ans, pre[i] + suf[i + 1]);

	for(int j = 1; j <= n; j ++)
		if(pre[j] + suf[j + 1] == ans) {
			st[sp = 0] = 0;
			for(int i = 1; i <= j; i ++) {
				while(sp and a[st[sp]] > a[i])
					-- sp;
				st[++ sp] = i;
			}

			while(sp) {
				for(int i = st[sp]; i > st[sp - 1]; i --)
					b[i] = a[st[sp]];
				-- sp;
			}

			st[sp = 0] = n + 1;
			for(int i = n; i > j; i --) {
				while(sp and a[st[sp]] > a[i])
					-- sp;
				st[++ sp] = i;
			}

			while(sp) {
				for(int i = st[sp]; i < st[sp - 1]; i ++)
					b[i] = a[st[sp]];
				-- sp;
			}

			break;
		}

	for(int i = 1; i <= n; i ++)
		printf("%d ", b[i]);
	puts("");

	for(int i = 1; i <= n; i ++)
		ans -= b[i];
	if(ans) return 1;
}