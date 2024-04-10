#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define pb push_back

const int mo = 1e9 + 7;
const int N = 1010;

int n, m, a[N], ans = 1;
int fac[N], fav[N], pw[N];
vector<int> b, c;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = 1ll * a * a % mo)
		if(b & 1) ans = 1ll * ans * a % mo;
	return ans;
}

int main() {
	fac[0] = pw[0] = 1;
	scanf("%d%d", &n, &m);
	if(n == m) {
		puts("1"); return 0;
	}
	for(int i = 1; i < N; i ++)
		fac[i] = fac[i - 1] * 1ll * i % mo;
	fav[N - 1] = qpow(fac[N - 1], mo - 2);
	for(int i = N - 1; i >= 1; i --)
		fav[i - 1] = 1ll * fav[i] * i % mo;
	for(int i = 1; i < N; i ++)
		pw[i] = pw[i - 1] * 2ll % mo;
	for(int i = 1; i <= m; i ++) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + m + 1);
	int ans = fac[n - m];
	for(int i = 1; i <= m + 1; i ++) {
		if(i == 1 && a[1] > 1) {
			b.pb(a[1] - 1); c.pb(1);
		}
		if(i == m + 1 && a[m] < n) {
			b.pb(n - a[m]); c.pb(1);
		}
		if(i > 1 && i <= m && a[i] - a[i - 1] >= 2) {
			b.push_back(a[i] - a[i - 1] - 1); c.pb(2);
		}
	}
	for(int i = 0; i < b.size(); i ++) {
//		printf("(%d, %d)\n", b[i], c[i]);
		ans = ans * 1ll * fav[b[i]] % mo;
		if(c[i] == 2) {
			ans = ans * 1ll * pw[b[i] - 1] % mo;
		}
	}
	printf("%d\n", ans);
	return 0;
}