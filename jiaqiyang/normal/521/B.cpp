#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10, MOD = 1000000009;

int n;

struct Point {
  int x, y;
  Point() {}
  Point(int _x, int _y): x(_x), y(_y) {}
  inline bool operator< (const Point &rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
} p[N];

std::map<Point, int> pool;

std::set<int> succ[N], pred[N];

inline void link(int a, int b) {
  succ[a].insert(b);
  pred[b].insert(a);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].x, &p[i].y), pool[p[i]] = i;
  for (std::map<Point, int>::iterator it = pool.begin(); it != pool.end(); ++it) {
    int id = it->second;
    const Point &p = it->first;
    Point q(p.x - 1, p.y - 1);
    if (pool.find(q) != pool.end()) link(id, pool[q]);
    q = Point(p.x, p.y - 1);
    if (pool.find(q) != pool.end()) link(id, pool[q]);
    q = Point(p.x + 1, p.y - 1);
    if (pool.find(q) != pool.end()) link(id, pool[q]);
  }
  std::set<int> cur;
  for (int i = 0; i < n; ++i) cur.insert(i);
  for (int i = 0; i < n; ++i) if (succ[i].size() == 1) cur.erase(*succ[i].begin());
  int ans = 0;
  static int mem[N];
  mem[0] = 1;
  for (int i = 1; i <= n; ++i) mem[i] = (i64)mem[i - 1] * n % MOD;
  static bool flag[N];
  for (int i = 0; i < n; ++i) {
    int t = (i & 1) ? *cur.begin() : *cur.rbegin();
    cur.erase(t);
    flag[t] = true;
    ans = (ans + (i64)t * mem[n - 1 - i]) % MOD;
    std::vector<int> temp;
    for (std::set<int>::iterator it = succ[t].begin(); it != succ[t].end(); ++it) {
      pred[*it].erase(t);
      temp.push_back(*it);
    }
    for (std::set<int>::iterator it = pred[t].begin(); it != pred[t].end(); ++it) {
      succ[*it].erase(t);
      if (succ[*it].size() == 1) cur.erase(*succ[*it].begin());
    }
    for (int i = 0; i < temp.size(); ++i) {
      int a = temp[i];
      if (flag[a]) continue;
      cur.insert(a);
      for (std::set<int>::iterator it = pred[a].begin(); it != pred[a].end(); ++it) if (succ[*it].size() <= 1) cur.erase(a);
    }
  }
  printf("%d\n", ans);
  return 0;
}