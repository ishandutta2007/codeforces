// I mean why not lol
#pragma GCC target ("avx2,avx,sse,sse2,ssse3")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <immintrin.h>
#define INLINE __attribute(( always_inline )) inline
using namespace std;
const int maxn = 1<<17;
int n, q, a[maxn];
alignas(32) int b[maxn], tmp[8];
set<int> f[maxn];
INLINE void ins(int x, int p) {
	auto it = f[x].insert(p).first;
	auto prev = it;
	if(prev-- != f[x].begin()) b[p] = *prev;
	else b[p] = -1;
	if(++it != f[x].end()) b[*it] = p;
}
INLINE void ers(int x, int p) {
	auto it = f[x].lower_bound(p);
	auto prev = it;
	if(++it != f[x].end()) {
		if(prev-- == f[x].begin()) b[*it] = -1;
		else b[*it] = *prev;
	}
	f[x].erase(p);
}
typedef __m256i reg;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	memset(b, -1, sizeof b);
	for(int i = 0; i < n; i++) cin >> a[i], ins(a[i], i);
	for(int t, l, r; q--;) {
		cin >> t >> l >> r;l--;
		if(t == 1) ers(a[l], l), ins(a[l]=r, l);
		else {
			int64_t ans = 0;
			reg rr = _mm256_set1_epi32( 0);
			int _val = l-1;
			reg L = _mm256_set1_epi32( _val);
			
			reg x;
			#pragma GCC ivdep
			for(; (l&7) && l < r;  l++) {
				ans += (b[l]>_val)*(l-b[l]);
			}
			for(int i = 0; i < 8; i++) tmp[i] = l+i;
			reg cur = _mm256_load_si256((reg*) tmp);
			reg shft = _mm256_set1_epi32(8);
			for(; l+7 < r; l+=8, cur = _mm256_add_epi32(cur, shft)) {
				x = _mm256_load_si256( (reg*) &(b[l]) );
				rr = _mm256_add_epi32(rr, _mm256_and_si256(_mm256_cmpgt_epi32(x, L), _mm256_sub_epi32(cur, x))); 
			}
			_mm256_store_si256((reg*)tmp, rr);
			for(int i = 0; i < 8; i++) ans += tmp[i];
			#pragma GCC ivdep
			for(; l < r;  l++) {
				ans += (b[l]>_val)*(l-b[l]);
			}
			cout << ans << '\n';
		}
	}
}