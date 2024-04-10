#if 0
date +%Y.%m.%d

 DP  f[i][j]  i  j 
 f[i][j] = f[g[i][j]][j - 1] + w(g[i][j] + 1, i) 
 g[i][j] w(l, r)  [l, r] 
 g[i][j]  i  DP 
 w  w 

#endif
#include <cstdio>
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

const int maxn = 100005, maxk = 22;
int a[maxn];
ll f[maxn][maxk];
int tot[maxn];

int wl = 1, wr = 0;
ll wans = 0;
ll W(int l, int r) {
	while(l < wl) wans += tot[a[-- wl]] ++;
	while(r > wr) wans += tot[a[++ wr]] ++;
	while(l > wl) wans -= -- tot[a[wl ++]];
	while(r < wr) wans -= -- tot[a[wr --]];
	return wans;
}

void solve(int k, int l, int r, int L, int R) {
	if(L == R) {
		for(int i = l; i <= r; i ++)
			f[i][k] = f[L][k - 1] + W(L + 1, i);
		return;
	}
	if(l > r) return;
	int mid = (l + r) >> 1;
	int g = L;
	for(int j = L; j <= R and j < mid; j ++)
		if(f[j][k - 1] + W(j + 1, mid) < f[mid][k])
			f[mid][k] = f[g = j][k - 1] + W(j + 1, mid);
	solve(k, l, mid - 1, L, g);
	solve(k, mid + 1, r, g, R);
}

int main() {
	int n = read, m = read;
	for(int i = 1; i <= n; i ++)
		read(a[i]);

	for(int i = 0; i <= n; i ++)
		for(int k = 0; k <= m; k ++)
			f[i][k] = 1000000000000000000;
	f[0][0] = 0;

	for(int k = 1; k <= m; k ++)
		solve(k, 1, n, 0, n - 1);

	printf("%lld\n", f[n][m]);
}