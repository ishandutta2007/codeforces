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

constexpr int N(2e4 + 5);
int n, k, a[N], dp[N];
struct Line {
  int k, b;
  inline int func(int x) { return k * x + b; }
  inline double intersect(const Line &rhs) const {
    return (double)(rhs.b - b) / (k - rhs.k);
  }
  inline bool check(const Line &p, const Line &q) const {
    assert((k < p.k) && (k < q.k));
    return 1LL * (b - p.b) * (q.k - k) <= 1LL * (b - q.b) * (p.k - k);
  }
};
struct Node {
  Node *ls, *rs;
  Line v;
} t[N * 30], *ptr;
void ins(Node *&o, int l, int r, Line x) {
  if (!o) {
    o = ptr++;
    o->ls = o->rs = 0;
    o->v = x;
    return;
  }
  *ptr = *o, o = ptr++;
  int mid = l + r >> 1;
  bool lf = x.func(l) < o->v.func(l);
  bool ri = x.func(r) < o->v.func(r);
  bool mi = x.func(mid) < o->v.func(mid);
  if (mi) std::swap(o->v, x);
  if (l == r || lf == ri) return;
  lf != mi ? ins(o->ls, l, mid, x) : ins(o->rs, mid + 1, r, x);
}
int ask(Node *o, int l, int r, int x) {
  if (!o) return 1e9;
  int mid = l + r >> 1;
  if (x == mid) return o->v.func(x);
  return std::min(o->v.func(x), x < mid ? ask(o->ls, l, mid, x) : ask(o->rs, mid + 1, r, x));
}
struct Block {
  std::deque<Line> q;
  int idx;
  inline void push_back(const Line &x) {
    while (q.size() >= 2 && !x.check(q[q.size() - 2], q[q.size() - 1])) q.pop_back();
    q.push_back(x);
  }
  inline void push_front(const Line &x) {
    while (q.size() >= 2 && !q[1].check(x, q[0])) q.pop_front();
    q.push_front(x);
  }
  inline LL ask(int x) {
    if (q.empty()) return 1e9;
    while (q.size() >= 2 && q[0].func(x) >= q[1].func(x)) q.pop_front();
    return q[0].func(x);
    // int l = 0, r = q.size() - 1;
    // while (l < r) {
    //   int mid = l + r >> 1;
    //   assert(mid < r);
    //   if (q[mid].intersect(q[mid + 1]) - 1E-12 < x)
    //     l = mid + 1;
    //   else
    //     r = mid;
    // }
    // return q[l].func(x);
  }
};
void calc(int k) {
 // static LL f[N];
  static Block s[N], *tp, now;
  static Node *rt[N];
  static Line ls[N];
  static int f[N];
  tp = s, ptr = t;
  for (int i = 1; i <= n; i++) {
    now.q.clear(), now.idx = i;
    now.q.push_back({-i + 1, dp[i - 1]});
    while (tp != s && a[i] >= a[tp->idx]) {
      if (tp->q.size() < now.q.size()) {
        while (!tp->q.empty()) {
          now.push_front(tp->q.back());
          tp->q.pop_back();
        }
      } else {
        tp->q.swap(now.q);
        while (!tp->q.empty()) {
          now.push_back(tp->q.front());
          tp->q.pop_front();
        }
      }
      tp--;
    }
    tp++;
    tp->q.swap(now.q), tp->idx = i;

    rt[tp - s] = rt[tp - s - 1];
    ins(rt[tp - s], 1, n, {a[i], tp->ask(a[i])});
    f[i] = ask(rt[tp - s], 1, n, i);
    // dbg(i, dp[i]);
  }
  for (int i = 1; i <= n; i++) dp[i] = f[i];
}
int main() {
  readInt(n, k);
  dp[0] = 1e9;
  for (int i = 1, max = 0; i <= n; i++) {
    readInt(a[i]);
    smax(max, a[i]);
    dp[i] = 1LL * max * i;
  }
  for (int i = 2; i <= k; i++) calc(i);
  std::cout << dp[n];
  return 0;
}