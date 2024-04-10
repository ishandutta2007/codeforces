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
  ModularInt() { num = 0; }
  ModularInt(int num): num(num) {}

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

  void operator*=(const ModularInt& other) {
    num = (long long)num * other.num % MOD;
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

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, K;
    scanf("%d %d", &N, &K);

    vector<Int> fact(N + 1, 1);
    for (int i = 1; i <= N; ++i) {
      fact[i] = fact[i - 1] * i;
    }
    vector<Int> inv_fact(N + 1);
    inv_fact[N] = Int(1) / fact[N];
    for (int i = N - 1; i >= 0; --i) {
      inv_fact[i] = inv_fact[i + 1] * (i + 1);
    }

    vector<Int> total(K, 1);
    Int two_N = pow(Int(2), N);
    for (int i = 1; i < K; ++i) {
      total[i] = total[i - 1] * two_N;
    }

    Int sum_even = 0;
    for (int i = 0; i <= N; ++i) {
      if (i & 1) {}
      else {
        sum_even += fact[N] * inv_fact[i] * inv_fact[N - i];
      }
    }

    Int answer = 1;
    if (N & 1) {
      for (int i = 0; i < K; ++i) {
        answer *= (sum_even + 1);
      }
    } else {
      for (int i = 0; i < K; ++i) {
        answer *= (sum_even - 1);
      }
      Int multiplier = 1;
      for (int i = 0; i < K; ++i) {
        answer += multiplier * total[K - i - 1];
        multiplier *= (sum_even - 1);
      }
    }
    printf("%d\n", answer.num);
  }
}