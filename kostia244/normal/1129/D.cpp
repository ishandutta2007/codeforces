// Problem: D. Isolation
// Contest: Codeforces - Codeforces Round #542 [Alex Lopashev Thanks-Round] (Div. 1)
// URL: https://codeforces.com/contest/1129/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int maxn = 1e5 + 15;
#include<immintrin.h>
using reg = __m256i;
alignas(64) int n, k, a[maxn], b[maxn], dp[maxn], x[maxn], y[maxn], tmp[8];
inline __attribute__(( always_inline )) void upd(int x, int y, int v) {
	reg A, f = _mm256_set1_epi32(v);
	for(; (x&7) && x < y; x++)
		b[x] += v;
	for(; x+7 < y; x+=8) {
		A = _mm256_load_si256((reg*)&b[x]);
		A = _mm256_add_epi32(A, f);
		_mm256_store_si256((reg*)&b[x], A);
	}
	for(; x < y; x++)
		b[x] += v;
}
inline __attribute__(( always_inline )) int calc(int pos) {
	reg res, A, B, K = _mm256_set1_epi32(k+1),
		MOD = _mm256_set1_epi32(998244353),
		RES = _mm256_set1_epi32(0);
	for(int i = 0; i <= pos; i+=8) {
		A = _mm256_load_si256((reg*)&dp[i]);
		B = _mm256_load_si256((reg*)&b[i]);
		B = _mm256_cmpgt_epi32(K, B);
		B = _mm256_and_si256(B, A);
		RES = _mm256_add_epi32(RES, B);
		B = _mm256_cmpgt_epi32(RES, MOD);
		B = _mm256_and_si256(B, MOD);
		RES = _mm256_sub_epi32(RES, B);
	}
	int ans = 0;
	_mm256_store_si256((reg*)&tmp[0], RES);
	for(int i = 0; i < 8; i++) {
		ans += tmp[i];
		if(ans >= 998244353) ans -= 998244353;
	}
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	dp[0] = 1;
	for(int i = 0; i < n; i++) {
		upd(y[a[i]], x[a[i]], -1);
		y[a[i]] = x[a[i]];
		x[a[i]] = i+1;
		upd(y[a[i]], x[a[i]], 1);
		dp[i+1] = calc(i);
	}
	cout << dp[n]%998244353 << '\n';
}