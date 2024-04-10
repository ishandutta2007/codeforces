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
  int n;
  scanf("%d", &n);

  vector<int> A(n), B(n);
  REP(i, n) scanf("%d", &A[i]);
  REP(i, n) scanf("%d", &B[i]);


  vector<pair<int, int>> v;
  REP(i, n) v.push_back({B[i], i});

  sort(v.begin(), v.end());

  sort(A.begin(), A.end());
  vector<int> ans(n);
  REP(i, n) ans[v[i].second] = A[(int)A.size() - i - 1];

  REP(i, n) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}