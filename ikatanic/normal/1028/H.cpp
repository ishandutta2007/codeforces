#include <algorithm>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 5100000;
const int K = 7;
const int R = 2 * K + 1;
const int MAXN = 200000;
const int MAXS = 1 << K;

int c[MAX];
int f[MAXN][R];
int g[K + 1][MAX];
int hb[MAXS];
int cnt[MAXS];

vector<int> RMQ(const vector<int>& array,
                const vector<pair<int, int>>& queries) {
  int n = array.size();
  vector<int> dad(n);
  function<int(int)> findset = [&](int x) {
    return x == dad[x] ? x : dad[x] = findset(dad[x]);
  };

  vector<vector<int>> qs(n);
  REP(i, (int)queries.size()) qs[queries[i].second].push_back(i);

  vector<int> ans(queries.size(), -1);
  vector<int> stack;
  REP(i, n) {
    dad[i] = i;
    while (stack.size() && array[stack.back()] > array[i]) {
      dad[stack.back()] = i;
      stack.pop_back();
    }
    stack.push_back(i);
    for (int qi : qs[i]) ans[qi] = array[findset(queries[qi].first)];
  }

  return ans;
}

int main(void) {
  ios_base::sync_with_stdio(false);

  FOR(i, 1, MAXS) {
    int j = 0;
    while (((i >> j) & 1) == 0) j++;
    hb[i] = j;
    cnt[i] = cnt[i ^ (1 << j)] + 1;
  }

  c[1] = 1;
  for (int i = 2; i * i < MAX; ++i) {
    if (!c[i]) {
      for (int j = i * i; j < MAX; j += i) {
        c[j] = i;
      }
    }
  }

  int N, Q;
  cin >> N >> Q;

  memset(g, -1, sizeof(g));

  REP(i, N) {
    int x;
    cin >> x;

    vector<int> v;
    while (x > 1) {
      int f = c[x] == 0 ? x : c[x];
      int cnt = 0;
      while (x % f == 0) {
        x /= f;
        cnt++;
      }

      if (cnt % 2) {
        v.push_back(f);
      }
    }

    int m = v.size();
    assert(m <= 7);

    REP(j, R) f[i][j] = -1;

    static int u[MAXS];

    u[0] = 1;
    REP(s, 1 << m) {
      if (s == 0) {
        u[s] = 1;
      } else {
        u[s] = u[s ^ (1 << hb[s])] * v[hb[s]];
      }

      int c = m - cnt[s];
      REP(k, K + 1) { f[i][k + c] = max(f[i][k + c], g[k][u[s]]); }
      g[c][u[s]] = i;
    }
  }

  vector<pair<int, int>> q(Q);
  vector<int> ans(Q, R);
  REP(i, Q) {
    cin >> q[i].first >> q[i].second;
    --q[i].first, --q[i].second;
  }

  REP(i, R) {
    vector<int> a(N);
    REP(j, N) a[j] = N - f[j][i];

    vector<int> ret(move(RMQ(a, q)));
    REP(j, Q) {
      if (N - ret[j] >= q[j].first) {
        ans[j] = min(ans[j], i);
      }
    }
  }

  REP(j, Q) { cout << ans[j] << "\n"; }
  return 0;
}