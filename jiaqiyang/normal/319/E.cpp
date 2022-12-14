#include <bits/stdc++.h>

typedef long long int64;

const int N = 1 << 17;

int n, op[N], a[N], b[N];

int anc[N], l[N], r[N];

inline int find(int x) { return (anc[x] == x) ? x : (anc[x] = find(anc[x])); }

inline void join(int u, int v) {
  u = find(u), v = find(v);
  if (u != v) {
    l[v] = std::min(l[v], l[u]);
    r[v] = std::max(r[v], r[u]);
    anc[u] = v;
  }
}

std::vector<int> pool[N * 4];

void merge(int id, int l, int r, int pos, int val) {
  for (std::vector<int>::iterator it = pool[id].begin(); it != pool[id].end(); ++it) join(*it, val);
  pool[id].clear();
  if (l == r) return;
  int mid = (l + r) / 2;
  if (pos <= mid)
    merge(id << 1, l, mid, pos, val);
  else
    merge(id << 1 | 1, mid + 1, r, pos, val);
}

void update(int id, int l, int r, int a, int b, int val) {
  if (a <= l && r <= b) {
    pool[id].push_back(val);
    return;
  }
  int mid = (l + r) / 2;
  if (a <= mid) update(id << 1, l, mid, a, b, val);
  if (b > mid) update(id << 1 | 1, mid + 1, r, a, b, val);
}

#define check(l, r, a) ((l) < (a) && (a) < (r))

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) anc[i] = i;
  static std::vector<int> sorted;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", op + i, a + i, b + i);
    if (op[i] == 2) continue;
    sorted.push_back(a[i]);
    sorted.push_back(b[i]);
  }
  std::sort(sorted.begin(), sorted.end());
  sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
  int tot = sorted.size() - 1;
  for (int i = 0; i <= tot; ++i) anc[i] = i;
  for (int i = 1, id = 0; i <= n; ++i) {
    switch (op[i]) {
      case 1:
        id++;
        l[id] = a[id] = std::lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin();
        r[id] = b[id] = std::lower_bound(sorted.begin(), sorted.end(), b[i]) - sorted.begin();
        anc[id] = id;
        merge(1, 0, tot, a[id], id);
        merge(1, 0, tot, b[id], id);
        if (l[find(id)] + 1 <= r[find(id)] - 1)
          update(1, 0, tot, l[find(id)] + 1, r[find(id)] - 1, id);
        break;
      case 2:
        b[i] = find(b[i]);
        puts((find(a[i]) == b[i] || check(l[b[i]], r[b[i]], a[a[i]]) || check(l[b[i]], r[b[i]], b[a[i]])) ? "YES" : "NO");
        break;
    }
  }
  return 0;
}