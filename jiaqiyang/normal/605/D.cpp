#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

#define fst first
#define snd second

typedef std::pair<int, int> Info;

const int N = 200000 + 10, S = 20 * N, INF = 1 << 27;

int n, a[N], b[N], c[N], d[N];
int tx, ty;

int discrete(int p[], int q[]) {
  std::vector<int> sorted;
  for (int i = 1; i <= n; ++i) {
    sorted.push_back(p[i]);
    sorted.push_back(q[i]);
  }
  std::sort(sorted.begin(), sorted.end());
  sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
  for (int i = 1; i <= n; ++i) {
    p[i] = std::lower_bound(sorted.begin(), sorted.end(), p[i]) - sorted.begin() + 1;
    q[i] = std::lower_bound(sorted.begin(), sorted.end(), q[i]) - sorted.begin() + 1;
  }
  return sorted.size();
}

int lch[S], rch[S], tot;
std::vector<int> adj[S];

int modify(int orig, int l, int r, int p, int v) {
  int res = ++tot;
  adj[res].push_back(orig);
  adj[res].push_back(v);
  lch[res] = lch[orig];
  rch[res] = rch[orig];
  if (l == r) return res;
  int mid = (l + r) / 2;
  if (p <= mid) lch[res] = modify(lch[orig], l, mid, p, v); else rch[res] = modify(rch[orig], mid + 1, r, p, v);
  return res;
}

void query(int id, int l, int r, int p, int q, int v) {
  if (!id) return;
  if (p <= l && r <= q) {
    adj[v].push_back(id);
    return;
  }
  int mid = (l + r) / 2;
  if (p <= mid) query(lch[id], l, mid, p, q, v);
  if (q > mid) query(rch[id], mid + 1, r, p, q, v);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
  std::vector<int> st;
  for (int i = 1; i <= n; ++i) if (a[i] == 0 && b[i] == 0) st.push_back(i);
  tx = discrete(a, c);
  ty = discrete(b, d);
  static std::vector<int> ins[N], que[N];
  for (int i = 1; i <= n; ++i) {
    ins[a[i]].push_back(i);
    que[c[i]].push_back(i);
  }
  static int root[N];
  tot = n;
  for (int i = 1; i <= tx; ++i) {
    root[i] = root[i - 1];
    for (auto j : ins[i]) root[i] = modify(root[i], 1, ty, b[j], j);
    for (auto j : que[i]) query(root[i], 1, ty, 1, d[j], j);
  }
  std::priority_queue<Info> heap;
  static int dist[S], pre[S];
  for (int i = 1; i <= tot; ++i) dist[i] = INF;
  for (auto i : st) heap.push(Info(-(dist[i] = 1), i));
  while (!heap.empty()) {
    Info cur = heap.top();
    int a = cur.snd;
    heap.pop();
    if (-cur.fst > dist[a]) continue;
    for (auto b : adj[a]) {
      int t = dist[a] + (b <= n);
      if (t < dist[b]) {
        heap.push(Info(-(dist[b] = t), b));
        pre[b] = a;
      }
    }
  }
  if (dist[n] == INF) return puts("-1"), 0;
  std::vector<int> ans;
  for (int i = n; i; i = pre[i]) if (i <= n) ans.push_back(i);
  printf("%u\n", ans.size());
  for (int i = ans.size() - 1; i >= 0; --i) printf("%d%c", ans[i], i ? ' ' : '\n');
  return 0;
}