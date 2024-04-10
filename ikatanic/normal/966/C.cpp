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

const int B = 61;

int main(void) {
  int N;
  scanf("%d", &N);

  vector<llint> b(N);
  vector<vector<llint>> f(B);

  llint last = 0;
  REP(i, N) {
    scanf("%lld", &b[i]);
    last ^= b[i];

    int j = B-1;
    while (((b[i] >> j)&1) == 0) --j;
    f[j].push_back(b[i]);
  }

  REP(j, B) sort(f[j].begin(), f[j].end(), greater<llint>());
  vector<llint> a = {last};
  REP(i, N) {
    llint prev = a.back();
    llint next = -1;
    REP(j, B) {
      if (prev & (1LL<<j)) {
        if (f[j].size()) {
          llint g = f[j].back();
          f[j].pop_back();
          next = prev ^ g;
          break;
        }
      }
    }

    if (next == -1) {
      puts("No");
      return 0;
    }
    assert(next < prev);
    a.push_back(next);
  }

  reverse(a.begin(), a.end());
  if (a[0] != 0) {
    puts("No");
  }


  llint prev = 0;
  puts("Yes");
  FOR(i, 1, N+1) {
    printf("%lld ", (prev ^ a[i]));
    prev = a[i];
  }

  printf("\n");
  return 0;
}