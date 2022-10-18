#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int inf = 2e9;
const int mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }

inline int sub(int a, int b) { return a >= b ? a - b : a - b + mod; }

inline int mul(int a, int b) { return llint(a) * b % mod; }

int main(void) {
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  vector<int> a(N);
  REP(i, N) cin >> a[i];

  vector<int> pl(N), pr(N);

  stack<pair<int, int>> S;
  S.push({inf, -1});
  REP(i, N) {
    while (a[i] >= S.top().first) S.pop();
    pl[i] = S.top().second;
    S.push({a[i], i});
  }

  while (!S.empty()) S.pop();
  S.push({inf, N});
  for (int i = N - 1; i >= 0; --i) {
    while (a[i] > S.top().first) S.pop();
    pr[i] = S.top().second;
    S.push({a[i], i});
  }

  vector<int> g(N + 1);
  for (int j = K; j <= N; j += K - 1) {
    g[j] = add(g[j], 1);
  }
  for (int i = 1; i <= N; ++i) {
    g[i] = add(g[i], g[i - 1]);
  }

  vector<int> h(N + 2);
  h[0] = 0;
  REP(i, N + 1) h[i + 1] = add(h[i], g[i]);

  int ans = 0;
  REP(i, N) {
    int x = i - pl[i] - 1;
    int m = pr[i] - pl[i] - 1;

    int cnt = 0;
    cnt = add(cnt, h[m + 1]);
    cnt = sub(cnt, h[m - x]);
    cnt = sub(cnt, h[x + 1]);

    ans = add(ans, mul(cnt, a[i]));
  }

  cout << ans << "\n";
  return 0;
}