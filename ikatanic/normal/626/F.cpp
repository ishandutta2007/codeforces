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

const int MAX = 211;
const int off = 100010;
const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int a[MAX];
int f[MAX/2][2*off];
int nf[MAX/2][2*off];
int bio[MAX/2][2*off];
int cookie;
vector<int> v[MAX];
vector<int> nv[MAX];
int n, k;

void update(int i, int g, int s, int ff) {
  //  TRACE(i _ g _ s);
  if (s-off > k - g*a[i]) return;
  if (bio[g][s] != cookie) {
    bio[g][s] = cookie;
    nv[g].push_back(s);
    nf[g][s] = 0;
  }
  nf[g][s] = add(nf[g][s], ff);
  //  TRACE(g _ s _ nf[g][s]);
}

int main(void) {
  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%d", &a[i]);
  sort(a, a + n);

  f[0][off + 0] = 1;
  v[0] = {off + 0};
  int mg = n / 2;

  REP(i, n) {
    cookie++;
    REP(g, mg+1) {
      for (int s: v[g]) {
        update(i+1, g+1, s - a[i], f[g][s]);
        update(i+1, g, s, mul(g+1, f[g][s]));
        if (g > 0) update(i+1, g-1, s + a[i], mul(g, f[g][s]));
      }
    }
    REP(g, mg+1) {
      v[g] = nv[g];
      nv[g].clear();
      for (int s: v[g]) f[g][s] = nf[g][s];
    }
  }

  int ans = 0;
  for (int s: v[0]) ans = add(ans, f[0][s]);
  printf("%d\n", ans);
  return 0;
}