#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int ui;
const ui inf = 3e9;
const int maxn = 5e4 + 5;
const int blk = 200, sizb = maxn / blk + 2;  //, sizc = 1e4;
int mnm[sizb][maxn], tag[sizb];
ui val[sizb];
int a[maxn], b[maxn];
ui c[maxn];
vector<int> divs[maxn];
// ui gcd2(int a, int b) {
//   if (a < b) swap(a, b);
//   while (b > 0) {
//     a %= b;
//     swap(a, b);
//   }
//   return a * a;
// }
unsigned int gcd2(unsigned int u, unsigned int v) {
  int shift;
  if (u == 0) return v;
  if (v == 0) return u;
  shift = __builtin_ctz(u | v);
  u >>= __builtin_ctz(u);
  do {
    unsigned m;
    v >>= __builtin_ctz(v);
    v -= u;
    m = (int)v >> 31;
    u += v & m;
    v = (v + m) ^ m;
  } while (v != 0);
  return u * u << shift * 2;
}
ui calc(int bid, int x) {
  ui res = inf;
  for (auto v : divs[x])
    if (mnm[bid][v] < maxn) res = min(res, (ui)x / v * mnm[bid][v]);
  return res;
}
void addtag(int bid, int x) {
  val[bid] = calc(bid, x);
  tag[bid] = x;
}
void pushtag(int bid) {
  if (!~tag[bid]) return;
  ui *cc = c + bid * blk;
  int *bb = b + bid * blk;
  for (int i = 0; i < blk; i++)
    cc[i] = (ui)tag[bid] * bb[i] / gcd2(tag[bid], bb[i]);
  tag[bid] = -1;
}
void update(int bid) {
  ui *cc = c + bid * blk;
  val[bid] = inf;
  for (int i = 0; i < blk; i++) val[bid] = min(val[bid], cc[i]);
}
int main() {
  for (int i = 1; i < maxn; i++)
    for (int j = i; j < maxn; j += i) divs[j].push_back(i);
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  fill(val, val + n, inf);
  fill(tag, tag + n, -1);
  fill(mnm[0], mnm[sizb], maxn);
  for (int i = 0; i < n; i++) {
    c[i] = a[i] * b[i] / gcd2(a[i], b[i]);
    int bid = i / blk;
    val[bid] = min(val[bid], c[i]);
    for (auto v : divs[b[i]]) mnm[bid][v] = min(mnm[bid][v], b[i] / v);
  }
  while (q--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    l--;
    int lid = l / blk, rid = r / blk;
    int lr = (lid + 1) * blk, rl = rid * blk;
    if (op == 1) {
      int x;
      scanf("%d", &x);
      ui ans = inf;
      if (lid == rid) {
        pushtag(lid);
        for (int i = l; i < r; i++) c[i] = (ui)b[i] * x / gcd2(b[i], x);
        update(lid);
      } else {
        pushtag(lid);
        pushtag(rid);
        for (int i = l; i < lr; i++) c[i] = (ui)b[i] * x / gcd2(b[i], x);
        for (int i = rl; i < r; i++) c[i] = (ui)b[i] * x / gcd2(b[i], x);
        update(lid);
        update(rid);
        for (int i = lid + 1; i < rid; i++) addtag(i, x);
      }
    } else {
      ui ans = inf;
      if (lid == rid) {
        pushtag(lid);
        for (int i = l; i < r; i++) ans = min(ans, c[i]);
      } else {
        pushtag(lid);
        pushtag(rid);
        for (int i = l; i < lr; i++) ans = min(ans, c[i]);
        for (int i = rl; i < r; i++) ans = min(ans, c[i]);
        for (int i = lid + 1; i < rid; i++) ans = min(ans, val[i]);
      }
      printf("%u\n", ans);
    }
  }
  return 0;
}