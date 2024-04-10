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

  int n;
  cin >> n;

  string s;
  cin >> s;

  int cnt8 = 0;
  for (char c : s) {
    if (c == '8') cnt8++;
  }

  int ret = min(cnt8, n / 11);
  cout << ret << "\n";
  return 0;
}