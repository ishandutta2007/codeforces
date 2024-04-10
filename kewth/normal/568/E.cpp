#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 100005;
int a[maxn], b[maxn];
int f[maxn], g[maxn];
int len[maxn], pre[maxn];
int tmp[maxn];
bool vis[maxn];

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++)
		a[i] = read;

	int m = read;
	for(int i = 1; i <= m; i ++)
		b[i] = read;
	std::sort(b + 1, b + m + 1);

	for(int i = 1; i <= n + 1; i ++)
		f[i] = 1000000005;

	int max = 0, now = 1;
	for(int i = 1; i <= n; i ++) {
		int nlen = 1;
		if(a[i] == -1) {
			for(int j = 1; j <= m; j ++) {
				while(f[nlen] < b[j])
					++ nlen;
				tmp[j] = nlen;
			}
			for(int j = 1; j <= m; j ++)
				if(tmp[j] > tmp[j - 1]) {
					f[tmp[j]] = b[j];
					g[tmp[j]] = i;
				}
		}
		else {
			nlen = int(std::lower_bound(f, f + n + 1, a[i]) - f);
			f[nlen] = a[i];
			g[nlen] = i;
			pre[i] = g[nlen - 1];
			len[i] = nlen;
		}
		if(nlen > max) {
			max = nlen;
			now = i;
		}
	}

	int nxt = 1000000005, pos = max;
	while(now) {
		// debug("%d\n", now);
		if(a[now] == -1) {
			int p = int(std::lower_bound(b + 1, b + m + 1, nxt) - b - 1);
			// debug(" p = %d\n", p);
			a[now] = b[p];
			vis[p] = 1;
			for(int i = 1; i < now; i ++)
				if(~a[i] and a[i] < a[now] and len[i] == pos - 1) {
					pre[now] = i;
					break;
				}
			if(!pre[now])
				for(int i = 1; i < now; i ++)
					if(a[i] == -1)
						pre[now] = i;
		}
		nxt = a[now];
		now = pre[now];
		-- pos;
	}

	for(int i = 1, j = 1; i <= n; i ++) {
		if(a[i] == -1) {
			while(vis[j]) ++ j;
			a[i] = b[j ++];
		}
		printf("%d ", a[i]);
	}
	puts("");
}