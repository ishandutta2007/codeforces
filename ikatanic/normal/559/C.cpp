#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
#define x first
#define y second

const int MAXN = 2020;
const int MAX = 200010;
const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}


int f[MAXN][2];
int fact[MAX], invfact[MAX];
pair<int, int> a[MAXN];

int choose(int n, int k) {
  return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int main(void) {
  fact[0] = invfact[0] = 1;
  FOR(i, 1, MAX) {
    fact[i] = mul(fact[i-1], i);
    invfact[i] = powmod(fact[i], mod - 2);
  }

  int h, w, n;
  scanf("%d %d %d", &h, &w, &n);
  REP(i, n) {
    scanf("%d %d", &a[i].x, &a[i].y);
    --a[i].x, --a[i].y;
  }

  sort(a, a + n);
  REP(i, n) f[i][1] = choose(a[i].x + a[i].y, a[i].x);
  REP(i, n) FOR(j, i + 1, n)
    if (a[i].x <= a[j].x && a[i].y <= a[j].y)
      REP(c, 2) {
        int dx = a[j].x - a[i].x;
        int dy = a[j].y - a[i].y;
        f[j][c^1] = add(f[j][c^1], mul(f[i][c], choose(dx + dy, dx)));
      }
       
  int bad = 0;
  REP(i, n) REP(c, 2) {
    int dx = h-1 - a[i].x;
    int dy = w-1 - a[i].y;
    int ways = mul(f[i][c], choose(dx + dy, dx));
    if (c) bad = add(bad, ways); else
      bad = sub(bad, ways);
  }

  int all = choose(w + h - 2, w - 1);
  int ans = sub(all, bad);
  printf("%d\n", ans);
  return 0;
}