#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse4,popcnt,tune=native")
#include<bits/stdc++.h>
#include<immintrin.h>
using reg = __m256i;
using namespace std;
using ll = long long;
const int maxn = 1<<17;
alignas(32) int n, q, a[maxn], tmp[8];
#define load(x, p) x.mm = _mm256_loadu_si256((reg*) &(p))
#define store(x, p) _mm256_storeu_si256((reg*) &(p), x.mm)

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> q;
	int cmd, l, r, k, t, ans = 0;
	while(q--) {
		cin >> cmd >> l >> r;
		l = (n + l + ans - 1) % n;
		r = (n + r + ans - 1) % n;
		if (l > r)
			swap(l, r);
		if(cmd == 1) {
			t = a[r];
			int p = r;
			reg r;
			for(; p - 7 > l; p -= 8) {
				r = _mm256_loadu_si256((reg*) &a[p-8]);
				_mm256_storeu_si256((reg*) &a[p-7], r);
			}
			for(; p > l; p--) a[p] = a[p-1];
			a[l] = t;
		} else {
			cin >> k;
			k = 1 + (n + k + ans - 1) % n;
			
			for(int i = 0; i < 8; i++) tmp[i] = 0;
			reg res = _mm256_loadu_si256((reg*) tmp);
			for(int i = 0; i < 8; i++) tmp[i] = k;
			reg msk = _mm256_loadu_si256((reg*) tmp);
			
			reg x;
			#pragma GCC ivdep
			for(; l + 7 <= r; l += 8) {
				x = _mm256_loadu_si256((reg*) &a[l]);
				x = _mm256_cmpeq_epi32(x, msk);
				res = _mm256_add_epi32(res, x);
			}
			ans = 0;
			for(; l <= r; l++) ans += a[l] == k;
			
			_mm256_storeu_si256((reg*) tmp, res);
			for(int i = 0; i < 8; i++) ans -= tmp[i];
			
			cout << ans << '\n';
		}
	}
}