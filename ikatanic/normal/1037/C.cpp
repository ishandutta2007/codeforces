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
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  string A, B;
  cin >> A;
  cin >> B;

  int ret = 0;
  REP(i, N) {
    if (A[i] != B[i]) {
      if (i + 1 < N && A[i] != A[i + 1] && A[i + 1] != B[i + 1]) {
        swap(A[i], A[i + 1]);
        ret++;
      } else {
        ret++;
      }
    }
  }

  cout << ret << "\n";
  return 0;
}