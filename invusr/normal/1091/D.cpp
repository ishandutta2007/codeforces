#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

template <class T>
bool relax(T &a, T b) {
  return b > a ? a = b, true : false;
}
template <class T>
bool tense(T &a, T b) {
  return b < a ? a = b, true : false;
}

const int N = 1111111;
const int M = 998244353;

void add(int &a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
}
void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += M;
  }
}
int mul(int a, int b) {
  return (s64)a * b % M;
}

int n;
int fac[N], ifac[N];

int power(int a, int n) {
  int result = 1;
  for (int i = n; i; i >>= 1) {
    if (i & 1) {
      result = mul(result, a);
    }
    a = mul(a, a);
  }
  return result;
}

int binom(int n, int m) {
  return mul(fac[n], mul(ifac[m], ifac[n - m]));
}

int main() {
  cin >> n;

  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = mul(fac[i - 1], i);
  }
  ifac[n] = power(fac[n], M - 2);
  for (int i = n; i; --i) {
    ifac[i - 1] = mul(ifac[i], i);
  }

  int result = fac[n];
  for (int i = 1; i < n; ++i) {
    add(result, mul(mul(binom(n, i), fac[n - i]), (fac[i] + M - 1) % M));
  }
  cout << result << endl;

  return 0;
}