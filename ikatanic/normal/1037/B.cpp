#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  ios_base::sync_with_stdio(false);

  int N, S;
  cin >> N >> S;

  vector<int> a(N);
  REP(i, N) cin >> a[i];

  sort(a.begin(), a.end());

  llint ret = 0;
  REP(i, N / 2) {
    if (a[i] > S) ret += a[i] - S;
  }

  ret += abs(a[N / 2] - S);
  FOR(i, N / 2 + 1, N) {
    if (a[i] < S) ret += S - a[i];
  }

  cout << ret << "\n";
  return 0;
}