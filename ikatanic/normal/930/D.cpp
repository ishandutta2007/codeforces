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

const int off = 100010;
const int MAX = 500200;
const int inf = 1e9;


llint solve(vector<pair<int, int>>& A) {
  vector<int> minL(MAX, inf);
  vector<int> minR(MAX, inf);
  vector<int> maxL(MAX, -inf);
  vector<int> maxR(MAX, -inf);

  for (auto& p: A) {
    int X = p.first + p.second;
    int Y = p.first - p.second;
    minL[X] = min(minL[X], Y);
    minR[X] = min(minR[X], Y);
    maxL[X] = max(maxL[X], Y);
    maxR[X] = max(maxR[X], Y);
  }

  for (int i = 1; i < MAX; ++i) {
    minL[i] = min(minL[i], minL[i - 1]);
    maxL[i] = max(maxL[i], maxL[i - 1]);
  }

  for (int i = MAX - 2; i >= 0; --i) {
    minR[i] = min(minR[i], minR[i + 1]);
    maxR[i] = max(maxR[i], maxR[i + 1]);
  }

  llint ans = 0;
  for (int x = 0; x < MAX; x += 2) {
    int lo = max(minL[x], minR[x]);
    int hi = min(maxL[x], maxR[x]);
    if (lo <= hi) ans += (hi - lo) / 2;
  }
  return ans;
}

int main(void) {
  int N;
  scanf("%d", &N);

  vector<pair<int, int>> A, B;
  REP(i, N) {
    int x, y;
    scanf("%d %d", &x, &y);
    x += off, y += off;
    if ((x + y) % 2) {
      A.push_back({x, y});
    } else {
      B.push_back({x, y+1});
    }
  }

  llint ans = solve(A) + solve(B);
  printf("%lld\n", ans);
  return 0;
}