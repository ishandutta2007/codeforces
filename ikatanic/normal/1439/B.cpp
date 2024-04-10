#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

vector<int> solve(vector<unordered_set<int>>& E, int M, int K) {
  int N = E.size();
  if (K * 1LL * (K - 1) / 2 > M) return {};

  set<int> S;
  queue<int> Q;
  for (int i = 0; i < N; ++i) {
    S.insert(i);
    if (E[i].size() < K) Q.push(i);
  }

  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();

    if (E[x].size() == K - 1) {
      bool ok = true;
      for (int a : E[x]) {
        for (int b : E[x]) {
          if (a < b && !E[a].count(b)) {
            ok = false;
            break;
          }
        }
        if (!ok) break;
      }
      if (ok) {
        vector<int> ret;
        ret.push_back(2);
        ret.push_back(x);
        for (int a : E[x]) ret.push_back(a);
        return ret;
      }
    }

    S.erase(x);
    for (int y : E[x]) {
      E[y].erase(x);
      if (E[y].size() == K - 1) Q.push(y);
    }
  }

  if (S.size() > 0) {
    assert(S.size() >= K + 1);
    vector<int> ret;
    ret.push_back(1);
    for (int x : S) ret.push_back(x);
    return ret;
  }
  return {};
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int N, M, K;
    cin >> N >> M >> K;

    vector<unordered_set<int>> E(N);
    for (int i = 0; i < M; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      E[u].insert(v);
      E[v].insert(u);
    }

    auto ret = solve(E, M, K);

    if (ret.empty()) {
      cout << "-1\n";
    } else {
      cout << ret[0];
      if (ret[0] == 1) {
        cout << ' ' << ret.size() - 1;
      } else {
        assert(ret.size() == K + 1);
      }
      cout << '\n';
      for (int i = 1; i < (int)ret.size(); ++i) {
        cout << ret[i] + 1 << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}