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

  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];

  vector<pair<int, int>> p(n);
  REP(i, n) p[i] = {a[i], i};

  sort(p.begin(), p.end(), greater<pair<int, int>>());

  vector<bool> win(n);
  for (auto& r : p) {
    int i = r.second;
    int x = r.first;

    win[i] = false;
    for (int j = i % x; j < n; j += x) {
      if (a[j] > a[i] && !win[j]) {
        win[i] = true;
        break;
      }
    }
  }

  REP(i, n) {
    if (win[i]) {
      cout << "A";
    } else {
      cout << "B";
    }
  }
  cout << "\n";
  return 0;
}