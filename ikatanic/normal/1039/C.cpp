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

const int mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }

inline int sub(int a, int b) { return a >= b ? a - b : a - b + mod; }

inline int mul(int a, int b) { return llint(a) * b % mod; }

struct UnionFind {
  vector<int> p;

  UnionFind(int n) : p(vector<int>(n, 0)) { REP(i, n) p[i] = i; }

  int findset(int x) { return x == p[x] ? x : p[x] = findset(p[x]); }

  void merge(int x, int y) { p[findset(x)] = findset(y); }
};

int main(void) {
  ios_base::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;

  vector<llint> c(N);
  REP(i, N) cin >> c[i];

  vector<pair<llint, pair<int, int>>> edges;
  REP(i, M) {
    int u, v;
    cin >> u >> v;
    --u, --v;

    edges.push_back({c[u] ^ c[v], {u, v}});
  }

  sort(edges.begin(), edges.end());
  int rem_x = (1LL << K) % mod;

  int ans = 0;
  vector<int> bio(N, 0);
  vector<int> mapping(N);
  int cookie = 0;

  vector<int> pow2(N + 1);
  pow2[0] = 1;
  REP(i, N) pow2[i + 1] = mul(pow2[i], 2);

  int i = 0;
  while (i < M) {
    int j = i;
    while (edges[i].first == edges[j].first && j < M) j++;

    cookie++;
    int C = 0;

    FOR(k, i, j) {
      int u = edges[k].second.first;
      int v = edges[k].second.second;
      for (int x : {u, v}) {
        if (bio[x] != cookie) {
          mapping[x] = C++;
          bio[x] = cookie;
        }
      }
    }

    UnionFind uf(C);
    int n_comps = N;
    FOR(k, i, j) {
      int u = mapping[edges[k].second.first];
      int v = mapping[edges[k].second.second];
      if (uf.findset(u) != uf.findset(v)) {
        uf.merge(u, v);
        n_comps--;
      }
    }

    ans = add(ans, pow2[n_comps]);

    i = j;
    rem_x = sub(rem_x, 1);
  }

  ans = add(ans, mul(rem_x, pow2[N]));

  cout << ans << "\n";
  return 0;
}