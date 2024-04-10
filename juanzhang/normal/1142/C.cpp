#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, top, st[maxn];

struct node {
  ll x, y;
} a[maxn];

db slope(int x, int y) {
  return (a[x].y - a[y].y) / (a[x].x - a[y].x);
}

//(y1 - y2) / (x1 - x2) >= (y2 - y3) / (x2 - x3)

//(y1 - y2) * (x2 - x3) >= (y2 - y3) * (x1 - x2)

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    a[i] = {x, y - 1ll * x * x};
  }
  sort(a + 1, a + n + 1, [] (node a, node b) {
    return a.x < b.x || (a.x == b.x && a.y > b.y);
  });
  for (int i = 1; i <= n; i++) {
    if (i > 1 && a[i].x == a[i - 1].x) {
      continue;
    }
    for (; top > 1; top--) {
      ll x1 = a[i].x, y1 = a[i].y;
      ll x2 = a[st[top]].x, y2 = a[st[top]].y;
      ll x3 = a[st[top - 1]].x, y3 = a[st[top - 1]].y;
      if ((y1 - y2) * (x2 - x3) < (y2 - y3) * (x1 - x2)) {
        break;
      }
    }
    st[++top] = i;
  }
  printf("%d", top - 1);
  return 0;
}