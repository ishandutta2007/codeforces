#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
#include<bits/stdc++.h>
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
namespace AVX2_harley_seal {
	
__m256i popcount(const __m256i v)
{
  const __m256i m1 = _mm256_set1_epi8(0x55);
  const __m256i m2 = _mm256_set1_epi8(0x33);
  const __m256i m4 = _mm256_set1_epi8(0x0F);

  const __m256i t1 = _mm256_sub_epi8(v,       (_mm256_srli_epi16(v,  1) & m1));
  const __m256i t2 = _mm256_add_epi8(t1 & m2, (_mm256_srli_epi16(t1, 2) & m2));
  const __m256i t3 = _mm256_add_epi8(t2, _mm256_srli_epi16(t2, 4)) & m4;
  return _mm256_sad_epu8(t3, _mm256_setzero_si256());
}

void CSA(__m256i& h, __m256i& l, __m256i a, __m256i b, __m256i c)
{
  const __m256i u = a ^ b;
  h = (a & b) | (u & c);
  l = u ^ c;

}

uint64_t popcnt(const __m256i* data, const uint64_t size)
{
  __m256i total     = _mm256_setzero_si256();
  __m256i ones      = _mm256_setzero_si256();
  __m256i twos      = _mm256_setzero_si256();
  __m256i fours     = _mm256_setzero_si256();
  __m256i eights    = _mm256_setzero_si256();
  __m256i sixteens  = _mm256_setzero_si256();
  __m256i twosA, twosB, foursA, foursB, eightsA, eightsB;

  const uint64_t limit = size - size % 16;
  uint64_t i = 0;

  for(; i < limit; i += 16)
  {
    CSA(twosA, ones, ones, data[i+0], data[i+1]);
    CSA(twosB, ones, ones, data[i+2], data[i+3]);
    CSA(foursA, twos, twos, twosA, twosB);
    CSA(twosA, ones, ones, data[i+4], data[i+5]);
    CSA(twosB, ones, ones, data[i+6], data[i+7]);
    CSA(foursB, twos, twos, twosA, twosB);
    CSA(eightsA,fours, fours, foursA, foursB);
    CSA(twosA, ones, ones, data[i+8], data[i+9]);
    CSA(twosB, ones, ones, data[i+10], data[i+11]);
    CSA(foursA, twos, twos, twosA, twosB);
    CSA(twosA, ones, ones, data[i+12], data[i+13]);
    CSA(twosB, ones, ones, data[i+14], data[i+15]);
    CSA(foursB, twos, twos, twosA, twosB);
    CSA(eightsB, fours, fours, foursA, foursB);
    CSA(sixteens, eights, eights, eightsA, eightsB);

    total = _mm256_add_epi64(total, popcount(sixteens));
  }

  total = _mm256_slli_epi64(total, 4);     // * 16
  total = _mm256_add_epi64(total, _mm256_slli_epi64(popcount(eights), 3)); // += 8 * ...
  total = _mm256_add_epi64(total, _mm256_slli_epi64(popcount(fours),  2)); // += 4 * ...
  total = _mm256_add_epi64(total, _mm256_slli_epi64(popcount(twos),   1)); // += 2 * ...
  total = _mm256_add_epi64(total, popcount(ones));

  for(; i < size; i++)
    total = _mm256_add_epi64(total, popcount(data[i]));


  return static_cast<uint64_t>(_mm256_extract_epi64(total, 0))
       + static_cast<uint64_t>(_mm256_extract_epi64(total, 1))
       + static_cast<uint64_t>(_mm256_extract_epi64(total, 2))
       + static_cast<uint64_t>(_mm256_extract_epi64(total, 3));
}

} // AVX2_harley_seal

uint64_t popcnt_AVX2_harley_seal(const uint8_t* data, const size_t size)
{
	uint64_t total = AVX2_harley_seal::popcnt((const __m256i*) data, size / 32);
	return total;
}
alignas(32) ll t[1000];
struct o {
	int cut, s, e;
	bool isect(o b) {
		return cut >= b.s && cut <= b.e && b.cut >= s && b.cut <= e;
	}
};
int n, xx, yy, xx1, yy1;
vector<o> x, y;
alignas(256) uint8_t xb[5001][642], tmp[642];
__attribute__((always_inline)) void xset(int p, int i) {
	xb[p][i>>3] |= 1<<(i&7);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	#pragma GCC ivdep
	while (n--) {
		cin >> xx >> yy >> xx1 >> yy1;
		if (xx > xx1)
			swap(xx, xx1);
		if (yy > yy1)
			swap(yy, yy1);
		if (xx == xx1) {
			x.pb( { xx, yy, yy1 });
		} else {
			y.pb( { yy, xx, xx1 });
		}
	}
	if (x.size() > y.size()) {
		swap(x, y);
	}
	#pragma GCC ivdep
	for (int i = 0; i < x.size(); i++)
		for (int j = 0; j < y.size(); j++) {
			if (x[i].isect(y[j]))
				xset(i, j);
		}
	ll ans = 0;
	#pragma GCC ivdep
	for (int i = 0; i < x.size(); i++)
		for (int j = i + 1; j < x.size(); j++) {
			__m256i r = _mm256_setzero_si256();
			for(int k = 0; k < 625; k+=32) {
				__m256i x = _mm256_load_si256((__m256i*) &xb[j][k]);
				__m256i y = _mm256_loadu_si256((__m256i*) &xb[i][k]);
				_mm256_store_si256((__m256i*)&tmp[k], _mm256_and_si256(x, y));
			}
			ll res = popcnt_AVX2_harley_seal(tmp, 642);
			ans += res * (res - 1) / 2;
		}
	cout << ans;
}