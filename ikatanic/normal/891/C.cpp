#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 500500;

struct TimeMachine {
  struct Change {
    int* ptr;
    int old_val;
    int timestamp;
  };

  stack<Change> S;

  void set(int* ptr, int val, int timestamp) {
    if (val != *ptr) {
      S.push({ptr, *ptr, timestamp});
      *ptr = val;
    }
  }

  void revert(int timestamp) {
    while (!S.empty() && S.top().timestamp > timestamp) {
      *S.top().ptr = S.top().old_val;
      S.pop();
    }
  }
};

struct DSU {
  int dad[MAX];
  int rank[MAX];
  TimeMachine tm;

  void init(int n) {
    for (int i = 0; i < n; ++i)
      dad[i] = i, rank[i] = 0;
  }

  int findset(int x, int t) {
    if (x == dad[x]) return x;
    tm.set(&dad[x], findset(dad[x], t), t);
    return dad[x];
  }

  void merge(int x, int y, int t) {
    x = findset(x, t);
    y = findset(y, t);
    if (x == y) return;

    if (rank[x] > rank[y]) swap(x, y);
    tm.set(&dad[x], y, t);
    if (rank[x] == rank[y]) tm.set(&rank[y], rank[y] + 1, t);
  }

  void undo(int t) {
    tm.revert(t - 1);
  }
} dsu;

int u[MAX], v[MAX], w[MAX];
vector<int> e[MAX];

bool ans[MAX];
vector<pair<vector<int>, int>> qe[MAX];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    scanf("%d %d %d", &u[i], &v[i], &w[i]);
    --u[i], --v[i];
    e[w[i]].push_back(i);
  }

  int q;
  scanf("%d", &q);
  REP(i, q) {
    int k;
    scanf("%d", &k);
    ans[i] = true;

    vector<int> e(k);
    REP(j, k) {
      scanf("%d", &e[j]);
      e[j]--;
    }

    sort(e.begin(), e.end(), [&] (const int& x, const int &y) {
        return w[x] < w[y];
      });

    int x = 0;
    while (x < (int)e.size()) {
      int y = x;
      vector<int> ex;
      while (y < (int)e.size() && w[e[x]] == w[e[y]]) {
        ex.push_back(e[y]);
        y++;
      }
      qe[w[e[x]]].push_back({ex, i});
      x = y;
    }
  }

  dsu.init(n);
  REP(w, MAX) {
    if (qe[w].size() + e[w].size() == 0) {
      continue;
    }
    for (auto& q: qe[w]) {
      for (int i: q.first) {
        if (dsu.findset(u[i], w) == dsu.findset(v[i], w)) {
          ans[q.second] = false;
          break;
        }
        dsu.merge(u[i], v[i], w);
      }

      dsu.undo(w);
    }

    for (int i: e[w]) {
      dsu.merge(u[i], v[i], w);
    }
  }

  REP(i, q) {
    puts(ans[i] ? "YES" : "NO");
  }
  return 0;
}