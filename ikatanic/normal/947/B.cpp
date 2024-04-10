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

int main(void) {
  int N;
  scanf("%d", &N);

  vector<llint> V(N);
  vector<llint> T(N);
  REP(i, N) scanf("%lld", &V[i]);
  REP(i, N) scanf("%lld", &T[i]);

  vector<llint> pT(N + 1, 0);
  REP(i, N) pT[i + 1] = pT[i] + T[i];

  vector<llint> A(N + 1, 0), B(N, 0);
  REP(i, N) {
    int lo = i, hi = N;
    while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      if (pT[mid] - pT[i] > V[i]) {
        hi = mid - 1;
      } else {
        lo = mid;
      }
    }

    A[i]++, A[lo]--;
    if (lo < N) {
      B[lo] += V[i] - (pT[lo] - pT[i]);
    }
  }

  llint sA = 0;
  REP(i, N) {
    sA += A[i];
    llint tot = sA * T[i] + B[i];
    printf("%lld ", tot);
  }
  printf("\n");
  return 0;
}