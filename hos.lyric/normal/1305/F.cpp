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
#include <functional>
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
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }

constexpr int LIM = 1000010;

bool isnp[LIM];
int primesLen;
Int primes[LIM];

int N;
Int A[200010];
int ans;

Int sieve[400010];

void check(Int p) {
// cerr<<"check "<<p<<endl;
  Int cost = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] <= p) {
      cost += (p - A[i]);
    } else {
      const Int r = A[i] % p;
      cost += min(r, p - r);
    }
    if (ans <= cost) {
      return;
    }
  }
// cerr<<"check "<<p<<": "<<cost<<endl;
  ans = cost;
}

int main() {
  for (Int p = 2; p < LIM; ++p) {
    if (!isnp[p]) {
      primes[primesLen++] = p;
      for (Int n = p * p; n < LIM; n += p) {
        isnp[n] = true;
      }
    }
  }
// cerr<<"primesLen = "<<primesLen<<endl;
  
  for (; ~scanf("%d", &N); ) {
    for (int i = 0; i < N; ++i) {
      scanf("%lld", &A[i]);
    }
    sort(A, A + N);
    
    Int g = 0;
    for (int i = 0; i < N; ++i) {
      g = __gcd(g, A[i]);
    }
    if (g != 1) {
      ans = 0;
    } else {
      ans = N;
      for (int j = 0; j < primesLen; ++j) {
        check(primes[j]);
      }
      const Int lb = max<Int>(A[0] - ans, LIM);
      const Int ub = A[0] + ans + 1;
      if (lb < ub) {
        for (Int x = lb; x < ub; ++x) {
          const int pos = x - lb;
          sieve[pos] = x;
        }
        for (int j = 0; j < primesLen; ++j) {
          const Int p = primes[j];
          for (Int x = max((lb + p - 1) / p, 2LL) * p; x < ub; x += p) {
            const int pos = x - lb;
            do {
              sieve[pos] /= p;
            } while (sieve[pos] % p == 0);
          }
        }
// cerr<<"lb = "<<lb<<", ub = "<<ub<<endl;
// cerr<<"sieve = ";pv(sieve,sieve+(ub-lb));
        for (Int x = lb; x <= A[0] + ans; ++x) {
          const int pos = x - lb;
          if (sieve[pos] > 1) {
            check(sieve[pos]);
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}