#include <bits/stdc++.h>
using namespace std;

constexpr int kMod = 998244353;

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

int main() {
  int N;
  scanf("%d", &N);

  vector<int> X(N), Y(N), S(N);
  vector<Int> dp(N);
  Int answer = 0;
  vector<Int> prefix_sum(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d %d %d", &X[i], &Y[i], &S[i]);
    dp[i] = X[i] - Y[i];
    if (i > 0) {
      int start_from = lower_bound(X.begin(), X.begin() + i, Y[i]) - X.begin();
      dp[i] += prefix_sum[i - 1] -
               (start_from == 0 ? 0 : prefix_sum[start_from - 1]);
      prefix_sum[i] = dp[i] + prefix_sum[i - 1];
    } else {
      prefix_sum[i] = dp[i];
    }
    if (S[i] == 1) {
      answer += dp[i];
    }
  }
  answer += X[N - 1] + 1;
  printf("%d\n", answer.num);
}