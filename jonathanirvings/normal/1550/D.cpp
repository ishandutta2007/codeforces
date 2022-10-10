#include <bits/stdc++.h>
using namespace std;

constexpr int kMod = 1000000007;

template <typename T>
T pow(T a, int b) {
  if (b == 1) {
    return a;
  }
  T res = pow(a, b >> 1);
  res = res * res;
  if (b & 1) {
    res = res * a;
  }
  return res;
}

template <int MOD>
struct ModularInt {
  ModularInt() {}
  ModularInt(int num): num(num % MOD) {}

  void operator+=(const ModularInt& other) {
    num += other.num;
    if (num >= MOD) {
      num -= MOD;
    }
  }

  ModularInt operator+(const ModularInt& other) const {
    int res = num + other.num;
    if (res >= MOD) {
      res -= MOD;
    }
    return res;
  }

  ModularInt operator-(const ModularInt& other) const {
    int res = num - other.num + MOD;
    if (res >= MOD) {
      res -= MOD;
    }
    return res;
  }

  ModularInt operator*(const ModularInt& other) const {
    return (long long)num * other.num % MOD;
  }

  ModularInt operator/(const ModularInt& other) const {
    return (*this) * pow(other, MOD - 2);
  }

  int num;
};

typedef ModularInt<kMod> Int;

constexpr int kMaxN = 200000;
Int fact[kMaxN + 1];
Int inv_fact[kMaxN + 1];

Int choose(int N, int K) {
  if (K > N) {
    return 0;
  }
  return fact[N] * inv_fact[K] * inv_fact[N - K];
}

int main() {
  fact[0] = 1;
  for (int i = 1; i <= kMaxN; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  inv_fact[kMaxN] = Int(1) / fact[kMaxN];
  for (int i = kMaxN - 1; i >= 0; --i) {
    inv_fact[i] = inv_fact[i + 1] * (i + 1);
  }

  int T;
  scanf("%d", &T);
  while (T--) {
    int N, L, R;
    scanf("%d %d %d", &N, &L, &R);
    int half = N >> 1;
    L = 1 - L;
    R = R - N;
    Int answer = 0;
    if (min(L, R) > 0) {
      answer = choose(N, half) * min(L, R);
      if (N & 1) {
        answer = answer * 2;
      }
    }
    for (int i = min(L, R) + 1; i <= min(L, R) + N; ++i) {
      int can_sub = min(N, L - i + N);
      int can_add = min(N, R - i + N);

      int must_add = N - can_sub;
      int must_sub = N - can_add;
      int free = N - must_add - must_sub;

      if (N & 1) {
        if (must_add <= half) {
          answer += choose(free, half - must_add);
        }
        if (must_sub <= half) {
          answer += choose(free, half - must_sub);
        }
      } else {
        if (must_add <= half) {
          answer += choose(free, half - must_add);
        }
      }
    }
    printf("%d\n", answer.num);
  }
}