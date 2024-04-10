#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
const int maxn = 200500;
const int mod = 1000000000;
typedef long long i64;
inline int add(int x, int y) { return (x + y) % mod; }
inline int mul(int x, int y) { return (i64)x*y%mod; }

int n, m;
int a[maxn];

void scan()
{
  scanf("%d%d", &n, &m);
  forn(i, n) scanf("%d", &a[i]);
}

void solve_small()
{
  forn(i, m) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int p, x;
      scanf("%d%d", &p, &x);
      a[p-1] = x;
    }
    else if (t == 2) {
      int l, r;
      scanf("%d%d", &l, &r);
      --l; --r;

      int s = 0, a0 = 1, a1 = 1;

      for (int j = l; j <= r; ++j) {
        s = add(s, mul(a[j], a0));
        a0 = add(a0, a1);
        swap(a0, a1);
      }
      
      printf("%d\n", s);
    }
  }
}

int main()
{
  //freopen("input.txt", "r", stdin);

  scan();
  solve_small();

  return 0;
}