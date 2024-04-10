#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[300000], b[300000];
const int n = 1<<20;
int ma[n*2], lazy[n*2];

void add(int i, int v) {
  for (i += n+1; i > 1; i >>= 1) {
    if (i&1)
      lazy[i-1] += v, ma[i-1] += v;
    ma[i>>1] = max(ma[i],ma[i^1])+lazy[i>>1];
  }
}

int query() {
  if (ma[1] <= 0) return -1;
  int i = 1;
  int acc = 0;
  while (i < n) {
    acc += lazy[i];
    if (ma[i*2+1]+acc > 0)
      i = i*2+1;
    else
      i = i*2;
  }
  return i-n;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  scanf("%d%d", &n,&m);
  for (int i = 0; i < n; i++) {
    scanf("%d",a+i);
    add(a[i], 1);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d",b+i);
    add(b[i],-1);
  }
  int q;
  scanf("%d",&q);
  while (q--) {
    int t, i, x;
    scanf("%d%d%d",&t,&i,&x);
    i--;
    if (t == 1) {
      add(a[i],-1);
      a[i] = x;
      add(a[i], 1);
    } else {
      add(b[i], 1);
      b[i] = x;
      add(b[i],-1);
    }
    printf("%d\n", query());
  }
}