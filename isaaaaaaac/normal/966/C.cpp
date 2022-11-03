#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long LL;
const int N = 1e5 + 5;
const int M = N * 66;

LL a, b[N];
int n;
int ch[M][2], sz[M], Sz = 1;

inline void Ins(LL x) {
  int p = 1;
  sz[p] ++;
  for (int i = 59; ~ i; i --) {
    if (!ch[p][(x >> i) & 1])
      ch[p][(x >> i) & 1] = ++ Sz;
    p = ch[p][(x >> i) & 1];
    sz[p] ++;
  }
}

inline LL Que(LL x) {
  LL res = 0;
  int p = 1, rt = 0, dep = 0;
  for (int i = 59; ~ i; i --) {
    if (!((x >> i) & 1) && sz[ch[p][1]]) {
      dep = i; rt = p;
    }
    p = ch[p][0];
    if (!p) break;
  }
  if (!rt) { puts("No"); exit(0); }
  res = 1LL << dep;
  p = 1;
  for (int i = 59; i >= dep; i --)
    sz[p] --, p = ch[p][0];
  rt = ch[rt][1];
  for (int i = dep - 1; i >= 0; i --) {
    sz[rt] --;
    if (sz[ch[rt][(x >> i) & 1]]) {
      rt = ch[rt][(x >> i) & 1];
      res += ((x >> i) & 1) * (1LL << i);
    }
    else {
      rt = ch[rt][!((x >> i) & 1)];
      res += (!((x >> i) & 1)) * (1LL << i);
    }
  }
  sz[rt] --;
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) {
    scanf("%lld", &a); Ins(a);
  }
  a = 0;
  for (int i = 1; i <= n; i ++) {
    b[i] = Que(a);
    if (a >= (a ^ b[i])) {
      puts("No");
      return 0;
    }
    a ^= b[i];
  }
  puts("Yes");
  for (int i = 1; i <= n; i ++) printf("%lld ", b[i]);
  puts("");
  return 0;
}