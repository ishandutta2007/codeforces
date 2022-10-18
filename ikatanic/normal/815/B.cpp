#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

vector<int> transform(vector<int> v) {
  vector<int> nv;
  REP(i, (int)v.size() - 1) {
    int x = v[i];
    if (i % 2) {
      x = sub(x, v[i + 1]);
    } else {
      x = add(x, v[i + 1]);
    }
    nv.push_back(x);
  }
  return nv;
}

int main(void) {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  REP(i, n) scanf("%d", &a[i]);

  if (n == 1) {
    printf("%d\n", a[0]);
    return 0;
  }

  if (n % 2) {
    a = transform(a);
    --n;
  }

  vector<int> binoms(n/2 + 1);
  binoms[0] = 1;
  int k = n / 2 - 1;
  for (int i = 1; i <= k; ++i) {
    binoms[i] = binoms[i - 1];
    binoms[i] = mul(binoms[i], k - i + 1);
    binoms[i] = mul(binoms[i], powmod(i, mod - 2));
  }

  int ans = 0;
  REP(i, n) {
    int coef = binoms[i / 2];
    if (n % 4 == 0 && i % 2) coef = mul(coef, mod - 1);
    ans = add(ans, mul(a[i], coef));
  }
  printf("%d\n", ans);
  return 0;
}