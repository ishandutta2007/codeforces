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

const int MAX = 1e7 + 1;
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

int c[MAX];

void factor(int x, vector<int>& v) {
  v.clear();
  while (x > 1) {
    int p = c[x] ? c[x] : x;
    while (x%p == 0) x /= p;
    v.push_back(p);
  }
}

int f[MAX], g[MAX];
int cnt[MAX];

int main(void) {
  c[1] = 1;
  for (int i = 2; i*i < MAX; ++i)
    if (!c[i])
      for (int j = i*i; j < MAX; j += i)
        c[j] = i;

  int n;
  scanf("%d", &n);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    static vector<int> v;
    factor(x, v);
    int y = 1;
    for (int x: v) y *= x;
    cnt[y]++;
  }

  for (int i = 2; i < MAX; ++i)
    for (int j = i; j < MAX; j += i)
      f[i] += cnt[j];

  int all = 0;
  for (int i = MAX-1; i >= 2; --i) 
    if (f[i]) {
      static vector<int> v;
      factor(i, v);
      
      g[i] = 1;
      REP(j, f[i]) g[i] = add(g[i], g[i]);
      g[i] = sub(g[i], 1);
      
      if (v.size()%2) all = add(all, g[i]); else
        all = sub(all, g[i]);
    }

  int ans = 0;
  for (int i = 2; i < MAX; ++i)
    if (cnt[i]) {
      static vector<int> v;
      factor(i, v);
      int m = v.size();
      int ways = 0;
      REP(s, 1<<m) {
        int y = 1, c = 0;
        REP(i, m)
          if (s & (1<<i)) y *= v[i], c++;
        if (c%2) ways = add(ways, g[y]); else
          ways = sub(ways, g[y]);
      }

      ways = sub(all, ways);
      ans = add(ans, mul(cnt[i], ways));
    }

  printf("%d\n", ans);
  return 0;
}