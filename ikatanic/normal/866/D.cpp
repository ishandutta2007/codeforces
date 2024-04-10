#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int N;
  scanf("%d", &N);

  multiset<int> S;
  llint score = 0;
  REP(i, N) {
    int x;
    scanf("%d", &x);
    
    if (S.size() && *S.begin() < x) {
      score += x - *S.begin();
      S.erase(S.begin());
      S.insert(x);
    }
    S.insert(x);
  }

  printf("%lld\n", score);
  return 0;
}