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

int mod;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

const int MAX = 220;

char a[MAX][MAX];
int id[MAX][MAX];
vector<int> E[MAX*MAX]; // existing edges
vector<int> F[MAX*MAX]; // possible edges

bool bio[MAX*MAX];
int comp[MAX*MAX];

int e[MAX][MAX];

void dfs(int x, int c) {
  bio[x] = true;
  comp[x] = c;
  for (int y: E[x])
    if (!bio[y]) dfs(y, c);
}

int calcDet(int e[MAX][MAX], int n) {
  REP(i, n) REP(j, n) {
    e[i][j] %= mod;
    if (e[i][j] < 0) e[i][j] += mod;
  }

  int ans = 1;
  REP(i, n) {
    int k = -1;
    FOR(j, i, n)
      if (e[j][i]) { k = j; break; }
    if (k == -1) return 0;
    
    if (i != k) {
      REP(j, n) swap(e[i][j], e[k][j]);
      ans = mul(ans, sub(0, 1));
    }

    ans = mul(ans, e[i][i]);
    int inv = powmod(e[i][i], mod-2);
    REP(j, n) e[i][j] = mul(e[i][j], inv);

    FOR(j, i+1, n)
      if (e[j][i]) {
        int c = e[j][i];
        REP(k, n)
          e[j][k] = sub(e[j][k], mul(c, e[i][k]));
      }
  }

  return ans;
}

int main(void) {
  int n, m;
  scanf("%d %d %d", &n, &m, &mod);
  REP(i, n) scanf("%s", a[i]);

  int ans = 0;
  REP(it, 2) {
    int N = 0;
    REP(i, n+1) REP(j, m+1)
      if ((i+j)%2 == it) id[i][j] = N++; else
        id[i][j] = -1;

    int cnt = 0;
    REP(i, N) E[i].clear(), F[i].clear();
    REP(i, n) REP(j, m) {
      if (a[i][j] == '/') {
        if ((i+1+j)%2 == it) {
          E[id[i+1][j]].push_back(id[i][j+1]);
          E[id[i][j+1]].push_back(id[i+1][j]);
        }
      }
      if (a[i][j] == '\\') {
        if ((i+j)%2 == it) {
          E[id[i][j]].push_back(id[i+1][j+1]);
          E[id[i+1][j+1]].push_back(id[i][j]);
        }
      }
      if (a[i][j] == '*') {
        cnt++;
        if ((i+j)%2 == it) {
          F[id[i][j]].push_back(id[i+1][j+1]);
          F[id[i+1][j+1]].push_back(id[i][j]);
        } else {
          F[id[i+1][j]].push_back(id[i][j+1]);
          F[id[i][j+1]].push_back(id[i+1][j]);
        }
      }
    }

    int c = 0;
    REP(i, N) bio[i] = false;
    REP(i, N)
      if (!bio[i]) dfs(i, c++);

    if (c-1 > cnt) continue;
    assert(c < MAX);

    REP(i, c) REP(j, c) e[i][j] = 0;
    REP(i, N)
      for (int j: F[i]) {
        e[comp[i]][comp[i]]++;
        e[comp[i]][comp[j]]--;
      }

    ans = add(ans, calcDet(e, c-1));
  }

  printf("%d\n", ans);
  return 0;
}