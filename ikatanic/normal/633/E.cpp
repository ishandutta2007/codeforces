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

const int MAX = 1000100;
const int inf = 1e9;

int Lc[MAX], Lv[MAX];
int v[MAX], c[MAX];

void updc(int x, int v) {
  for (++x; x < MAX; x += x&-x)
    Lc[x] = min(Lc[x], v);
}

void updv(int x, int v) {
  for (++x; x < MAX; x += x&-x)
    Lv[x] = max(Lv[x], v);
}

int getc(int x) {
  int ans = inf;
  for (++x; x; x -= x&-x)
    ans = min(ans, Lc[x]);
  return ans;
}

int getv(int x) {
  int ans = -inf;
  for (++x; x; x -= x&-x)
    ans = max(ans, Lv[x]);
  return ans;
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%d", &v[i]);
  REP(i, n) scanf("%d", &c[i]);
  REP(i, n) v[i] *= 100;

  REP(i, n+2) Lc[i] = inf, Lv[i] = -inf;
  
  int j = n-1;
  vector<int> w;
  for (int i = n-1; i >= 0; --i) {
    updc(i, c[i]);
    updv(i, v[i]);

    while (j > i && getv(j) > getc(j)) --j;
    
    int score = min(getv(j), getc(j));
    if (j+1 < n) score = max(score, min(getv(j+1), getc(j+1)));
    w.push_back(score);
  }

  long double ans = 0;
  sort(w.begin(), w.end());

  double p = 1;
  for (int x: w) {
    if (k == 0) break;
    ans += p * x * 1.0l * k / n;
    p *= (n-k)*1.0l / n;
    n--;
  }

  printf("%.10lf\n", (double)ans);
  return 0;
}