#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
const int maxn = 2010;
char a[maxn][maxn];
int n, m;

struct node {
  int x1, y1, x2, y2;
} data[26];

vector <pii> vec[26];

void solve() {
  for (int i = 0; i < 26; i++) {
    vec[i].clear();
    data[i].x1 = data[i].y1 = data[i].x2 = data[i].y2 = 0;
  }
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != '.') vec[a[i][j] - 'a'].push_back(pii(i, j));
    }
  }
  for (int k = 0; k < 26; k++) {
    if (vec[k].empty()) continue;
    set <int> r, c;
    for (pii p : vec[k]) {
      r.insert(p.first);
      c.insert(p.second);
    }
    if (r.size() > 1 && c.size() > 1) {
      puts("NO"); return;
    }
    data[k] = node{*r.begin(), *c.begin(), *(--r.end()), *(--c.end())};
  }
  int val = -1;
  for (int k = 0; k < 26; k++) {
    if (!data[k].x1) continue;
    val = k;
    if (data[k].x1 == data[k].x2) {
      int x = data[k].x1;
      for (int i = data[k].y1; i <= data[k].y2; i++) {
        if (a[x][i] == '.' || a[x][i] < 'a' + k) {
          puts("NO"); return;
        }
      }
    } else {
      int y = data[k].y1;
      for (int i = data[k].x1; i <= data[k].x2; i++) {
        if (a[i][y] == '.' || a[i][y] < 'a' + k) {
          puts("NO"); return;
        }
      }
    }
  }
  puts("YES");
  for (int k = val; ~k; k--) {
    int x = data[k].x1, y = data[k].y1;
    if (x) {
      for (int t = 0; t <= val; t++) {
        if (!data[t].x1) data[t] = node{x, y, x, y};
      }
      break;
    }
  }
  printf("%d\n", val + 1);
  for (int k = 0; k <= val; k++) {
    printf("%d %d %d %d\n", data[k].x1, data[k].y1, data[k].x2, data[k].y2);
  }
}

int main() {
  int Tests;
  scanf("%d", &Tests);
  while (Tests--) solve();
  return 0;
}