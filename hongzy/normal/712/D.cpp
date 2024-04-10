#include <algorithm>
#include <cstdio>
using namespace std;

const int mo = 1e9 + 7;
const int N = 4e5 + 10; //max(score)

int a, b, k, t, f[N], g[N]; //f[i] = total(score = i), g[i] = total(score <= i)
int fac[N], fav[N];

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = 1ll * a * a % mo)
		if(b & 1) ans = ans * 1ll * a % mo;
	return ans;
} 

int c(int a, int b) {
	return a < b ? 0 : fac[a] * 1ll * fav[b] % mo * fav[a - b] % mo;
}
long long pw(int x) { //(-1)^x 
	return (x & 1) ? -1ll : 1ll;
}
int calc(int a) { //ai \in [1, 2k + 1], sum = a, 
	int ans = 0;
	for(int i = 0; i <= t; i ++) { //>=i(>= 2k + 2 ,  2k+1
		int sum = a - (2 * k + 1) * i;
		(ans += pw(i) * c(t, i) * c(sum - 1, t - 1) % mo) %= mo;
	}
	return (ans + mo) % mo;
}
int main() {
	scanf("%d%d%d%d", &a, &b, &k, &t);
	int m = (2 * k + 1) * t;
	fac[0] = 1;
	for(int i = 1; i < N; i ++) {
		fac[i] = fac[i - 1] * 1ll * i % mo;
	}
	fav[N - 1] = qpow(fac[N - 1], mo - 2);
	for(int i = N - 1; i >= 1; i --) {
		fav[i - 1] = fav[i] * 1ll * i % mo;
	}
	for(int i = t; i <= m; i ++) { //total: \sum_ai = i -> C(i - 1, t - 1)
		f[i] = calc(i);
		g[i] = (g[i - 1] + f[i]) % mo;
//		printf("f[%d] = %d, g[%d] = %d\n", i, f[i], i, g[i]);
	}
	int ans = 0;
	for(int i = t; i <= m; i ++) {
		if(a - b + i - 1 < t) continue ;
		int x = min(a - b + i - 1, m);
		(ans += f[i] * 1ll * g[x] % mo) %= mo;
	}
	printf("%d\n", ans);
	return 0;
}
/*
[1, 2k + 1]
a + i > b + j
j < a - b + i
t[1, 2k + 1] -> sum = i
C(i - 1, t - 1)
k_{1} <= 2k + 1 
k_{i} - k_{i - 1} <= 2k + 1 
(x+x^2+x^3+..+x^{n}) ^ m
*/