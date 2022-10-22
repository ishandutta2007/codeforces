#if 0
date +%Y.%m.%d



#endif
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

const int maxn = 205;
int a[maxn][maxn], r[maxn], c[maxn];

int main() {
	int n = read, m = read;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			a[i][j] = read;

	for(int x = 0; x <= m; x ++) {
		for(int o = 0; o < 2; o ++) {
			r[1] = o;
			for(int j = 1; j <= x; j ++)
				c[j] = a[1][j] ^ r[1] ^ 0;
			for(int j = x + 1; j <= m; j ++)
				c[j] = a[1][j] ^ r[1] ^ 1;

			bool get = x < m;
			for(int i = 2; i <= n; i ++)
				if(get) {
					r[i] = a[i][1] ^ c[1] ^ 1;
					for(int j = 1; j <= m; j ++)
						if((a[i][j] ^ r[i] ^ c[j]) == 0)
							goto fail;
				} else {
					r[i] = a[i][1] ^ c[1] ^ 0;
					int find_one = m + 1;
					for(int j = m; j; j --)
						if((a[i][j] ^ r[i] ^ c[j]) == 1)
							find_one = j;
					for(int j = find_one; j <= m; j ++)
						if((a[i][j] ^ r[i] ^ c[j]) == 0)
							goto fail;
					get |= find_one <= m;
				}

			puts("YES");
			for(int i = 1; i <= n; i ++)
				printf("%d", r[i]);
			puts("");
			for(int j = 1; j <= m; j ++)
				printf("%d", c[j]);
			puts("");

			return 0;
fail:;
		}
	}

	puts("No");
}