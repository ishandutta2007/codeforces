#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4")//tells to assume the processor supports various instruction sets
//which compiler can utilize to make your code way faster
#include<bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
const uint mod = 1e9+7;
namespace matmul {
const int maxM = 100;
//alignas(64) 
uint r[maxM][maxM], res[maxM][maxM];
#include<immintrin.h>
__attribute__((target("avx2"), optimize("O3", "unroll-loops")))
__attribute__((always_inline)) __m256i
my256_mullo_epu32(const __m256i &a, const __m256i &b) {
  return _mm256_mullo_epi32(a, b);
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops")))
__attribute__((always_inline)) __m256i
my256_mulhi_epu32(const __m256i &a, const __m256i &b) {
  __m256i a13 = _mm256_shuffle_epi32(a, 0xF5);
  __m256i b13 = _mm256_shuffle_epi32(b, 0xF5);
  __m256i prod02 = _mm256_mul_epu32(a, b);
  __m256i prod13 = _mm256_mul_epu32(a13, b13);
  __m256i prod = _mm256_unpackhi_epi64(_mm256_unpacklo_epi32(prod02, prod13),
                                       _mm256_unpackhi_epi32(prod02, prod13));
  return prod;
}

typedef uint v8si __attribute__(( vector_size(8*sizeof(int)) ));
using reg = __m256i;
union orz {
	v8si v;
	reg r;
};
#define load(x) _mm256_loadu_si256((reg*)&(x))
#define store(dst, src) _mm256_storeu_si256((reg*)&(dst), (src)) 
struct matrix : vector<vector<uint>> {
	int N;
	matrix(int n = 0) : N(n) {
		resize(N);
		for(auto &i : (*this))
			i.resize(n);
	}
	matrix &operator*=(const matrix &rhs) {
		for(int i = 0; i < N; i++)
		    for(int j = 0; j < N; j++) {
		        r[i][j] = (uint64_t((*this)[i][j]) << 32) / mod;//replace multiplication with cast
		        res[i][j] = 0;
		    }
		for(int i = 0; i < N; i++) {
			for(int k = 0; k < N; k++) {
		        int j = 0;
		        orz A, MOD, R, MOD1, MOD2;
		        A.r = _mm256_set1_epi32((*this)[i][k]);
		        MOD.r = _mm256_set1_epi32(mod);
		        MOD1.r = _mm256_set1_epi32(2*mod);
		        MOD2.r = _mm256_set1_epi32(2*mod-1);
		        R.r = _mm256_set1_epi32(r[i][k]);
		        orz B, RES, Q;
		        
		        for(; j+7 < N; j+=8) {
		        	B.r = load(rhs[k][j]);
		        	RES.r = load(res[i][j]);
		        	Q.r = my256_mulhi_epu32(R.r, B.r);
		        	Q.r = my256_mullo_epu32(MOD.r, Q.r);
		        	B.r = my256_mullo_epu32(A.r, B.r);
		        	B.r = _mm256_sub_epi32(B.r, Q.r);
					RES.r = _mm256_add_epi32(RES.r, B.r);
		        	//RES.v -= MOD1.v&(RES.v>MOD2.v);
		        	B.v = RES.v > MOD2.v;
		        	RES.r = _mm256_sub_epi32(RES.r,
		        	 _mm256_and_si256(MOD1.r, B.r));
					store(res[i][j], RES.r);
		        }
		        for(; j < N; j++) {
		        	uint q = (1LL * r[i][k] * rhs[k][j]) >> 32;
		            q = (*this)[i][k] * rhs[k][j] - mod * q;
		            res[i][j] += q;
		            if(res[i][j] >= 2*mod){
		                res[i][j] -= 2*mod;
		            }
		        }
		    }
		}
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++) {
		        (*this)[i][j] = res[i][j];
		        if((*this)[i][j] >= mod) (*this)[i][j] -= mod;
		    }
		return *this;
	}
	friend matrix operator*(const matrix &a, const matrix &b) {
		return matrix(a)*=b;
	}
};
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
	int m;
	cin >> n >> m;
	if(m > n) return cout << 1, 0;
	matmul::matrix a(m), res(m);
	for(int i = 0; i < m; i++) res[i][i] = 1;
	for(int i = 1; i < m; i++)
		a[i][i-1] = 1;
	n -= m-1;
	a[0][0] = a[0][m-1] = 1;
	for(;n; n/=2,a*=a) {
		if(n&1) res *= a;
	}
	uint f = 0;
	for(int i = 0; i < m; i++) {
		f += res[0][i];
		if(f >= mod) f -= mod;
	}
	cout << f << '\n';
}