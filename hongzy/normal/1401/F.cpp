#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, a[1 << 18];
ll s[1 << 19];
bool rev[20], swp[20];
void build(int u, int l, int k) {
  if(k == 0) { s[u] = a[l]; return ; }
  build(u << 1, l, k - 1);
  build(u << 1 | 1, l | 1 << (k - 1), k - 1);
  s[u] = s[u << 1] + s[u << 1 | 1];
}
void modify(int u, int k, int p, int v) {
  if(rev[k]) p ^= (1 << k) - 1;
  if(k == 0) { s[u] = v; return ; }
  if(p < (1 << (k - 1))) modify(u << 1 | swp[k - 1], k - 1, p, v);
  else modify(u << 1 | (1 ^ swp[k - 1]), k - 1, p ^ (1 << (k - 1)), v);
  s[u] = s[u << 1] + s[u << 1 | 1];
}
ll query(int u, int k, int ql, int qr) {
  if(ql == 0 && qr == (1 << k) - 1) return s[u];
  if(rev[k]) ql ^= (1 << k) - 1, qr ^= (1 << k) - 1, swap(ql, qr);
  if(qr < (1 << (k - 1))) return query(u << 1 | swp[k - 1], k - 1, ql, qr);
  if(ql >= (1 << (k - 1))) return query(u << 1 | (1 ^ swp[k - 1]), k - 1, ql ^ (1 << (k - 1)), qr ^ (1 << (k - 1)));
  return query(u << 1 | swp[k - 1], k - 1, ql, (1 << (k - 1)) - 1)
  + query(u << 1 | (1 ^ swp[k - 1]), k - 1, 0, qr ^ (1 << (k - 1)));
}
int main() {
  scanf("%d%d", &n, &q);
  for(int i = 0; i < (1 << n); i ++)
    scanf("%d", a + i);
  build(1, 0, n);
  int op, l, r, k;
  for(int i = 0; i < q; i ++) {
    scanf("%d", &op);
    if(op == 1) {
      scanf("%d%d", &l, &k);
      modify(1, n, l - 1, k);
    }
    if(op == 2) { scanf("%d", &k); rev[k] ^= 1; }
    if(op == 3) { scanf("%d", &k); swp[k] ^= 1; }
    if(op == 4) {
      scanf("%d%d", &l, &r);
      printf("%lld\n", query(1, n, l - 1, r - 1));
    }
  }
  return 0;
}