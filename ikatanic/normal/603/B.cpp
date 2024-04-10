#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1000100;
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
  int p, k;
  scanf("%d %d", &p, &k);

  if (k == 0) {
    int ans = 1;
    REP(i, p-1) ans = mul(ans, p);
    printf("%d\n", ans);
    return 0;
  }


  if (k == 1) {
    int ans = 1;
    REP(i, p) ans = mul(ans, p);
    printf("%d\n", ans);
    return 0;
  }

  static bool bio[MAX];
  REP(i, p) bio[i] = false;

  int ans = 1;
  FOR(i, 1, p) {
    if (bio[i]) continue;

    int x = i, cnt = 0;
    while (!bio[x]) {
      bio[x] = true;
      cnt++;
      x = (llint(x) * k) % p;
    }

    assert(x == i);
    ans = mul(ans, p);
  }

  printf("%d\n", ans);
  return 0;
}