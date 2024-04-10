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

int w[MAX], b[MAX];
vector<int> E[MAX];
vector<int> v;
bool bio[MAX];


void dfs(int x) {
  if (bio[x]) return;
  bio[x] = true;
  v.push_back(x);
  for (int y: E[x]) dfs(y);
}

int main(void) {
  int N, M, W;
  scanf("%d %d %d", &N, &M, &W);
  REP(i, N) scanf("%d", &w[i]);
  REP(i, N) scanf("%d", &b[i]);
  REP(i, M) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  vector<int> f(W + 1, 0);
  REP(i, N) {
    if (!bio[i]) {
      v.clear();
      dfs(i);

      int total_w = 0;
      int total_b = 0;
      for (int x: v) {
        total_w += w[x];
        total_b += b[x];
      }

      for (int j = W; j >= 0; --j) {
        if (j + total_w <= W) f[j+total_w] = max(f[j+total_w], f[j] + total_b);
        for (int x: v) {
          if (j + w[x] <= W) f[j+w[x]] = max(f[j+w[x]], f[j] + b[x]);
        }
      }
    }
  }

  int ans = *max_element(f.begin(), f.end());
  printf("%d\n", ans);
  return 0;
}