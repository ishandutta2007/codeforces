#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 998244353;
int fact[maxn], inv[maxn];
void setup() {
	for(int i = 0; i < maxn; i++) {
		if(i < 2) fact[i] = inv[i] = 1;
		else {
			fact[i] = fact[i-1]*1ll*i%mod;
			inv[i] = mod - (mod/i)*1ll*inv[mod%i]%mod;
		}
	}
	for(int i = 1; i < maxn; i++) inv[i] = inv[i] * 1ll * inv[i-1]%mod;
}
int nck(int n, int k) {
	if(k > n || n < 0) return 0;
	int t = fact[n] * 1ll * inv[k] % mod;
	return t * 1ll * inv[n-k]%mod;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	setup();
	int n;
	string s;
	cin >> s;
	n = s.size();
	int op = 0, cl = 0;
	for(auto &i : s) {
		if(i == '(') op++;
		if(i == ')') cl++;
	}
	ll ans = 0, cop = 0, cqq = 0;
	for(int p = 0, k = cl; k <= n-op; k++) {
		while(p < k) {
			cop += s[p] == '(';
			cqq += s[p] == '?';
			p++;
		}
		(ans += nck(n-op-cl-1, k-cl)*1ll*cqq) %= mod;
		(ans += nck(n-op-cl, k-cl)*1ll*cop) %= mod;
	}
	cout << ans << '\n';
}