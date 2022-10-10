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

vector<Int> fact, inv_fact;
const Int ONE_OVER_THREE = Int(1) / 3;

Int binomial(int n, int k) {
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);

  fact.resize(3 * N + 2);
  fact[0] = 1;
  for (int i = 1; i <= 3 * N + 1; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  inv_fact.resize(3 * N + 2);
  inv_fact[3 * N + 1] = Int(1) / fact[3 * N + 1];
  for (int i = 3 * N; i >= 0; --i) {
    inv_fact[i] = inv_fact[i + 1] * (i + 1);
  }

  vector<vector<Int>> dp(3 * N + 1, vector<Int>(3));
  dp[0][0] = dp[0][1] = dp[0][2] = N;
  for (int i = 1; i <= 3 * N; ++i) {
    dp[i][2] = ONE_OVER_THREE * (
        binomial(3 * N + 1, i + 1) - Int(2) * dp[i - 1][2] - dp[i - 1][1]);
    dp[i][1] = dp[i - 1][2] + dp[i][2];
    dp[i][0] = dp[i - 1][1] + dp[i][1];
  }

  while(Q--) {
    int X;
    scanf("%d", &X);
    printf("%d\n", dp[X][0].num);
  }
}