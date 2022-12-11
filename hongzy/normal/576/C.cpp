#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1e6 + 10;
int n, sz = 1000, bel[N];
struct node {
  int x, y, id;
  bool operator < (const node &b) const {
    return bel[x] == bel[b.x] ? (bel[x] & 1 ? y < b.y : y > b.y) : x < b.x;
  }
} a[N];
int main() {
  scanf("%d", &n);
  rep(i, 0, int(1e6)) bel[i] = (i + sz - 1) / sz;
  rep(i, 1, n) {
    scanf("%d%d", &a[i].x, &a[i].y);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1);
  rep(i, 1, n) {
    printf("%d ", a[i].id);
  }
  putchar('\n');
  return 0;
}