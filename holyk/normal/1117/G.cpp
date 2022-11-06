#include <bits/stdc++.h>
#ifdef LOCAL
#define dbg(args...) std::cerr << "\033[32;1m" << #args << " -> ", err(args)
#else
#define dbg(...)
#endif
inline void err() { std::cerr << "\033[0m\n"; }
template<class T, class... U>
inline void err(const T &x, const U &... a) { std::cerr << x << ' '; err(a...); }
template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar());) w = w * 10 + (c & 15);
  if (p) w = -w;
}
template <class T, class... U>
inline void readInt(T &w, U &... a) { readInt(w), readInt(a...); }
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

typedef long long LL;
typedef std::pair<int, int> PII;

constexpr int N(1e6 + 5);
int n, m, a[N], s[N], l[N], r[N];


class FenwickTree {
 public:
  void add(int l, int r) {
    add(v, l, 1), add(v, r + 1, -1);
    add(vi, l, l), add(vi, r + 1, -r - 1);
  }
  LL ask(int l, int r) {
    return ask(v, r) * (r + 1) - ask(v, l - 1) * l - ask(vi, r) + ask(vi, l - 1);
  }
  void clear() {
    memset(v, 0, sizeof v);
    memset(vi, 0, sizeof vi);
  }
 private:
  LL v[N], vi[N];
  void add(LL c[], int p, int x) {
    for (; p <= n; p += p & -p) c[p] += x;
  }
  LL ask(LL c[], int p) {
    LL r = 0;
    for (; p; p -= p & -p) r += c[p];
    return r;
  }
} t;

int ql[N], qr[N];
std::vector<int> lq[N], rq[N];
LL b[N], ans[N];
int main() {
  readInt(n, m);
  for (int i = 1; i <= n; i++) readInt(a[i]);
  for (int i = 1; i <= n; i++) {
    while (s[0] && a[s[s[0]]] < a[i]) s[0]--;
    b[l[i] = s[s[0]] + 1]++;
    // printf("+ %d %d\n", s[s[0]], i);
    s[++s[0]] = i;
  }
  s[0] = 0;
  for (int i = n; i; i--) {
    while (s[0] && a[s[s[0]]] < a[i]) s[0]--;
    if (s[0])
      b[r[i] = s[s[0]]]--;
    else 
      r[i] = n + 1;
    // printf("- %d %d\n", i, s[s[0]]);
    
    s[++s[0]] = i;
  }
  for (int i = 1; i <= n; i++) b[i] += b[i - 1];
  for (int i = 1; i <= n; i++) b[i] += b[i - 1];
  for (int i = 1; i <= m; i++) readInt(ql[i]), lq[ql[i]].push_back(i);
  for (int i = 1; i <= m; i++) readInt(qr[i]), rq[qr[i]].push_back(i);
  for (int i = 1; i <= n; i++) {
    for (int j : lq[i]) ans[j] -= b[ql[j] - 1] + t.ask(ql[j], qr[j]);
    t.add(l[i], r[i] - 1);
  }
  t.clear();
  for (int i = n; i; i--) {
    for (int j : rq[i]) ans[j] += b[qr[j]] - t.ask(ql[j], qr[j]);
    t.add(l[i], r[i] - 1);
  }
  for (int i = 1; i <= m; i++) printf("%lld ", ans[i]);
  return 0;
}