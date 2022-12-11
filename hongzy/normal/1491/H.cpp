#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 10;
const int S = 550;
int n, q, sz, a[N], L[N], R[N], B[N], pre[N], tag[S];
bool out[N]; //one-jump < L
int LCA(int u, int v) {
  while(u != v) {
    if(B[u] > B[v]) swap(u, v);
    if(B[u] == B[v]) {
      if(pre[u] == pre[v]) {
        while(u != v) {
          if(u > v) swap(u, v);
          v = max(1, a[v] - tag[B[v]]);
        }
        return u;
      } else {
        u = max(1, pre[u] - tag[B[u]]);
        v = max(1, pre[v] - tag[B[v]]);
      }
    } else {
      v = max(1, pre[v] - tag[B[v]]);
    }
  }
  return u;
}
void build(int u) {
  int l = L[u], r = L[u + 1] - 1;
  rep(i, l, r) a[i] = max(1, a[i] - tag[u]);
  bool o = 1;
  rep(i, l, r) pre[i] = a[i] < l ? a[i] : (o = 0, pre[a[i]]);
  tag[u] = 0; out[u] = o;
}
void slow(int l, int r, int x) {
  rep(i, l, r) a[i] = max(1, a[i] - x);
  build(B[l]);
}
void upd(int l, int r, int x) {
  if(B[l] == B[r]) {
    slow(l, r, x); return ;
  }
  slow(l, L[B[l] + 1] - 1, x);
  slow(L[B[r]], r, x);
  rep(i, B[l] + 1, B[r] - 1) {
    if(out[i]) {
      tag[i] += x;
    } else {
      rep(j, L[i], L[i + 1] - 1) a[j] = max(1, a[j] - x);
      build(i);
    }
  }
}
int main() {
  scanf("%d%d", &n, &q);
  rep(i, 2, n) scanf("%d", a + i);
  sz = (int)sqrt(n);
  rep(i, 2, n) {
    B[i] = (i - 2) / sz + 1;
    if(B[i] != B[i - 1]) {
      L[B[i]] = i;
    }
  }
  L[B[n] + 1] = n + 1;
  rep(i, 1, B[n]) build(i);
  int op, l, r, x;
  rep(i, 1, q) {
    scanf("%d%d%d", &op, &l, &r);
    if(op == 1) {
      scanf("%d", &x);
      upd(l, r, x);
    }
    if(op == 2) {
      printf("%d\n", LCA(l, r));
    }
  }
  return 0;
}