#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10;

int n, m, k;

i64 a[N];

struct Tuple {
  int x, y, z, id;
  Tuple() {}
  Tuple(int _x, int _y, int _z, int _id): x(_x), y(_y), z(_z), id(_id) {}
  inline bool operator< (const Tuple &rhs) const {
    i64 p1, q1, p2, q2;
    if (x < 3) p1 = a[y] + z, q1 = a[y]; else p1 = z, q1 = 1;
    if (rhs.x < 3) p2 = a[rhs.y] + rhs.z, q2 = a[rhs.y]; else p2 = rhs.z, q2 = 1;
    if ((i64)p1 * q2 != (i64)p2 * q1) return (i64)p1 * q2 < (i64)p2 * q1;
    return id < rhs.id;
  }
};

Tuple b[N];

std::vector<Tuple> op[N];

inline bool comp(const Tuple &lhs, const Tuple &rhs) {
  return lhs.x < rhs.x;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (int i = 1; i <= m; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    Tuple cur(x, y, z, i);
    if (x == 1) {
      if (cur.z > b[y].z) b[y] = cur;
    } else if (x == 2) {
      op[y].push_back(cur);
    } else {
      cur.y = 0;
      op[0].push_back(cur);
    }
  }
  std::priority_queue<Tuple> heap;
  for (int i = 1; i <= n; ++i) if (b[i].z > a[i]) op[i].push_back(Tuple(b[i].x, b[i].y, b[i].z - a[i], b[i].id));
  for (int i = 0; i <= n; ++i) std::sort(op[i].begin(), op[i].end());
  for (int i = 0; i <= n; ++i) if (!op[i].empty()) heap.push(op[i].back());
  std::vector<Tuple> ans;
  while (k-- && !heap.empty()) {
    Tuple t = heap.top();
    heap.pop();
    ans.push_back(t);
    int p = t.y;
    a[p] += t.z;
    op[p].pop_back();
    if (!op[p].empty()) heap.push(op[p].back());
  }
  printf("%d\n", ans.size());
  std::sort(ans.begin(), ans.end(), comp);
  for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i].id);
  return 0;
}