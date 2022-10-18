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

char s[5050];

int main(void) {
  scanf("%s", s);
  int n = strlen(s);

  int good = 0;
  REP(i, 26) {
    vector<int> v;
    REP(j, n) if (s[j] == 'a'+i) v.push_back(j);

    if (v.size() == 0) continue;

    int best = 0;
    vector<int> f(26, 0);
    REP(d, n) {
      for (int p: v) {
        f[s[(p + d) % n] - 'a']++;
      }

      int cnt = 0;
      REP(j, 26) {
        if (f[j] == 1) cnt++;
        f[j] = 0;
      }

      best = max(best, cnt);
    }

    good += best;
  }

  printf("%.15lf\n", good * 1.0 / n);
  return 0;
}