#include <bits/stdc++.h>
using namespace std;

#define mid ((s + t) >> 1)
#define lson k << 1, s, mid
#define rson k << 1 | 1, mid + 1, t
const int maxn = 2e5 + 10;
int n, m, val[maxn << 2], sum[62][maxn << 2]; char str[maxn];

int get(char c) {
  if (c < 58) return c - 48;
  if (c <= 'Z') return c - 'A' + 10;
  return c - 'a' + 36;
}

void maintain(int k) {
  for (int i = 0; i < 62; i++) {
    sum[i][k] = sum[i][k << 1] + sum[i][k << 1 | 1];
  }
  val[k] = val[k << 1] + val[k << 1 | 1];
}

void build(int k, int s, int t) {
  if (s == t) {
    sum[get(str[s])][k] = val[k] = 1; return;
  }
  build(lson), build(rson), maintain(k);
}

void print(int k, int s, int t) {
  if (s == t) {
    if (val[k]) putchar(str[s]); return;
  }
  print(lson), print(rson);
}

bool upd(int k, int s, int t, int l, int r, int x) {
  if (l > val[k] || r < 1 || !sum[x][k]) return 0;
  if (s == t) return sum[x][k] = val[k] = 0, 1;
  return upd(rson, l - val[k << 1], r - val[k << 1], x) | upd(lson, l, r, x) ? maintain(k), 1 : 0;
}

int main() {
  scanf("%d %d %s", &n, &m, str + 1);
  build(1, 1, n); int l, r; char c;
  while (m--) {
    scanf("%d %d %c", &l, &r, &c);
    upd(1, 1, n, l, r, get(c));
  }
  print(1, 1, n);
  return 0;
}