#include <cstdio>
#include <cstdlib>
#include <vector>

typedef long long i64;
typedef std::pair<int, int> Info;

const int N = 100000 + 10;

struct Line {
  int x, y, z, id;
  Line(int _x, int _y, int _z, int _id): x(_x), y(_y), z(_z), id(_id) {}
};

inline i64 det(int a, int b, int c, int d) { return (i64)a * d - (i64)b * c; }
inline i64 det(const Line &a, const Line &b, const Line &c) {
  i64 p = (i64)b.y * c.z - (i64)b.z * c.y;
  i64 q = (i64)b.x * c.z - (i64)b.z * c.x;
  i64 r = (i64)b.x * c.y - (i64)b.y * c.x;
  return a.x * p - a.y * q + a.z * r;
}

std::vector<Info> ans;

void solve(std::vector<Line> &line, int k) {
  const int n = line.size();
  if (n <= k) {
    printf("YES\n%d\n", n + ans.size());
    for (int i = 0; i < n; ++i) printf("%d -1\n", line[i].id);
    for (int i = 0; i < ans.size(); ++i) printf("%d %d\n", ans[i].first, ans[i].second);
    exit(0);
  }
  if (!k) return;
  std::vector<Line> cur;
  for (int i = 3 * k * k; i--;) {
    int x = rand() % n, y = rand() % n;
    while (y == x) y = rand() % n;
    const Line &a = line[x], &b = line[y];
    if (det(a.x, a.y, b.x, b.y) == 0) continue;
    cur.clear();
    for (int j = 0; j < n; ++j) if (j != x && j != y && det(a, b, line[j])) cur.push_back(line[j]);
    int t = n - cur.size();
    if (cur.size() > std::max(k - 1, n - n / k)) continue;
    ans.push_back(Info(line[x].id, line[y].id));
    solve(cur, k - 1);
    ans.pop_back();
    if (t > k) return;
  }
}

int main() {
  srand(19937);
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<Line> line;
  for (int i = 1; i <= n; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    line.push_back(Line(x, y, z, i));
  }
  solve(line, k);
  puts("NO");
  return 0;
}