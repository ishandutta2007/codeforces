#include <bits/stdc++.h>

bool smin(int &x, int y) {
  return y < x ? x = y, 1 : 0;
}
void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  a--, b--;
  std::vector<int> p(n), seq(n);
  for (int i = 0; i < n; i++) std::cin >> p[i];
  std::iota(seq.begin(), seq.end(), 0);
  std::sort(seq.begin(), seq.end(), [&](int i, int j) { return p[i] < p[j]; });
  
  int s = 1 << std::__lg(n * 2 - 1);
  std::vector<std::vector<int>> t1(s * 2), t2(s * 2);

  for (int i : seq) {
    for (int o = i + s; o; o >>= 1) {
      t1[o].push_back(i);
    }
  }
  std::reverse(seq.begin(), seq.end());
  for (int i : seq) {
    int l = std::max(0, i - p[i]);
    int r = std::min(n, i + p[i] + 1);
    for (l += s, r += s; l < r; l /= 2, r /= 2) {
      if (l & 1) t2[l++].push_back(i);
      if (r & 1) t2[--r].push_back(i);
    }
  }

  std::vector<int> q = {a}, d(n, -1);

  d[a] = 0;
  for (int i = 0; i < q.size(); i++) {
    int x = q[i];
    for (int o = x + s; o; o >>= 1) {
      while (!t2[o].empty() && p[t2[o].back()] <= p[x]) {
	int y = t2[o].back();
	t2[o].pop_back();
	if (d[y] == -1) {
	  d[y] = d[x] + 1;
	  q.push_back(y);
	}
      }
    }
    int l = std::max(0, x - p[x]);
    int r = std::min(n, x + p[x] + 1);

    auto trans = [&](int o) {
		   while (!t1[o].empty() && p[t1[o].back()] >= p[x]) {
		     int y = t1[o].back();
		     t1[o].pop_back();
		     if (d[y] == -1) {
		       d[y] = d[x] + 1;
		       q.push_back(y);
		     }
		   }
		 };
    for (l += s, r += s; l < r; l /= 2, r /= 2) {
      if (l & 1) trans(l++);
      if (r & 1) trans(--r);
    }
  }

  std::cout << d[b] << "\n";
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}