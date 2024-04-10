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

const int MAXN = 55;
const int MAXT = 5050;

double f[MAXN][MAXT];
int F[MAXN], S[MAXN];
double P[MAXN];

int main(void) {
  int N, R;
  scanf("%d %d", &N, &R);
  REP(i, N) {
    scanf("%d %d %lf", &F[i], &S[i], &P[i]);
    P[i] /= 100.0;
  }

  double lo = 0, hi = 1e20;
  REP(it, 150) {
    double mid = (lo + hi) / 2;
    
    for (int i = N-1; i >= 0; --i) {
      REP(j, R+1) {
        double cost = 0;
        if (j >= F[i]) {
          cost += P[i] * (F[i] + min(mid, f[i + 1][j - F[i]]));
        } else {
          cost += P[i] * (F[i] + mid);
        }
        if (j >= S[i]) {
          cost += (1 - P[i]) * (S[i] + min(mid, f[i + 1][j - S[i]]));
        } else {
          cost += (1 - P[i]) * (S[i] + mid);
        }

        f[i][j] = cost;
      }
    }

    if (f[0][R] > mid) lo = mid;
    else hi = mid;
  }

  printf("%.15lf\n", lo);
  return 0;
}