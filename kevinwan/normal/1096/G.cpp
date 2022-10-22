#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;
ll a[1<<20],t[1<<20];
ll p(ll a, ll b) {
	ll ans = 1;
	for (; b; b >>= 1, a = a * a%mod)if (b & 1)ans = ans * a%mod;
	return ans;
}
ll w[1 << 20];
int rev(int x, int n) {
	int ret = 0;
	for (int i = 0; i < n; i++)ret += ((x >> i) & 1) << n - i - 1;
	return ret;
}
void fft(ll ar[], int n, bool inv=0) {
	int N = 1 << n, m = N - 1,i,j,k;
	w[0] = 1;
	w[1] = p(3, mod >> n);
	for (i = 2; i < N; i++)w[i] = w[i - 1] * w[1] % mod;
	if (inv)for (i = 1; i < N >> 1; i++)swap(w[i], w[N - i]);
	for (i = 0; i < N; i++)t[rev(i, n)] = ar[i];
	memcpy(ar, t, sizeof(ar[0])<<n);
	ll sc = N >> 1;
	for (i = 0; i < n; i++,sc>>=1) {
		for (j = 0; j < N; j++) {
			if (j&(1 << i))continue;
			k = j | (1 << i);
			ll aa = (ar[j] + ar[k] * w[(sc*j)&m]) % mod;
			ll bb = (ar[j] + ar[k] * w[(sc*k)&m]) % mod;
			ar[j] = aa;
			ar[k] = bb;
		}
	}
	ll q = p(N, mod - 2);
	if (inv)for (i = 0; i < N; i++)ar[i] = ar[i] * q%mod;
}
int main() {
	int n,k,i,x;
	scanf("%d%d", &n, &k);
	for (i = 0; i < k; i++)scanf("%d", &x), a[x] = 1;
	fft(a, 20, 0);
	for (i = 0; i < 1 << 20; i++)a[i] = p(a[i], n / 2);
	fft(a, 20, 1);
	ll ans = 0;
	for (i = 0; i < 1 << 20; i++)ans = (ans + a[i] * a[i]) % mod;
	printf("%lld", ans);
}