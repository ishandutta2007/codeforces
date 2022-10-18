#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int qcnt = 0;

int ask(vector<int>& v) {
  if (v.size() <= 1) return 0;
  qcnt++;

  cout << "? " << v.size() << "\n";
  for (int x : v) cout << x + 1 << " ";
  cout << "\n";
  cout.flush();

  int m;
  cin >> m;
  return m;
}

vector<int> get_neighbors(int x, vector<int>& ys) {
  if (ys.size() == 0) return {};

  vector<int> ret;
  queue<pair<vector<int>, int>> Q;

  ys.push_back(x);
  int cnt = ask(ys);
  ys.pop_back();
  cnt -= ask(ys);
  Q.push({ys, cnt});

  while (!Q.empty()) {
    vector<int> v = Q.front().first;
    int cnt = Q.front().second;
    Q.pop();

    if (cnt == 0) continue;

    assert(v.size() > 0);

    if (v.size() == 1) {
      ret.push_back(v[0]);
      continue;
    }

    vector<int> w;
    FOR(i, (int)v.size() / 2, (int)v.size()) { w.push_back(v[i]); }
    v.resize((int)v.size() / 2);

    v.push_back(x);
    int cntv = ask(v);
    v.pop_back();
    cntv -= ask(v);

    int cntw = cnt - cntv;

    Q.push({v, cntv});
    Q.push({w, cntw});
  }
  return ret;
}

namespace PathFinder {
stack<int> S;
vector<int> found_path;

void dfs(int x, int y, vector<vector<int>>& E, vector<bool>& visited) {
  if (found_path.size()) return;
  if (visited[x]) return;

  S.push(x);
  visited[x] = true;

  if (x == y) {
    while (!S.empty()) {
      found_path.push_back(S.top());
      S.pop();
    }
    return;
  }

  for (int w : E[x]) {
    dfs(w, y, E, visited);
    if (found_path.size()) return;
  }

  S.pop();
}

vector<int> get_path(int a, int b, vector<vector<int>>& E) {
  found_path.clear();
  while (!S.empty()) S.pop();
  vector<bool> visited(E.size());
  dfs(a, b, E, visited);
  assert(found_path.size());
  return found_path;
}
}  // namespace PathFinder

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  queue<int> Q;
  vector<int> which_side(N);
  vector<bool> visited(N), seen(N);
  vector<int> side[2];
  vector<vector<int>> E(N);

  Q.push(0);
  seen[0] = true;
  which_side[0] = 0;

  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();

    visited[x] = true;
    auto& my_side = side[which_side[x]];
    my_side.push_back(x);

    if (ask(my_side) > 0) {  // not bipartite
      for (int i = 0; i < (int)my_side.size() - 1; ++i) {
        vector<int> w = {my_side[i], x};
        if (ask(w) > 0) {
          vector<int> path = PathFinder::get_path(x, my_side[i], E);
          assert((int)path.size() % 2);
          cout << "N\n";
          cout << path.size() << "\n";
          for (int x : path) {
            cout << x + 1 << " ";
          }
          cout << "\n";
          return 0;
        }
      }
      assert(false);
    }

    vector<int> unseen;
    REP(i, N) if (!seen[i]) unseen.push_back(i);

    vector<int> neighbors = get_neighbors(x, unseen);

    for (int y : neighbors) {
      E[x].push_back(y);
      E[y].push_back(x);
      seen[y] = true;
      which_side[y] = which_side[x] ^ 1;
      Q.push(y);
    }
  }

  cout << "Y\n";
  cout << side[0].size() << "\n";
  for (int x : side[0]) cout << x + 1 << " ";
  cout << "\n";

  return 0;
}