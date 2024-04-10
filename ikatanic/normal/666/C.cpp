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

const int MAX = 100100;
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

char buff[MAX];
vector<pair<int, int>> q[MAX];

int f[MAX], invf[MAX];

int choose(int n, int k) {
  return mul(f[n], mul(invf[k], invf[n-k]));
}

int pw25[MAX];

int main(void) {
  f[0] = invf[0] = 1;
  FOR(i, 1, MAX) {
    f[i] = mul(f[i-1], i);
    invf[i] = powmod(f[i], mod-2);
  }

  pw25[0] = 1;
  FOR(i, 1, MAX) pw25[i] = mul(pw25[i-1], 25);

  int m;
  scanf("%d", &m);

  vector<string> v;
  scanf("%s", buff);
  int len = strlen(buff);

  int cnt = 0;
  REP(i, m) {
    int tip;
    scanf("%d", &tip);
    if (tip == 1) {
      scanf("%s", buff);
      len = strlen(buff);
    }
    if (tip == 2) {
      int n;
      scanf("%d", &n);
      q[len].push_back({n, cnt++});
    }
  }

  vector<int> ans(cnt);
  REP(m, MAX)
    if (q[m].size()) {
      static int g[MAX];
      int N = max_element(q[m].begin(), q[m].end())->first;
      REP(n, m) g[n] = 0;
      FOR(n, m, N + 1) {
        g[n] = add(mul(26, g[n-1]), mul(choose(n-1, m-1), pw25[n-m]));
      }

      for (auto& p: q[m])
        ans[p.second] = g[p.first];
    }

  for (int x: ans) printf("%d\n", x);
  return 0;
}