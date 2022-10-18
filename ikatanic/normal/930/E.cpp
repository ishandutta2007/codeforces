#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;
const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

int f[MAX][2], g[MAX][2];
int h[MAX][2][2];

vector<pair<int, int>> compress(vector<pair<int, int>>& A) {
  int N = A.size();
  vector<bool> dead(N, false);
  stack<pair<int, int>> S;

  sort(A.begin(), A.end(), [&] (const pair<int, int>& a, const pair<int, int>& b) {
      if (a.first != b.first) return a.first < b.first;
      return a.second > b.second;
    });

  REP(i, N) {
    while (!S.empty() && S.top().first >= A[i].second) {
      dead[S.top().second] = true;
      S.pop();
    }

    S.push({A[i].second, i});
  }

  vector<pair<int, int>> ret;
  REP(i, N) if (!dead[i]) ret.push_back(A[i]);
  return ret;
}

int main(void) {
  int K, N, M;
  scanf("%d %d %d", &K, &N, &M);
  vector<pair<int, int>> A(N), B(M);
  REP(i, N) scanf("%d %d", &A[i].first, &A[i].second);
  REP(i, M) scanf("%d %d", &B[i].first, &B[i].second);

  REP(i, N) --A[i].first, --A[i].second;
  REP(i, M) --B[i].first, --B[i].second;

  A = compress(A);
  B = compress(B);

  struct Segment {
    int a, b, type;
  };

  vector<Segment> v;
  for (auto& a: A) v.push_back({a.first, a.second, 0});
  for (auto& b: B) v.push_back({b.first, b.second, 1});

  sort(v.begin(), v.end(), [&](const Segment& a, const Segment& b) {
    return a.a < b.a;
    });

  int n = v.size();
  v.push_back({K, K, -1});
  f[0][0] = powmod(2, v[0].a);

  int next00 = 0, next01 = 0, next10 = 0, next11 = 0;
  int th[2][2];
  REP(i, 2) REP(j, 2) th[i][j] = 0;

  REP(i, n) {
    if (v[i].type == 0) {
      next00 = max(next00, i + 1);
      while (next00 < n && v[next00].type == 1) next00++;
      next01 = max(next01, i + 1);
      while (next01 < n && v[next01].a <= v[i].b) next01++;
    }

    if (v[i].type == 1) {
      next11 = max(next11, i + 1);
      while (next11 < n && v[next11].type == 0) next11++;
      next10 = max(next10, i + 1);
      while (next10 < n && v[next10].a <= v[i].b) next10++;
    }

    REP(c, 2) {
      f[i+1][c] = add(f[i+1][c], mul(f[i][c], powmod(2, v[i+1].a - v[i].a)));
      g[i][c^1] = add(g[i][c^1], f[i][c]);
    }


    REP(j, 2) REP(c, 2) th[j][c] = add(th[j][c], h[i][j][c]);

    REP(c, 2) {
      g[i][c] = add(g[i][c], th[v[i].type][c]);
    }

    REP(c, 2) {
      if (v[i].type == 0) {
        th[0][c^1] = add(th[0][c^1], g[i][c]);
        h[next01][0][c^1] = sub(h[next01][0][c^1], g[i][c]);

        f[next01][c] = add(f[next01][c], mul(g[i][c], powmod(2, v[next01].a - v[i].b - 1)));
      } else {
        th[1][c^1] = add(th[1][c^1], g[i][c]);
        h[next10][1][c^1] = sub(h[next10][1][c^1], g[i][c]);

        f[next10][c] = add(f[next10][c], mul(g[i][c], powmod(2, v[next10].a - v[i].b - 1)));
      }
    }
  }
  int ans = sub(f[n][0], f[n][1]);
  printf("%d\n", ans);
  return 0;
}