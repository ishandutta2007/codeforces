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

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return llint(a)*b % mod;
}

int neg(int x) {
  return x == 0 ? 0 : mod - x;
}

int powmod(int a, int b) {
  int ans = 1;
  while (b > 0) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b /= 2;
  }
  return ans;
}


int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);

  vector<int> p(n+1, 0);
  p[0] = 1;
  int start_prod = 1;
  REP(i, n) {
    int a;
    scanf("%d", &a);

    vector<int> np(n+1, 0);
    for (int j = 0; j <= i+1; ++j) {
      np[j] = mul(a, p[j]);
      if (j > 0) {
        np[j] = sub(np[j], p[j - 1]);
      }
    }
    p = np;
    start_prod = mul(start_prod, a);
  }

  int inv_n = powmod(n, mod - 2);

  int end_prod = 0, coef = 1;
  for (int j = 0; j < (int)p.size(); ++j) {
    end_prod = add(end_prod, mul(coef, p[j]));
    coef = mul(coef, k - j);
    coef = mul(coef, inv_n);
  }
  int ans = sub(start_prod, end_prod);
  printf("%d\n", ans);
  return 0;
}