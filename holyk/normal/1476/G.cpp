#include <bits/stdc++.h>

constexpr int N(1e5 + 5), T(1024);
struct Info {
  int l, r, t, k, id;
  bool operator<(const Info &rhs) const {
    return l / T == rhs.l / T ? r / T == rhs.r / T ? t  < rhs.t : r < rhs.r : l < rhs.l;
  }
};
int c[N], cc[N], col;
bool vis[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int &x : a) std::cin >> x;
  std::vector<Info> q;
  std::vector<std::array<int, 3>> p;
  auto b = a;
  for (int i = 0; i < m; i++) {
    int opt, l, r, k;
    std::cin >> opt >> l >> r;
    if (opt == 1) {
      std::cin >> k;
      q.push_back({l - 1, r - 1, (int)p.size(), k, (int)q.size()});
    } else {
      p.push_back({l - 1, b[l - 1], r});
      b[l - 1] = r;
    }
  }
  int x = 0, y = -1, z = 0;
  std::vector<int> ans(q.size()), v;
  auto add = [&](int x, int y) {
    cc[c[x]]--;
    if (!c[x]) col++;
    c[x] += y;
    if (!c[x]) col--;
    cc[c[x]]++;
    if (c[x] && !vis[c[x]]) v.push_back(c[x]), vis[c[x]] = true;
    // if (cc[c[x]] == 1) v.push_back(c[x]);
  };
  std::sort(q.begin(), q.end());
  for (auto [l, r, t, k, id] : q) {
    while (y < r) add(a[++y], 1);
    while (x > l) add(a[--x], 1);
    while (y > r) add(a[y--], -1);
    while (x < l) add(a[x++], -1);
    while (z < t) {
      auto [i, x, y] = p[z++];
      a[i] = y;
      if (i < l || i > r) continue;
      add(x, -1), add(y, 1);

    }
    while (z > t) {
      auto [i, x, y] = p[--z];
      a[i] = x;
      if (i < l || i > r) continue;
      add(y, -1), add(x, 1);

    }
    if (col < k) {
      ans[id] = -1;
    } else {
      for (int i = 0; i < v.size(); i++) {
	while (i < v.size() && !cc[v[i]]) {
	  vis[v[i]] = false;
	  std::swap(v[i], v.back());
	  v.pop_back();
	}
      }
      std::sort(v.begin(), v.end());
      // v.resize(std::unique(v.begin(), v.end()) - v.begin());
      // std::cout << "q! " << l << " " << r << " " << t << " " << k << " \n";
      // for (int x : v) {
      // 	std::cout << x << " : " << cc[x] << "\n";
      // }
      ans[id] = 1e5;
      for (int i = 0, j = 0, s = 0; i < v.size(); s -= cc[v[i++]]) {
	while (j < v.size() && s < k) s += cc[v[j++]];
	if (s < k) break;
	ans[id] = std::min(ans[id], v[j - 1] - v[i]);
      }
      // std::cout << ans[id] << "\n";
    }
  }
  for (int x : ans) std::cout << x << "\n";
  return 0;
}

/*
12 11
2 1 1 2 1 1 3 2 1 1 3 3
1 2 10 3
1 2 11 3
2 7 2
1 3 9 2
1 1 12 1
1 1 12 4
2 12 4
1 1 12 4
2 1 5
1 3 12 2
1 1 4 3
 */