#include <bits/stdc++.h>

#define IL __inline__ __attribute__((always_inline))

#define For(i, a, b) for (int i = a, i##end = b; i <= i##end; ++ i)
#define FOR(i, a, b) for (int i = a, i##end = b; i < i##end; ++ i)
#define Rep(i, a, b) for (int i = a, i##end = b; i >= i##end; -- i)
#define REP(i, a, b) for (int i = a - 1, i##end = b; i >= i##end; -- i)

typedef long long LL;

template <class T>
IL bool chkmax(T &a, const T b) {
  return a < b ? ((a = b), 1) : 0;
}

template <class T>
IL bool chkmin(T &a, const T b) {
  return a > b ? ((a = b), 1) : 0;
}

template <class T>
IL T mymax(const T a, const T b) {
  return a > b ? a : b;
}

template <class T>
IL T mymin(const T a, const T b) {
  return a < b ? a : b;
}

template <class T>
IL T myabs(const T &a) {
  return a > 0 ? a : -a;
}

const int INF = 0X3F3F3F3F;
const double EPS = 1E-10, PI = acos(-1.0);

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define OK DEBUG("Passing [%s] in LINE %d...\n", __FUNCTION__, __LINE__)
#define F first
#define S second
/*************************header*************************/

const int MAXN = 100000 + 5;

int a[MAXN], ans[MAXN];

IL void GG() {
  puts("No");
  exit(0);
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int sum = 0;
  For(i, 1, n) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  if (sum % k)
    GG();
  int target = sum / k, cur_sum = 0, cur = 0, cnt = 0;
  For(i, 1, n) {
    cur_sum += a[i];
    ++ cur;
    if (cur_sum == target)
      ans[++ cnt] = cur, cur = cur_sum = 0;
    else if (cur_sum > target)
      GG();
  }
  puts("Yes");
  For(i, 1, k)
    printf("%d ", ans[i]);
  puts("");
  return 0;
}