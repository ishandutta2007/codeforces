#include <bits/stdc++.h>

constexpr int N(2e5 + 5);
int n, v, f[N], t[N], a[N];
int64_t v1[N], v2[N], b[N];

int lb, c[N];
void add(int p, int x) {
  for (; p <= lb; p += p & -p) {
    c[p] = std::max(c[p], x);
  }
}
void clear(int p) {
  for (; p <= lb; p += p & -p) {
    c[p] = c[0];
  }
}
int ask(int p) {
  int r = c[0];
  for (; p; p -= p & -p) {
    r = std::max(r, c[p]);
  }
  return r;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> v;
  for (int i = 1; i <= n; i++) {
    std::cin >> t[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    v1[i] = 1LL * v * t[i] + a[i];
    v2[i] = 1LL * v * t[i] - a[i];
  }
  memcpy(b, v2, (n + 1) * sizeof(*v2));
  std::sort(b, b + n + 1);
  lb = std::unique(b, b + n + 1) - b;
  for (int i = 0; i <= n; i++) {
    v2[i] = std::lower_bound(b, b + lb, v2[i]) - b + 1; 
  }

  memset(f, 0xc0, sizeof f);
  memset(c, 0xc0, sizeof c);
  f[0] = 0;
  
  for (int m = 1; m <= n; m++) {
    int l = m & m - 1, r = std::min(n + 1, m + (m & -m));
    std::vector<int> p(r - l);
    
    std::iota(p.begin(), p.end(), l);
    std::sort(p.begin(), p.end(), [&](int i, int j) { return v1[i] < v1[j] || v1[i] == v1[j] && i < j; });
    for (int i : p) {
      if (i < m) {
	add(v2[i], f[i]);
      } else {
	f[i] = std::max(f[i], ask(v2[i]) + 1);
      }
    }
    for (int i = l; i < m; i++) clear(v2[i]);
  }

  std::cout << *std::max_element(f, f + n + 1) << "\n";
  return 0;
}