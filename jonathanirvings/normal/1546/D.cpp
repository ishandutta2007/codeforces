#include <bits/stdc++.h>
using namespace std;

constexpr int kMod = 998244353;

template <typename T>
T pow(T a, long long b) {
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
    int N;
    scanf("%d", &N);
    vector<Int> fact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
      fact[i] = fact[i - 1] * i;
    }
    char S[N + 1];
    scanf("%s", S);
    int pairs = 0, zeroes = 0;
    for (int i = 0; i < N; ++i) {
      if (S[i] == '0') {
        ++zeroes;
      } else {
        if (i + 1 < N && S[i + 1] == '1') {
          ++pairs;
          ++i;
        }
      }
    }
    printf("%d\n", fact[pairs + zeroes] / fact[pairs] / fact[zeroes]);
  }
}