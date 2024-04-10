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

int main(void) {
  int n;
  scanf("%d", &n);
  vector<int> pw(n+1, 0);
  pw[0] = 1;
  REP(i, n-1) pw[i+1] = mul(pw[i], 2);

  int ans = 0;
  vector<int> v(n);
  REP(i, n) scanf("%d", &v[i]);
  sort(v.begin(), v.end());

  REP(i, n) {
    int k = sub(pw[i], pw[n-i-1]);
    ans = add(ans, mul(k, v[i]));
  }

  printf("%d\n", ans);
    
  return 0;
}