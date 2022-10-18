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

const int MAX = 1<<16;
const int MAXW = 1001;
const int inf = 2e9;
const int P = 1e7 + 19;
const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

vector<int> T[2*MAX];

int f[MAXW];
int tmp[20][MAXW];
int tip[MAX], ans[MAX];
int st[MAX], en[MAX];
int v[MAX], w[MAX];
int off, n, k;

void insert(int i, int lo, int hi, int a, int b, int k) {
  if (lo >= b || hi <= a) return;
  if (lo >= a && hi <= b) {
    T[i].push_back(k);
    return;
  }
  insert(i*2, lo, (lo+hi)/2, a, b, k);
  insert(i*2+1, (lo+hi)/2, hi, a, b, k);
}

void solve(int i, int d) {
  if (T[i].size()) {
    REP(j, k+1) tmp[d][j] = f[j];
  }

  for (int x: T[i]) {
    for (int j = k - w[x]; j >= 0; --j)
      f[j + w[x]] = max(f[j + w[x]], f[j] + v[x]);
  }

  if (i < off) {
    solve(i*2, d+1);
    solve(i*2+1, d+1);
  } else {
    int *r = &ans[i-off];
    int pot = 1, best = f[0];
    for (int j = 1; j <= k; ++j) {
      best = max(best, f[j]);
      *r = add(*r, mul(pot, best));
      pot = mul(pot, P);
    }
  }

  if (T[i].size()) {
    REP(j, k+1) f[j] = tmp[d][j];
  }
}

int main(void) {
  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%d %d", &v[i], &w[i]);
  REP(i, n) en[i] = -1;

  int m;
  scanf("%d", &m);

  int cur = 0;
  REP(i, m) {
    scanf("%d", &tip[i]);
    if (tip[i] == 1) {
      scanf("%d %d", &v[n], &w[n]);
      en[n] = -1;
      st[n++] = cur;
    }
    if (tip[i] == 2) {
      int x;
      scanf("%d", &x); --x;
      en[x] = cur;
    }
    if (tip[i] == 3) cur++;
  }

  for (off = 1; off < cur; off *= 2);
  
  REP(i, n) {
    if (en[i] == -1) en[i] = cur;
    insert(1, 0, off, st[i], en[i], i);
  }

  REP(i, k+1) f[i] = -inf;
  f[0] = 0;
  solve(1, 0);

  REP(i, cur) printf("%d\n", ans[i]);
  return 0;
}