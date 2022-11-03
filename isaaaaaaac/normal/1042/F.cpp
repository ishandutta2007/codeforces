#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define travel(x, i) for (int i = fir[x]; i; i = e[i].nxt) 
using namespace std;

const int N = 1e6 + 50;

struct edge {
  int nxt, to;
} e[N << 1];
int fir[N], cnt = 1, deg[N];

inline void addedge(int x, int y) {
  e[++ cnt] = (edge) { fir[x], y }; fir[x] = cnt;
}

int n, k, ans = 0;

inline int Dfs(int x, int f) {
  if (deg[x] == 1) return 0;
  vector <int> son;
  travel(x, i)
    if (e[i].to != f) {
      int k = Dfs(e[i].to, x);
      if (k != -1)
        son.push_back(k + 1);
    }
  sort(son.begin(), son.end(), greater <int> ());
  for (int i = 0; i < (int)son.size(); i ++) {
    int dis = son[i] + (i + 1 < (int)son.size() ? son[i + 1] : 0);
    if (dis > k) ans ++;
    else return son[i];
  }
  return -1;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1, x, y; i < n; i ++) {
    scanf("%d%d", &x, &y);
    addedge(x, y); addedge(y, x);
    deg[x] ++; deg[y] ++;
  }
  int rt = 0;
  for (int i = 1; i <= n; i ++)
    if (deg[i] > 1) { rt = i; break; }
  if (Dfs(rt, 0) != -1) ans ++;
  printf("%d\n", ans);
  return 0;
}