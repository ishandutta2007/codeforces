#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <ll, int> pii;
const int maxn = 5e4 + 10;
char str[maxn];
int n, a[maxn], b[maxn];

priority_queue <pii> Q;

int main() {
  scanf("%s", str + 1);
  n = strlen(str + 1);
  int cur = 0; ll res = 0;
  rep(i, 1, n) {
    int x, y;
    if (str[i] == '?') {
      scanf("%d %d", &x, &y);
      Q.push(pii(y - x, i));
      cur--, res += y, str[i] = ')';
    } else if (str[i] == '(') {
      cur++;
    } else if (str[i] == ')') {
      cur--;
    }
    if (cur < 0) {
      if (Q.empty()) {
        return puts("-1"), 0;
      }
      pii p = Q.top(); Q.pop();
      cur += 2, res -= p.first, str[p.second] = '(';
    }
  }
  if (cur) {
    return puts("-1"), 0;
  }
  printf("%I64d\n%s", res, str + 1);
  return 0;
}