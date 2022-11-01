#include <bits/stdc++.h>
using namespace std;

inline void addmax(int &x, int y) { x = max(x, y); }

const int N = 1005, MX = 12345;

vector <int> state[MX];
char c[N];
int trie[MX * 10][10], ch[MX][10], ban[25], ban_id[MX], f[MX], g[MX];
int n, x, tot = 1;

void dfs1(int u, vector <int> now, int sum) {
  state[u] = now;
  for (int i = 2; i <= 9; i++) {
    if (sum + i <= x) {
      vector <int> tmp = now;
      tmp.push_back(i);
      if (sum + i == x) {
        bool cando = 0;
        for (int l = 0; l < (int)tmp.size(); l++) {
          int nowsum = 0;
          for (int r = l; r < (int)tmp.size(); r++) {
            nowsum += tmp[r];
            if (ban[nowsum]) {
              cando = 1;
            }
          }
        }
        if (!cando) {
          continue;
        }
      }
      trie[u][i] = ++tot;
      dfs1(tot, tmp, sum + i);
    }
  }
}

int getid(vector <int> a) {
  int now = 1;
  for (int i = 0; i < (int)a.size(); i++) {
    now = trie[now][a[i]];
  }
  return now;
}

int main() {
  memset(f, -1, sizeof(f));
  scanf("%s%d", c + 1, &x); n = strlen(c + 1);
  if (x == 1) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += (c[i] == '1');
    }
    printf("%d\n", ans);
    return 0;
  }
  for (int i = 1; i < x; i++) {
    if (x % i == 0) {
      ban[i] = 1;
    }
  }
  dfs1(1, vector <int> {}, 0);
  for (int i = 1; i <= tot; i++) {
    if (ban_id[i]) {
      continue;
    }
    for (int j = 2; j <= 9; j++) {
      if (j > x) {
        ch[i][j] = 1;
        continue;
      }
      vector <int> now(1, j);
      int sum = j;
      for (int k = (int)state[i].size() - 1; k >= 0; k--) {
        if (state[i][k] + sum <= x) {
          now.push_back(state[i][k]);
          sum += state[i][k];
        } else {
          break;
        }
      }
      reverse(now.begin(), now.end());
      ch[i][j] = getid(now);
    }
  }
  int ans = 0;
  for (int l = 1, r; l <= n; l = r + 1) {
    r = l;
    if (c[l] == '1') {
      ++ans;
      continue;
    }
    while (r < n && c[r + 1] != '1') ++r;
    memset(f, 0, sizeof(f));
    for (int i = l; i <= r; i++) {
      memset(g, 0, sizeof(g));
      for (int j = 1; j <= tot; j++) {
        if (ch[j][c[i] - '0']) {
          addmax(g[ch[j][c[i] - '0']], f[j] + 1);
        }
      }
      for (int j = 1; j <= tot; j++) {
        addmax(f[j], g[j]);
      }
    }
    int maxn = 0;
    for (int i = 1; i <= tot; i++) {
      addmax(maxn, f[i]);
    }
    ans += maxn;
  }
  printf("%d\n", n - ans);
  return 0;
}