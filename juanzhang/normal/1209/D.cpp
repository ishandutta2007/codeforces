#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

const int maxn = 1e5 + 10;
int n, ans, par[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  if ((x = find(x)) != ((y = find(y)))) {
    par[x] = y;
  } else {
    ans++;
  }
}

int main() {
  scanf("%*d %d", &n);
  rep(i, 1, 1e5) par[i] = i;
  rep(i, 1, n) {
    int x, y;
    scanf("%d %d", &x, &y);
    unite(x, y);
  }
  printf("%d", ans);
  return 0;
}