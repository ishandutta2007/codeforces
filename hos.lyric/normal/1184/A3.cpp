#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")

#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template <class T> void chmax(T &t, const T &f) { if (t < f) t = f; }

unsigned xrand() {
	static unsigned x = 314159265, y = 358979323, z = 846264338, w = 327950288;
	unsigned t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
}

Int power(Int a, Int e, Int m) {
  Int x = a % m, y = 1 % m;
  for (; e; e >>= 1) {
    if (e & 1) {
      y = (y * x) % m;
    }
    x = (x * x) % m;
  }
  return y;
}


constexpr int LIM = 1000000;
constexpr int MM = 100000;

bool isnp[LIM];
int primesLen;
Int primes[LIM];

int N, M;
char A[100010], B[100010];

Int c[100010];

int main() {
  for (int p = 2; p < LIM; ++p) {
    if (!isnp[p]) {
      for (int n = 2 * p; n < LIM; n += p) {
        isnp[n] = true;
      }
    }
  }
  for (int p = MM; p < LIM; ++p) {
    if (!isnp[p]) {
      primes[primesLen++] = p;
    }
  }
cerr<<"|primes| = "<<primesLen<<endl;
  
  
  
  for (; ~scanf("%d%d", &N, &M); ) {
    scanf("%s%s", A, B);
    for (; ; ) {
      for (int k = 3; k < 100; ++k) {
// cerr<<"k = "<<k<<endl;
        fill(c, c + k, 0);
        for (int pos = 0; pos < N; ++pos) {
          c[pos % k] += (B[pos] - A[pos]);
        }
        for (int i = 0; i < primesLen; ++i) {
          const Int p = primes[i];
          if ((p - 1) % k == 0) {
// cerr<<"  p = "<<p<<endl;
            for (int iter = 0; iter < 3; ++iter) {
              const Int b = 2 + xrand() % (p - 3);
              const Int r = power(b, (p - 1) / k, p);
              if (2 <= r && r <= p - 2) {
                Int s = 0;
                for (int j = k; j--; ) {
                  s = (s * r + c[j]) % p;
                }
                if (s == 0) {
cerr<<"found k = "<<k<<endl;
                  printf("%lld %lld\n", p, r);
                  goto found;
                }
              }
            }
          }
        }
      }
    }
   found:{}
  }
  return 0;
}