#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int B = 60;

bool can(vector<llint>& A, int K, llint R) {
  int N = A.size();
  vector<vector<bool>> f(N+1, vector<bool>(K+1, false));
  f[0][0] = true;
  REP(i, N) REP(j, K) {
    if (f[i][j]) {
      llint sum = 0;
      FOR(k, i, N) {
        sum += A[k];
        if ((sum & R) == R) {
          f[k+1][j+1] = true;
        }
      }
    }
  }
  return f[N][K];
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<llint> a(n);
  REP(i, n) scanf("%lld", &a[i]);

  llint ret = 0;
  for (int i = B-1; i >= 0; --i) {
    if (can(a, k, ret + (1LL<<i))) {
      ret += 1LL<<i;
    }
  }

  printf("%lld\n", ret);
  return 0;
}