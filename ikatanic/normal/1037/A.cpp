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
  N++;

  int ret = 0;
  while (N > 1) {
    ret++;
    N = (N + 1) / 2;
  }

  cout << ret << "\n";
  return 0;
}