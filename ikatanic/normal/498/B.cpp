#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 5050;
const double eps = 1e-12;

double f[MAXN], nf[MAXN];
double g[MAXN], ng[MAXN];
double p[MAXN];
double pw[MAXN], pwsum[MAXN];
int t[MAXN];

int main(void) {
  int n, T;
  scanf("%d %d", &n, &T);
  REP(i, n) {
    int pr;
    scanf("%d %d", &pr, t+i);
    p[i] = pr / 100.0;
  }

  f[0] = 1;
  double ans = 0;
  REP(i, n+1) {
    pw[0] = pwsum[0] = 1;
    FOR(j, 1, MAXN) {
      pw[j] = pw[j-1] * (1 - p[i]);
      pwsum[j] = pwsum[j-1] + pw[j];
      if (pw[j] < eps) pw[j] = 0;
      if (pwsum[j] < eps) pwsum[j] = 0;
    }
    
    REP(j, T+1) nf[j] = 0, ng[j] = 0;

    REP(j, T+1) {
      if (g[j] < eps) g[j] = 0;
      f[j] += g[j];
      if (f[j] < eps) f[j] = 0;

      if (i > 0) g[j+1] += g[j] * (1 - p[i-1]);
      
      ng[j+1] += p[i] * f[j];

      if (j + t[i] <= T) {
        double rem = 1.0;
        if (t[i] > 1) rem -= p[i] * pwsum[t[i]-2];
        ng[j + t[i]] -= p[i] * pw[t[i]-1] * f[j];
        nf[j + t[i]] += rem * f[j];
      } else 
        if (j < T) {
          double rem = 1.0;
          rem -= p[i] * pwsum[T-j-1];
          f[T] += f[j] * rem;
        }

    }
    
    if (i == n) REP(j, T+1) ans += f[j] * n; else
      ans += f[T] * i;
    REP(j, T+1) f[j] = nf[j], g[j] = ng[j];
  }
  
  printf("%.9lf\n", ans);
  return 0;
}