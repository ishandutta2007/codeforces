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

const int MAX = 1010;
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

int f[MAX][MAX];
int pw_a[MAX];
int s1_a, s2_a;

int count(int c_a, int c, int k, int p_a, int p_b, int p) {
  if (c_a < k-c) {
    p = mul(p, pw_a[k-c-c_a]);
    c_a = k - c;
  }
  p = mul(p, p_b);

  int ret = add(mul(s1_a, add(c, c_a)), s2_a);
  ret = mul(ret, p);

  return ret;
}

int main(void) {
  int k, pa, pb;
  scanf("%d %d %d", &k, &pa, &pb);

  int denom = powmod(pa + pb, mod - 2);
  int p_a = mul(pa, denom);
  int p_b = mul(pb, denom);

  pw_a[0] = 1;
  for (int i = 1; i <= k; ++i) {
    pw_a[i] = mul(pw_a[i-1], p_a);
  }
  s1_a = powmod(sub(1, p_a), mod - 2);
  s2_a = mul(p_a, mul(s1_a, s1_a));

  int ans = 0;

  ans = add(ans, count(1, 0, k, p_a, p_b, 1));

  f[1][0] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < k; ++j) {

      f[i + 1][j] = add(f[i + 1][j], mul(f[i][j], p_a));
      if (j + i < k) {
        f[i][j + i] = add(f[i][j + i], mul(f[i][j], p_b));
        ans = add(ans, count(i, j + i, k, p_a, p_b, mul(f[i][j], p_b)));
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}