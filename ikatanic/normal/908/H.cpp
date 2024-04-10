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

void Transform(llint *A, int n) {
  if (n == 0) return;
  int mid = 1<<(n-1);
  REP(i, mid) A[mid + i] += A[i];
  Transform(A, n-1);
  Transform(A + mid, n-1);
}

llint InvertOne(llint *A, int n, int x) {
  if (n == 0) return A[0];
  int mid = 1<<(n-1);

  if (x < mid) {
    return InvertOne(A, n-1, x);
  } else {
    return InvertOne(A + mid, n - 1, x - mid) - InvertOne(A, n - 1, x - mid);
  }
}

void rec(int x, int mask, vector<vector<bool>>& e, vector<llint>& ret) {
  if (x == (int)e.size()) {
    ret[mask] = 1;
    return;
  }

  rec(x + 1, mask, e, ret);
  bool ok = true;
  REP(i, x) {
    if (mask & (1<<i)) {
      if (!e[i][x]) {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    rec(x + 1, mask | (1<<x), e, ret);
  }
}

int main(void) {
  int N;
  scanf("%d", &N);

  vector<vector<int>> a(N, vector<int>(N, 0));
  vector<int> sz(N, 1);
  REP(i, N) {
    static char buf[111];
    scanf("%s", buf);

    REP(j, N) {
      int mask = 0;
      if (buf[j] == 'A') mask = 2;
      if (buf[j] == 'X') mask = 1;
      if (buf[j] == 'O') mask = 3;
      a[i][j] = mask;
    }
  }


  while (true) {
    bool changed = false;

    REP(j, N) REP(i, j) {
      if (a[i][j] == 2) {
        REP(x, N) {
          if (x == i || x == j) continue;
          a[i][x] &= a[j][x];
          a[x][i] &= a[x][j];
        }

        REP(x, N) {
          a[x].erase(a[x].begin() + j);
        }
        a.erase(a.begin() + j);
        sz[i] += sz[j];
        sz.erase(sz.begin() + j);
        N--;

        REP(x, N) REP(y, x) {
          if (a[x][y] == 0) {
            puts("-1");
            return 0;
          }
        }
        changed = true;
        break;
      }
    }

    if (!changed) break;
  }

  int ret = 0;
  int cliques = 0;

  vector<vector<bool>> e;
  REP(i, N) {
    if (sz[i] > 1) {
      e.push_back({});
      REP(j, N) {
        if (sz[j] > 1) e.back().push_back(a[i][j] == 3);
      }
      ret += sz[i];
    } else {
      cliques++;
    }
  }

  int M = e.size();

  vector<llint> x(1<<M, 0);
  rec(0, 0, e, x);

  Transform(x.data(), M);

  vector<llint> y(1<<M, 0);
  y[0] = 1;

  Transform(y.data(), M);

  while (InvertOne(y.data(), M, (1<<M) - 1) == 0) {
    REP(i, (1<<M)) {
      y[i] *= x[i];
    }

    cliques++;
  }

  ret += cliques - 1;

  printf("%d\n", ret);
  return 0;
}