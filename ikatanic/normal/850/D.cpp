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

const int M = 88;

bool f[M][M*M][M];
int r[M][M*M][M];

void upd(int i, int j, int k, int p) {
  f[i][j][k] = true;
  r[i][j][k] = p;
}

int main(void) {
  f[0][0][0] = true;

  vector<bool> have(M, false);
  int k;
  scanf("%d", &k);
  REP(i, k) {
    int x;
    scanf("%d", &x);
    have[x] = true;
  }

  REP(i, M-1) REP(j, M*M) REP(k, M) {
    if (f[i][j][k]) {
      if (!have[i]) {
        upd(i+1, j, k, -1);
      } else {
        if (j + i >= k * (k+1) / 2 && j + i < M*M && k+1 < M) {
          upd(i+1, j+i, k+1, i);
          upd(i, j+i, k+1, i);
        }
      }
    }
  }

  int n = 1;
  while (n < M && !f[M-1][n*(n-1)/2][n]) n++;
  assert(n < M);
  
  int s = n*(n-1)/2;
  int i = M-1;

  vector<int> degs;
  while (n > 0) {
    int w = r[i][s][n];
    if (w == -1) {
      i--;
    } else {
      degs.push_back(w);
      n--;
      s -= w;
      if (w == i-1) i--;
    }
  }


  n = degs.size();
  vector<string> adj(n, string(n, '0'));
  vector<pair<int, int>> v;
  REP(i, n) v.push_back({degs[i], i});

  while (v.size()) {
    sort(v.begin(), v.end());
    auto p = v.back();
    v.pop_back();

    int d = p.first;
    assert(d <= (int)v.size());
    REP(i, (int)v.size()) {
      if (i < d) adj[p.second][v[i].second] = '1';
      else adj[v[i].second][p.second] = '1', v[i].first--;
    }
  }

  printf("%d\n", n);
  REP(i, n) puts(adj[i].c_str());
  return 0;
}