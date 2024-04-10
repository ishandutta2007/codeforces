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

const int MAX = 300030;

bool bio[MAX];
bool bad[MAX];
vector<pair<int, int>> E[MAX];

vector<int> ans;

int dfs(int x) {
  bio[x] = true;

  int bal = bad[x];
  for (auto& p: E[x]) {
    if (!bio[p.first]) {
      if (dfs(p.first)) {
        bal ^= 1;
        ans.push_back(p.second);
      }
    }
  }
  return bal;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  int dontcare = -1;
  int cnt = 0;
  REP(i, n) {
    int d;
    scanf("%d", &d);
    if (d == 1) bad[i] = true, cnt++;
    if (d == -1) dontcare = i;
  }

  if (cnt % 2) {
    if (dontcare == -1) {
      puts("-1");
      return 0;
    }
    bad[dontcare] = true;
  }

  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back({b, i});
    E[b].push_back({a, i});
  }

  dfs(0);
  
  printf("%d\n", (int)ans.size());
  for (int x: ans) printf("%d\n", x+1);
  return 0;
}