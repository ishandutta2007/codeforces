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

  int N;
  cin >> N;

  vector<int> ls(N), rs(N);
  REP(i, N) { cin >> ls[i] >> rs[i]; }

  sort(ls.begin(), ls.end());
  sort(rs.begin(), rs.end());

  llint ret = N;
  REP(i, N) { ret += max(ls[i], rs[i]); }

  cout << ret << "\n";
  return 0;
}