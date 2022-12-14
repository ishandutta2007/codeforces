#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

const int N = 1000 + 10;

int n, m, u, v, tot;
char s[N][N];

int anc[N * N], mem[N * N], rank[N * N];

int find(int x) { return anc[x] == x ? x : find(anc[x]); }
int eval(int x) { return anc[x] == x ? x : (anc[x] = eval(anc[x])); }

int pos(int x, int y) {
  if (0 <= x && x < n && 0 <= y && y < m) return s[x][y] == '#' ? x * m + y : -1;
  if ((x == -1 && y == -1) || (x == n && y == m)) return -1;
  return x == -1 || y == m ? v : u;
}

std::set< std::pair<int, int> > pool;
std::vector< std::pair<int, int> > stk;

void meld(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (rank[x] > rank[y]) std::swap(x, y);
  stk.push_back(std::make_pair(x, anc[x]));
  anc[x] = y;
  if (rank[x] == rank[y]) ++rank[y];
}

void revert() {
  for (; !stk.empty(); stk.pop_back()) {
    int x = stk.back().first, y = stk.back().second;
    rank[x] = rank[anc[x]] = 0;
    anc[x] = y;
  }
}

std::vector<int> block;

void mark(int x, int y) {
  int id = pos(x, y);
  for (int dx = -1; dx <= 1; ++dx) {
    for (int dy = -1; dy <= 1; ++dy) {
      int t = pos(x + dx, y + dy);
      if (t != -1) meld(id, t), block.push_back(mem[t]);
    }
  }
}

bool check(int x, int y) {
  if (!(0 <= x && x < n && 0 <= y && y < m) || s[x][y] == '#') return true;
  if ((x == 0 && y == 0) || (x == n - 1 && y == m - 1)) return true;
  bool p = false, q = false;
  for (int dx = -1; dx <= 1; ++dx) {
    for (int dy = -1; dy <= 1; ++dy) {
      int t = pos(x + dx, y + dy);
      if (t != -1) {
        if (find(t) == find(u)) p = true;
        if (find(t) == find(v)) q = true;
        if (p && q) return false;
      }
    }
  }
  return true;
}

int main() {
  int q;
  scanf("%d%d%d", &n, &m, &q);
  tot = n * m;
  for (int i = 0; i < n; ++i) scanf(" %s", s[i]);
  u = tot++;
  v = tot++;
  for (int i = 0; i < tot; ++i) rank[anc[i] = i] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] != '#') continue;
      int id = i * m + j;
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          int t = pos(i + dx, j + dy);
          if (t != -1) anc[eval(id)] = eval(t);
        }
      }
    }
  }
  for (int i = 0; i < tot; ++i) mem[i] = eval(i);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] != '.' || (i == 0 && j == 0) || (i == n - 1 && j == m - 1)) continue;
      int id = i * m + j;
      static int cur[N];
      int temp = 0;
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          int t = pos(i + dx, j + dy);
          if (t != -1) cur[temp++] = t;
        }
      }
      std::sort(cur, cur + temp);
      temp = std::unique(cur, cur + temp) - cur;
      for (int a = 0; a < temp; ++a) {
        for (int b = 0; b < a; ++b) {
          int p = find(cur[a]), q = find(cur[b]);
          if (p > q) std::swap(p, q);
          pool.insert(std::make_pair(p, q));
        }
      }
    }
  }
  while (q--) {
    int k;
    scanf("%d", &k);
    static int r[N], c[N];
    for (int i = 0; i < k; ++i) scanf("%d%d", &r[i], &c[i]), --r[i], --c[i];
    block.clear();
    block.push_back(find(u));
    block.push_back(find(v));
    for (int i = 0; i < k; ++i) s[r[i]][c[i]] = '#';
    for (int i = 0; i < k; ++i) mark(r[i], c[i]);
    bool ans = find(u) != find(v);
    for (int i = 0; ans && i < k; ++i)
      for (int dx = -1; ans && dx <= 1; ++dx)
        for (int dy = -1; ans && dy <= 1; ++dy)
          if (!check(r[i] + dx, c[i] + dy)) ans = false;
    if (ans) {
      std::sort(block.begin(), block.end());
      block.erase(std::unique(block.begin(), block.end()), block.end());
      std::vector<int> p, q;
      for (int i = 0; i < block.size(); ++i) {
        if (find(block[i]) == find(u)) p.push_back(block[i]);
        if (find(block[i]) == find(v)) q.push_back(block[i]);
      }
      for (int i = 0; ans && i < p.size(); ++i) {
        for (int j = 0; ans && j < q.size(); ++j) {
          int a = p[i], b = q[j];
          if (a > b) std::swap(a, b);
          if (pool.count(std::make_pair(a, b))) ans = false;
        }
      }
    }
    revert();
    for (int i = 0; i < k; ++i) s[r[i]][c[i]] = '.';
    puts(ans ? "YES" : "NO");
    fflush(stdout);
  }
  return 0;
}