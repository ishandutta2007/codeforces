#if 0
date +%Y.%m.%d

 x = 1..12..2...9..9 
 x = 1.....1 + 0..01....1 + 0.....01...1 + .... + 0.....01..1 (emm) 
 12335 = 11111 + 1111 + 111 + 1 
 1 ~ 9  k  x  j  k 
 k  x  1...1 (j  1) 

 k  x  DP  k 
 f[i][j]  i  j  k  n 
 n 
#endif
#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 707, mod = 1000000007;
char s[maxn];
int count[maxn][10];
ll f[maxn][maxn * 10];
ll a[maxn];

int main() {
	scanf("%s", s + 1);
	int n = int(strlen(s + 1));

	for(int i = 1; i <= n; i ++) {
		for(int x = 0; x < 10; x ++)
			count[i][x] = count[i - 1][x];
		++ count[i][s[i] - '0'];
	}

	for(int i = 1; i <= n; i ++)
		a[i] = (a[i - 1] * 10 + 1) % mod;

	ll ans = 0;
	for(int X = 1; X <= 9; X ++) {
		for(int i = 1; i <= n; i ++) {
			int cnt = 0;
			for(int x = X; x < 10; x ++) cnt += count[i - 1][x];
			f[i][0] = X * f[i - 1][0] % mod;
			for(int j = 1; j <= i * 10; j ++)
				f[i][j] = ((10 - X) * f[i - 1][j - 1] + X * f[i - 1][j]) % mod;
			for(int x = 0; x < s[i] - '0'; x ++)
				++ f[i][cnt + (x >= X)];
		}
		for(int j = 0; j <= n * 10; j ++)
			(ans += f[n][j] * a[j]) %= mod;
	}

	for(int x = 1; x <= 9; x ++) {
		int tot = 0;
		for(int i = 1; i <= n; i ++)
			tot += s[i] - '0' >= x;
		ans += a[tot];
	}
	ans %= mod;

	printf("%lld\n", ans);
}