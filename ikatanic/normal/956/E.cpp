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

const int MAX = 10010;
const int inf = 1e9;

int f[MAX];

int main(void) {
  int N, L, R;
  scanf("%d %d %d", &N, &L, &R);

  vector<int> h(N);
  REP(i, N) scanf("%d", &h[i]);

  vector<int> a, b;
  REP(i, N) {
    int k;
    scanf("%d", &k);
    if (k == 1) {
      b.push_back(h[i]);
    } else {
      a.push_back(h[i]);
    }
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int total_sum = 0;
  REP(i, MAX) f[i] = inf;

  f[0] = 0;
  for (int x: a) {
    for (int j = total_sum; j >= 0; --j) {
      f[j + x] = 0;
    }
    total_sum += x;
  }


  int ret = 0;
  int sum = accumulate(b.begin(), b.end(), 0);
  int total = (int)b.size();

  for (int cnt = total; cnt >= 0; --cnt) {
    if (sum <= R - L) {
      for (int p = L; p <= R - sum; ++p) {
        if (f[p] < inf) {
          ret = max(ret, cnt + (f[p] < total - cnt ? 1 : 0));
        }
      }
    }

    if (cnt > 0) {
      int x = b[cnt - 1];
      for (int j = total_sum; j >= 0; --j) {
        f[j + x] = min(f[j + x], f[j] + 1);
      }
      total_sum += x;

      sum -= x;
    }
  }

  printf("%d\n", ret);
  return 0;
}