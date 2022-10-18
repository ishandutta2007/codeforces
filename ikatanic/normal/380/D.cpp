#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100100;
const int mod = 1e9 + 7;

int a[MAXN];
int f[MAXN], inv[MAXN];
int n;

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

int add(int a, int b) {
  if (a+b >= mod) return a+b-mod;
  return a+b;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  int tmp = powmod(a, b/2);
  return mul(tmp, tmp);
}

int choose(int n, int k) {
  if (n < k) return 0;
  return mul(f[n], mul(inv[k], inv[n-k]));
}

int solve(int l, int r, int fl, int fr) {
  if (l >= r) return 1;
  
  while (fl <= r && (fl < l || !a[fl])) fl++;
  while (fr >= l && (fr > r || !a[fr])) fr--;

  if (fl > r) return powmod(2, r-l);
  
  int next = r-l+1;
  int lx = a[fl], rx = a[fr];
  int freeLeft = fl-l, freeRight = r-fr;
  
  if (lx == rx && lx == 1) return choose(freeLeft+freeRight, freeLeft);
  
  int ans = 0;
  if (lx >= rx) {
    int dist = next-lx;
    if (dist < 0 || dist < freeLeft || dist-freeLeft > freeRight); else
      ans = add(ans, mul(choose(dist, freeLeft), solve(l+freeLeft+1, r-(dist-freeLeft), fl+1, fr)));
  }
  if (rx >= lx) {
    int dist = next-rx;
    if (dist < 0 || dist < freeRight || dist-freeRight > freeLeft); else
      ans = add(ans, mul(choose(dist, freeRight), solve(l+(dist-freeRight), r-freeRight-1, fl, fr-1)));
  }
  return ans;
}
  
int main(void)
{
  f[0] = inv[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    f[i] = mul(f[i-1], i);
    inv[i] = powmod(f[i], mod-2);
  }

  scanf("%d", &n);

  REP(i, n)
    scanf("%d", a+i);

  printf("%d\n", solve(0, n-1, -1, n));
  return 0;
}