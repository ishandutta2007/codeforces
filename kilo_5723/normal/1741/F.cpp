#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int inf = 1e9 + 5;
const int maxn = 2e5 + 5;
vector<vector<int>> e;
struct seg {
  int l, r;
};
bool operator<(seg a, seg b) {
  if (a.l != b.l) return a.l < b.l;
  if (a.r != b.r) return a.r > b.r;
  return false;
}
seg a[maxn];
int ans[maxn];
set<seg> st;
void insert(seg s) {
  auto it = st.upper_bound(s);
  if (it != st.begin() && prev(it, 1)->r >= s.r) return;
  st.insert(s);
  it = st.find(s);
  for (auto nx = next(it, 1); nx != st.end() && nx->r <= s.r; nx = next(it, 1))
    st.erase(nx);
}
int query(seg s) {
  int res = inf;
  auto it = st.lower_bound(s);
  if (it != st.end()) res = min(res, max(0, it->l - s.r));
  if (it != st.begin()) res = min(res, max(0, s.l - prev(it, 1)->r));
  return res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    e.assign(n + 1, {});
    for (int i = 0; i < n; i++) {
      int c;
      scanf("%d%d%d", &a[i].l, &a[i].r, &c);
      e[c].push_back(i);
      ans[i] = inf;
    }
    st.clear();
    for (int i = 1; i <= n; i++) {
      for (auto u : e[i]) ans[u] = min(ans[u], query(a[u]));
      for (auto u : e[i]) insert(a[u]);
    }
    st.clear();
    for (int i = n; i >= 1; i--) {
      for (auto u : e[i]) ans[u] = min(ans[u], query(a[u]));
      for (auto u : e[i]) insert(a[u]);
    }
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}