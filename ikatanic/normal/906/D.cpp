#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int LO = 50;

llint mod(llint x, llint lo, llint m) {
  if (x >= lo) {
    x -= ((x - lo) / m) * m;
  }
  return x;
}

llint power(llint a, llint b, llint lo, llint m) {
  llint ret = 1;
  while (b > 0) {
    if (b % 2) {
      ret = mod(ret * a, lo, m);
    }
    a = mod(a * a, lo, m);
    b /= 2;
  }
  return ret;
}

#include <map>
map<int, int> memo;

int phi(int m) {
  if (memo.count(m)) {
    return memo[m];
  }

  int ret = m;
  int org = m;
  for (int x = 2; x * x <= m; ++x) {
    if (m % x == 0) {
      ret /= x;
      ret *= x - 1;
      while (m % x == 0) m /= x;
    }
  }
  if (m > 1) {
    ret /= m;
    ret *= m - 1;
  }
  memo[org] = ret;
  return ret;
}

int solve(vector<int>& x, int l, int r, int m) {
  if (l == r) return 1;

  int a = mod(x[l], max(LO, m), m);
  int b = solve(x, l + 1, r, phi(m));

  return power(a, b, max(LO, m), m);
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  vector<int> x(n);
  REP(i, n) scanf("%d", &x[i]);

  int q;
  scanf("%d", &q);

  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    int ret = solve(x, l, min(r, l + 100), m) % m;
    printf("%d\n", ret);
  }
  return 0;
}