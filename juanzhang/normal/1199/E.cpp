#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
const int maxn = 3e5 + 10;
bool flg[maxn];
int n, m, cnt, tot, data[maxn];

map <pii, int> mp;

vector <int> e[maxn];

void solve() {
  mp.clear();
  scanf("%d %d", &n, &m), cnt = 3 * n;
  for (int i = 1; i <= cnt; i++) {
    e[i].clear(), flg[i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    e[u].push_back(v), e[v].push_back(u);
    mp[pii(u, v)] = i, mp[pii(v, u)] = i;
  }
  tot = 0;
  for (int u = 1; u <= cnt; u++) {
    if (flg[u]) continue;
    for (int v : e[u]) {
      if (flg[v]) continue;
      flg[u] = flg[v] = 1;
      data[++tot] = mp[pii(u, v)];
      break;
    }
  }
  if (tot >= n) {
    puts("Matching");
    for (int i = 1; i <= n; i++) {
      printf("%d%c", data[i], "\n "[i < n]);
    }
    return;
  }
  tot = 0;
  for (int i = 1; i <= cnt; i++) {
    if (!flg[i]) data[++tot] = i;
  }
  if (tot >= n) {
    puts("IndSet");
    for (int i = 1; i <= n; i++) {
      printf("%d%c", data[i], "\n "[i < n]);
    }
    return;
  }
  puts("Impossible");
}

int main() {
  int Tests;
  scanf("%d", &Tests);
  while (Tests--) solve();
  return 0;
}