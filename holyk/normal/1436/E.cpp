#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
typedef long long LL;
typedef std::pair<int, int> PII;

constexpr int N(1e5 + 5);
int n, a[N], p[N], prev[N], next[N];

struct Node {
  Node *ls, *rs;
  int w;
} t[N * 60], *ptr = t;
void ins(Node *&o, int l, int r, int x, int y) {
  if (!o) {
    o = ptr++, o->w = n + 1;
  } else {
    *ptr = *o, o = ptr++;
  }
  smin(o->w, y);
  if (l == r) return;
  int mid = l + r >> 1;
  x <= mid ? ins(o->ls, l, mid, x, y) : ins(o->rs, mid + 1, r, x, y);
}
int ask(Node *o, int l, int r, int x, int y) {
  if (!o || x > r || y < l) return n + 1;
  if (x <= l && r <= y) return o->w;
  int mid = l + r >> 1;
  return std::min(ask(o->ls, l, mid, x, y), ask(o->rs, mid + 1, r, x, y));
}
Node *root[N];
bool ok[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i], p[i] = n + 1;
  if (std::is_sorted(a + 1, a + 1 + n) && a[n] == 1) 
    return puts("1"), 0;
  for (int i = n; i; i--) next[i] = p[a[i]], p[a[i]] = i;
  for (int i = 1; i <= n; i++) ins(root[0], 1, n + 1, p[i], i);
  for (int i = 1; i <= n; i++) p[i] = 0;
  for (int i = 1; i <= n; i++) prev[i] = p[a[i]], p[a[i]] = i;
  for (int i = 1; i <= n; i++) {
    root[i] = root[i - 1];
    ins(root[i], 1, n + 1, next[i], a[i]);
    if (a[i] == ask(root[prev[i]], 1, n + 1, i, n + 1))
      ok[a[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (i == ask(root[p[i]], 1, n + 1, n + 1, n + 1))
      ok[i] = 1;
  }
  ok[ask(root[0], 1, n + 1, n + 1, n + 1)] = 1;
  int ans = 1;
  while (ok[ans]) ans++;
  std::cout << ans << "\n";
  return 0;
}