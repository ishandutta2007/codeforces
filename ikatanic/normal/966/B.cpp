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
  int N, X1, X2;
  scanf("%d %d %d", &N, &X1, &X2);

  vector<pair<int, int>> v(N);
  REP(i, N) {
    scanf("%d", &v[i].first);
    v[i].second = i;
  }

  sort(v.begin(), v.end());

  REP(swapped, 2) {
    int f = N-1;
    while (f >= 0 && v[f].first * 1LL * (N - f) < X1) --f;

    if (f >= 0) {
      int g = f - 1;
      while (g >= 0 && v[g].first * 1LL * (f - g) < X2) --g;

      if (g >= 0) {
        puts("Yes");

        vector<int> v1, v2;
        FOR(i, f, N) v1.push_back(v[i].second);
        FOR(i, g, f) v2.push_back(v[i].second);

        if (swapped) swap(v1, v2);

        printf("%d %d\n", (int)v1.size(), (int)v2.size());
        for (int x: v1) printf("%d ", x+1); printf("\n");
        for (int x: v2) printf("%d ", x+1); printf("\n");
        return 0;
      }
    }

    swap(X1, X2);
  }

  puts("No");
  return 0;
}