#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
struct fibo {
  int k;
  ll tot, fir;
  fibo *l, *r;
};
vector<fibo *> stk;
fibo *comb(fibo *a, fibo *b) {
  free(a->l);
  free(a->r);
  a->l = a->r = NULL;
  fibo *c = new fibo{a->k + 1, a->fir + b->tot, a->fir, a, b};
  return c;
}
void free(fibo *u) {
  if (!u) return;
  free(u->l);
  free(u->r);
  delete u;
}
void push(fibo *f) {
  if (!f) return;
  while (stk.size()) {
    if (stk.back()->k > f->k + 1) {
      if (!(stk.back()->k - f->k & 1)) break;
      auto u = stk.back();
      stk.pop_back();
      // stk.push_back(u->l);
      push(u->l);
      stk.push_back(u->r);
      delete u;
      continue;
    }
    if (stk.back()->k == f->k + 1) {
      f = comb(stk.back(), f);
      stk.pop_back();
      continue;
    }
    break;
  }
  if (stk.size()) {
    if (stk.back()->k < f->k) {
      for (auto u : stk) free(u);
      stk.clear();
    } else if (stk.size() >= 2 && stk[stk.size() - 2]->k == f->k) {
      auto tmp = stk.back();
      stk.pop_back();
      for (auto u : stk) free(u);
      stk = {tmp};
    }
  }
  stk.push_back(f);
}
int main() {
  int n;
  scanf("%d", &n);
  char ch = getchar();
  ll sum = 1, las = 1;
  while (n--) {
    while ((ch = getchar()) != '\n') {
      // putchar(ch);
      push(new fibo{ch == '1', las, las, NULL, NULL});
      las = (sum - stk.back()->tot) % mod;
      // printf("found %d", stk.back().k);
      sum = (sum + las) % mod;
      // for (auto v : stk) printf("fib: k = %d, v = %lld\n", v.k, v.tot);
      // printf("sum = %lld, val = %lld, fib = %d\n", sum, las, stk.back().k);
    }
    printf("%lld\n", (las % mod + mod) % mod);
  }
  return 0;
}