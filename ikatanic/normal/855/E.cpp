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

const int MAXD = 64;
const int MAXB = 11;

llint f[MAXB][MAXD][1<<MAXB];

llint count(int b, llint x) {
  if (x <= 0) return 0;

  x++;
  
  vector<int> digits;
  while (x > 0) {
    digits.push_back(x % b);
    x /= b;
  }

  reverse(digits.begin(), digits.end());

  llint ret = 0;
  int n = digits.size();
  int mask = 0;
  
  REP(p, n) { // prefix match
    REP(i, digits[p]) {
      if (p == 0 && i == 0) continue;
      ret += f[b][n-p-1][mask ^ (1<<i)];
    }
    mask ^= 1<<digits[p];
  }

  FOR(m, 1, n) FOR(i, 1, b) {
    ret += f[b][m-1][1<<i];
  }
  return ret;
}

int main(void) {
  for (int b = 2; b <= 10; ++b) {
    f[b][0][0] = 1;
    REP(n, MAXD-1) REP(s, 1<<b) REP(d, b) {
      f[b][n + 1][s ^ (1<<d)] += f[b][n][s];
    }
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    llint b, l, r;
    scanf("%lld %lld %lld", &b, &l, &r);
    printf("%lld\n", count(b, r) - count(b, l - 1));
  }
  return 0;
}