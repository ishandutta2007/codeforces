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
const int inv2 = (mod + 1)/2;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);
  int ans = 0;
  int sum = mul(mul(b, b - 1), inv2);
  FOR(k, 1, a+1) {
    ans = add(ans, sum);
    ans = add(ans, mul(mul(sum, k), b));
  }
  printf("%d\n", ans);
  return 0;
}