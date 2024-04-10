#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 100000 + 10;

int n;

std::vector< std::pair<int, int> > q;
int ans[N];

std::vector<int> pool[N], mem[N];

void init() {
  int m;
  for (scanf("%d%d", &n, &m); m--;) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l < r) pool[l].push_back(r);
  }
  int tot;
  scanf("%d", &tot);
  q.resize(tot);
  for (int i = 0; i < tot; ++i) {
    scanf("%d%d", &q[i].first, &q[i].second);
    if (q[i].first < q[i].second) mem[q[i].first].push_back(i); else ans[i] = q[i].first;
  }
}

int max[2 * N];

inline int pos(int l, int r) { return (l + r) | (l != r); }

void apply(int l, int r, int v) {
  int id = pos(l, r);
  max[id] = std::min(max[id], v);
}

void release(int l, int r) {
  int id = pos(l, r), mid = (l + r) >> 1;
  apply(l, mid, max[id]);
  apply(mid + 1, r, max[id]);
}

void update(int l, int r) {
  int id = pos(l, r), mid = (l + r) >> 1;
  max[id] = std::max(max[pos(l, mid)], max[pos(mid + 1, r)]);
}

void modify(int l, int r, int p, int q, int v) {
  if (p <= l && r <= q) {
    apply(l, r, v);
    return;
  }
  release(l, r);
  int mid = (l + r) >> 1;
  if (p <= mid) modify(l, mid, p, q, v);
  if (q > mid) modify(mid + 1, r, p, q, v);
  update(l, r);
}

int res;
bool flag;

void query(int l, int r, int p, int q) {
  if (!flag) return;
  if (l < r) release(l, r);
  int mid = (l + r) >> 1;
  if (p <= l && r <= q) {
    int id = pos(l, r);
    if (max[id] <= q + 1) {
      res = r + 1;
    } else {
      if (l < r) {
        query(l, mid, p, q);
        query(mid + 1, r, p, q);
      }
      flag = false;
    }
  } else {
    if (p <= mid) query(l, mid, p, q);
    if (q > mid) query(mid + 1, r, p, q);
  }
  if (l < r) update(l, r);
}

int main() {
  init();
  memset(max, 0x3f, sizeof max);
  for (int i = n; i > 0; --i) {
    for (int j = 0; j < pool[i].size(); ++j) {
      int k = pool[i][j];
      modify(1, n, i, k - 1, k);
    }
    for (int j = 0; j < mem[i].size(); ++j) {
      int k = mem[i][j];
      res = i, flag = true;
      query(1, n, i, q[k].second - 1);
      ans[k] = res;
    }
  }
  for (int i = 0; i < q.size(); ++i) printf("%d\n", ans[i]);
  return 0;
}