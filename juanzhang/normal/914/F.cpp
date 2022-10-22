#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 10;
int n, q;
char a[maxn], str[maxn];

bitset <maxn> bit, pos[26];

int main() {
  scanf("%s %d", a + 1, &q);
  n = strlen(a + 1);
  for (int i = 1; i <= n; i++) {
    pos[a[i] - 'a'].set(i);
  }
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x; char c;
      scanf("%d %s", &x, &c);
      pos[a[x] - 'a'].reset(x);
      pos[c - 'a'].set(x);
      a[x] = c;
    } else {
      int l, r;
      scanf("%d %d %s", &l, &r, str + 1);
      bit.set();
      int len = strlen(str + 1);
      for (int i = 1; i <= len; i++) {
        bit &= pos[str[i] - 'a'] >> (i - 1);
      }
      // [l, r - len + 1] [0, r - l - len + 1] [maxn - r + l + len - 2, maxn - 1]
      printf("%d\n", (int) (bit >> l << (maxn - r + l + len - 2)).count());
    }
  }
  return 0;
}