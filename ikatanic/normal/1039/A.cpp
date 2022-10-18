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

void no() {
  cout << "No\n";
  exit(0);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  int N;
  llint T;
  cin >> N >> T;

  vector<llint> a(N);
  REP(i, N) cin >> a[i];

  vector<int> x(N);
  REP(i, N) {
    cin >> x[i];
    --x[i];
  }

  vector<int> pref_true(N + 1, 0);
  vector<bool> set_false(N + 1, false);
  REP(i, N) {
    if (x[i] < i) {
      no();
    }

    pref_true[i + 1]++;
    pref_true[x[i] + 1]--;
    set_false[x[i] + 1] = true;
  }

  vector<llint> b(N);
  REP(i, N) {
    b[i] = i + 1 < N ? a[i + 1] + T - 1 : llint(3e18);

    if (pref_true[i] > 0) {
      if (set_false[i]) {
        no();
      }
      assert(i > 0);
      b[i - 1]++;
    }

    pref_true[i + 1] += pref_true[i];
  }

  REP(i, N - 1) {
    if (b[i] >= b[i + 1]) {
      no();
    }
  }

  cout << "Yes\n";
  REP(i, N) cout << b[i] << " ";
  cout << "\n";
  return 0;
}