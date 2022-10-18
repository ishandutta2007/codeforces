#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;

vector<int> E[MAX];
llint f[MAX][2], g[MAX][2];

llint dfs(int x, int dad) {
  llint ret = 0;

  g[x][0]++;

  for (int y : E[x]) {
    if (y != dad) {
      ret += dfs(y, x);

      REP(a, 2) REP(b, 2) {
        int par = a ^ b;
        llint cnt = g[x][a] * g[y][b];
        llint sum = f[x][a] * g[y][b] + g[x][a] * f[y][b];
        ret += (sum + par * cnt) / 2;
      }

      REP(a, 2) {
        f[x][a] += f[y][a];
        g[x][a] += g[y][a];
      }
    }
  }

  swap(f[x][0], f[x][1]);
  swap(g[x][0], g[x][1]);

  f[x][0] += g[x][0];
  f[x][1] += g[x][1];

  return ret;
}

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  REP(i, N - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  cout << dfs(0, -1) << "\n";
  return 0;
}