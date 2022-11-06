#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
typedef long long LL;
typedef std::pair<int, int> PII;

constexpr int N(2e5 + 5);

int n, m, cnt, ch[N][26], fa[N], pos[N];
std::vector<int> g[N];
int ins(const std::string &s) {
  int o = 0;
  for (char c : s) {
    if (!ch[o][c - 'a']) ch[o][c - 'a'] = ++cnt;
    o = ch[o][c - 'a']; 
  }
  return o;
}
int in[N], out[N];
void dfs(int x) {
  static int c = 0;
  in[x] = ++c;
  for (int y : g[x]) dfs(y);
  out[x] = c;
}
void build() {
  static int q[N], l, r;
  q[l = r = 1] = 0;
  while (l <= r) {
    int o = q[l++];
    if (fa[o] == o) fa[o] = 0;
    for (int i = 0; i < 26; i++) {
      (ch[o][i] ? fa[q[++r] = ch[o][i]] : ch[o][i]) = ch[fa[o]][i];
    }
  }
  for (int i = 1; i <= cnt; i++) g[fa[i]].push_back(i);
  dfs(0);
}
// FenwickTree
int c[N];
inline void add(int p, int x) {
  for (; p <= cnt + 1; p += p & -p) c[p] += x;
}
inline int ask(int p) {
  int r = 0;
  for (; p; p -= p & -p) r += c[p];
  return r;
}

std::string s[N];
struct Query {
  int k, r, id, tp;
} q[N * 5];
int ans[N * 3];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
    pos[i] = ins(s[i]);
  }
  build();
  for (int i = 1, k, l, r; i <= m; i++) {
    std::cin >> l >> r >> k;
    q[i] = { k, l - 1, i, -1 };
    q[i + m] = { k, r, i, 1 };
  }
  std::sort(q + 1, q + 1 + m + m, [](const Query &a, const Query &b) { return a.r < b.r; });
  for (int i = 1, t = 1; i <= m << 1; i++) {
    while (t <= q[i].r) {
      int o = 0;
      for (char c : s[t]) {
        o = ch[o][c - 'a'];
        assert(in[o]);
        add(in[o], 1);
      }
      t++;
    }
    int k = pos[q[i].k];
    ans[q[i].id] += q[i].tp * (ask(out[k]) - ask(in[k] - 1));
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}