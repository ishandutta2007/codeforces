// Author:  HolyK
// Created: Fri Sep 16 14:43:30 2022
#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(2e5 + 5);
int n, q, a[N], b[N], c[N];
struct Node {
  int ls, rs;
  LL s1, s2;
} t[N * 40];
int cnt;
void ins(int &o, int l, int r, int x, int k, int b) {
  t[++cnt] = t[o], o = cnt;
  t[o].s1 += k;
  t[o].s2 += b;
  if (l == r) return;
  int m = l + r >> 1;
  if (x <= m) {
    ins(t[o].ls, l, m, x, k, b);
  } else {
    ins(t[o].rs, m + 1, r, x, k, b);
  }
}

void build(int &o, int l, int r) {
  o = ++cnt;
  if (l == r) {
    t[o].s1 = b[l];
    return;
  }
  int m = l + r >> 1;
  build(t[o].ls, l, m);
  build(t[o].rs, m + 1, r);
  t[o].s1 = t[t[o].ls].s1 + t[t[o].rs].s1;
}

int root[N];
PII s[N];
void solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i] >> b[i];
    a[i] = (c[i] + b[i] - 1) / b[i];
  }

  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 1);
  std::sort(p.begin(), p.end(), [&](int i, int j) {
    return a[i] < a[j];
  });

  int cur = 0;
  build(root[0], 1, n);
  for (int i : p) {
    if (a[i] > 2e5) break;
    while (cur < a[i]) {
      root[cur + 1] = root[cur];
      cur++;
    }
    ins(root[cur], 1, n, i, -b[i], c[i]);
  }
  while (cur < 2e5) {
    root[cur + 1] = root[cur];
    cur++;
  }

  int top = 0;
  for (int i = n; i; i--) {
    s[++top] = {i, 0};
    a[i] = c[i];
  }
  s[0].first = n + 1;

  LL ans = 0;
  std::cin >> q;
  while (q--) {
    int now;
    LL h;
    std::cin >> now >> h;
    while (top) {
      if (s[top].first == s[top - 1].first - 1) {
        int i = s[top].first; 
        int x = std::min<LL>(a[i] + b[i] * LL(now - s[top].second), c[i]);

        if (h >= x) {
          h -= x;
          top--;
        } else {
          a[i] = x - h;
          s[top].second = now;
          break;
        }
      } else {
        int x = s[top].first, y = s[top - 1].first - 1,
            cur = now - s[top--].second;
        std::function<bool(int, int, int)> dfs = [&](int o, int l, int r) {
          if (r < x || y < l) return false;
          if (x <= l && r <= y) {
            LL val = t[o].s1 * cur + t[o].s2;
            if (h >= val) {
              h -= val;
              return false;
            }
            if (l == r) {
              if (l < y) {
                s[++top] = {l + 1, now - cur};
                a[l + 1] = 0;
              }
              s[++top] = {l, now};
              a[l] = val - h;
              return true;
            }
          }
          int m = l + r >> 1;
          return dfs(t[o].ls, l, m) || dfs(t[o].rs, m + 1, r);
        };

        if (dfs(root[cur], 1, n)) break;
      }
    }

    // std::cerr << "AA\n";
    if (!top) {
      ans += h;
      // std::cerr << "AD " << h << "\n";
    }
    if (s[top].first != 1) {
      s[++top] = {1, now};
      a[1] = 0;
    }
  
    // for (int i = top; i; i--) {
    //   std::cerr << s[i].first << " ";
    // }
    // std::cerr << "!! " << a[n] << "\n";
  }

  std::cout << ans << "\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}