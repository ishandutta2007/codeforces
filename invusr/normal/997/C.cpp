#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const int M = 998244353;

int add(int a, const int &b) {
  a += b;
  return a >= M ? a - M : a;
}
int sub(int a, const int &b) {
  a -= b;
  return a < 0 ? a + M : a;
}
int mul(const int &a, const int &b) {
  return (s64)a * b % M;
}

int main() {
  int n;
  cin >> n;

  vector<int> fac(n + 1), ifac(n + 1);
  fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = mul(M - M / i, ifac[M % i]);
  }
  for (int i = 2; i <= n; ++i) {
    ifac[i] = mul(ifac[i], ifac[i - 1]);
  }

  vector<int> pow(n + 1), exp(n + 1);
  pow[0] = exp[0] = exp[1] = 1;
  for (int i = 1; i <= n; ++i) {
    pow[i] = mul(pow[i - 1], 3);
    exp[1] = mul(exp[1], 3);
  }
  for (int i = 2; i <= n; ++i) {
    exp[i] = mul(exp[i - 1], exp[1]);
  }

  auto power = [&](int a, int n) {
    int answer = 1;
    for (int i = n; i; i >>= 1) {
      if (i & 1) {
        answer = mul(answer, a);
      }
      a = mul(a, a);
    }
    return answer;
  };
  auto binom = [&](int n, int m) {
    return mul(fac[n], mul(ifac[m], ifac[n - m]));
  };

  int answer = 0, coef = 2;
  for (int i = 1; i <= n; ++i) {
    int ways = mul(pow[i], exp[n - i]);
    ways = mul(ways, binom(n, i));
    answer = add(answer, mul(ways, coef));
    coef = sub(M, coef);
  }
  coef = M - 1;
  for (int i = 0; i < n; ++i) {
    int ways = sub(power(1 + M - pow[i], n), power(M - pow[i], n));
    ways = mul(ways, coef);
    ways = mul(ways, binom(n, i));
    answer = add(answer, mul(ways, 3));
    coef = sub(M, coef);
  }
  cout << answer << endl;

  return 0;
}