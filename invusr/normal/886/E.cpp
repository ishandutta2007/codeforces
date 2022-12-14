#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const int M = 1000000007;

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
  int n, k;
  cin >> n >> k;

  vector<int> fac(n), ifac(n);
  fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
  for (int i = 2; i < n; ++i) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = mul(M - M / i, ifac[M % i]);
  }
  for (int i = 2; i < n; ++i) {
    ifac[i] = mul(ifac[i], ifac[i - 1]);
  }

  vector<int> f(n + 1), sum(n + 1);
  for (int i = k + 1; i <= n; ++i) {
    f[i] = mul(add(i - k - 1, sub(sum[i - 1], sum[i - k - 1])), fac[i - 2]);
    sum[i] = mul(f[i], ifac[i - 1]);
    sum[i] = add(sum[i], sum[i - 1]);
  }

  int answer = 0;
  for (int i = 1; i <= n; ++i) {
    answer = add(answer, mul(f[i], mul(fac[n - 1], ifac[i - 1])));
  }
  cout << answer << endl;

  return 0;
}