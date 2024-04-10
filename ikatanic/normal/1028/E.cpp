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

const llint inf = 1e9;

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<llint> b(N);

  bool all_zero = true;
  REP(i, N) {
    cin >> b[i];
    all_zero &= (b[i] == 0);
  }

  if (all_zero) {
    cout << "YES\n";
    REP(i, N) cout << 1 << " ";
    cout << "\n";
    return 0;
  }

  int i = 0;
  while (i < N && b[i] >= b[(i + 1) % N]) i++;

  if (i == N) {
    cout << "NO\n";
    return 0;
  }

  int m = (i + 1) % N;
  assert(b[m] > 0);

  vector<llint> a(N);
  a[m] = b[m];
  a[i] = inf * b[m] + b[i];

  int j = (i - 1 + N) % N;
  while (j != m) {
    a[j] = a[(j + 1) % N] + b[j];
    j = (j - 1 + N) % N;
  }

  cout << "YES\n";
  REP(i, N) cout << a[i] << " ";
  cout << "\n";

  return 0;
}