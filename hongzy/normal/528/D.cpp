#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1 << 20 | 5;
const int mo = 998244353;
int n, m, k, lim, r[N], w[2][N], a[N], ans[N];
char ns[N], t[N];
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = 1ll * a * a % mo)
		if(b & 1) ans = 1ll * ans * a % mo;
	return ans;
}
void init(int n) {
	int l = 0;
	for(lim = 1; lim <= n; lim <<= 1) l ++;
	for(int i = 1; i < lim; i ++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	for(int i = 1; i < lim; i <<= 1) {
		w[0][i] = qpow(3, (mo - 1) / (i << 1));
		w[1][i] = qpow(w[0][i], mo - 2);
	}
}
void ntt(int *a, int t) {
	for(int i = 0; i < lim; i ++)
		if(i < r[i]) swap(a[i], a[r[i]]);
	for(int i = 1; i < lim; i <<= 1) {
		int x = w[t == -1][i];
		for(int j = 0; j < lim; j += i << 1) {
			int y = 1;
			for(int k = 0; k < i; k ++, y = 1ll * y * x % mo) {
				int p = a[j + k], q = 1ll * y * a[j + k + i] % mo;
				a[j + k] = (p + q) % mo; a[j + k + i] = (p - q + mo) % mo;
			}
		}
	}
}
int *mul(int *a, int *b, int m, int n) {
	static int A[N], B[N];
	for(int i = 0; i < lim; i ++) A[i] = i <= m ? a[i] : 0;
	for(int i = 0; i < lim; i ++) B[i] = i <= n ? b[i] : 0;
	ntt(A, 1); ntt(B, 1);
	for(int i = 0; i < lim; i ++) A[i] = 1ll * A[i] * B[i] % mo;
	ntt(A, -1); int inv_n = qpow(lim, mo - 2);
	for(int i = 0; i <= n + m; i ++) A[i] = 1ll * A[i] * inv_n % mo;
	return A;
}
void work(char C) {
	static int A[N], B[N];
	int la = -1e9 + 10;
	for(int i = 0; i <= n; i ++) {
		if(ns[i] == C) la = i;
		A[i] = i - la <= k;
	}
	la = 1e9 + 10;
	for(int i = n; i >= 0; i --) {
		if(ns[i] == C) la = i;
		A[i] |= la - i <= k;
	}
	for(int i = 0; i <= m; i ++) B[m - i] = t[i] == C;
	int *to = mul(A, B, n, m);
	for(int i = m; i <= n + m; i ++) ans[i - m] += to[i];
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s%s", ns, t); n --; m --;
    int res = 0;
    init(n + m); work('A'); work('T'); work('G'); work('C');
    for(int i = 0; i <= n - m; i ++)
    	if(ans[i] == m + 1) res ++;
    printf("%d\n", res);
	return 0;
}
/*
letter A:
ans(u) = \sum_{i = 0}^m [s[u + i] == A] * [t[i] == A]
ans(u + m) = \sum_{i = 0}^m a[u + i] * b[m - i]
*/