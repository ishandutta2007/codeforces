#include <cstdio>
#include <iostream>
#include <set>
// #include <vector>
using namespace std;
const int maxn = 2e5 + 5;
// vector<int> r[maxn], c[maxn];
int r[maxn], c[maxn];
int f[maxn];
int ff(int u) { return f[u] == u ? u : f[u]=ff(f[u]); }
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= q; i++) f[i] = i;
  for (int i = 1; i <= q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (r[x]) f[ff(r[x])] = i;
    if (c[y]) f[ff(c[y])] = i;
    r[x] = c[y] = i;
  }
  set<int> st;
  for (int i = 1; i <= q; i++) st.insert(ff(i));
  int ans = st.size() - 1;
  for (int i = 1; i <= n; i++)
    if (!r[i]) ans++;
  for (int i = 1; i <= m; i++)
    if (!c[i]) ans++;
  printf("%d\n", ans);
  return 0;
}