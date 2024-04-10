/*
 * Author: Kewth

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Type "!!sh" in Vim.

 * Solution:
  To be updated after "Accept".

 * Digression:

 * CopyRight:
   __  __                  __   __
  |  |/  |.-----.--.--.--.|  |_|  |--.
  |     < |  -__|  |  |  ||   _|     |
  |__|\__||_____|________||____|__|__|

 */

#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

static struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 8005, maxc = 26, mod = 1000000007;
char s[maxn];
int tmp[maxc];
int las[maxn];
ll f[maxn];

int main () {
	int n = read;
	scanf("%s", s + 1);

	for (int i = 1; i <= n; i ++) {
		las[i] = tmp[s[i] - 'a'];
		tmp[s[i] - 'a'] = i;
		if (!las[i])
			f[i] = 1;
	}

	for (int i = 2; i <= n; i ++) {
		for (int j = 1; j <= n; j ++)
			f[j] += f[j - 1];
		for (int j = n; j; j --)
			f[j] = (f[j] - f[las[j]]) % mod;
		f[0] = 0;
	}

	ll ans = 0;
	for (int j = 0; j <= n; j ++)
		ans += f[j];
	printf("%lld\n", ans % mod);
}