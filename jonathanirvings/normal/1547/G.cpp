#ifndef ATCODER_INTERNAL_CSR_HPP
#define ATCODER_INTERNAL_CSR_HPP 1

#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  // namespace internal

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_CSR_HPP

#ifndef ATCODER_INTERNAL_SCC_HPP
#define ATCODER_INTERNAL_SCC_HPP 1

#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_SCC_HPP

#ifndef ATCODER_SCC_HPP
#define ATCODER_SCC_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    explicit scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder

#endif  // ATCODER_SCC_HPP

#include <bits/stdc++.h>
using namespace std;

constexpr int kNoPath = 0;
constexpr int kOnePath = 1;
constexpr int kMultiplePaths = 2;
constexpr int kInfinitePaths = -1;

int combine(int a, int b) {
  if (a == kInfinitePaths || b == kInfinitePaths) {
    return kInfinitePaths;
  }
  if (a == kMultiplePaths || b == kMultiplePaths) {
    return kMultiplePaths;
  }
  if (a == kOnePath && b == kOnePath) {
    return kMultiplePaths;
  }
  if (a == kOnePath || b == kOnePath) {
    return kOnePath;
  }
  return kNoPath;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int>> adj(N);
    vector<bool> self_loop(N, false);
    atcoder::scc_graph scc(N);
    while (M--) {
      int A, B;
      scanf("%d %d", &A, &B);
      --A;
      --B;
      if (A == B) {
        self_loop[A] = true;
      }
      adj[A].push_back(B);
      scc.add_edge(A, B);
    }
    vector<vector<int>> groups = scc.scc();
    vector<int> belongs_to(N);
    M = groups.size();
    for (int i = 0; i < M; ++i) {
      for (int u : groups[i]) {
        belongs_to[u] = i;
      }
    }
    vector<vector<int>> adj_scc(M);
    for (int u = 0; u < N; ++u) {
      for (int v : adj[u]) {
        if (belongs_to[u] != belongs_to[v]) {
          adj_scc[belongs_to[u]].push_back(belongs_to[v]);
        }
      }
    }
    vector<int> in_degree(M, 0);
    for (int i = 0; i < M; ++i) {
      sort(adj_scc[i].begin(), adj_scc[i].end());
      adj_scc[i].erase(unique(adj_scc[i].begin(), adj_scc[i].end()),
                       adj_scc[i].end());
      for (int j : adj_scc[i]) {
        ++in_degree[j];
      }
    }
    queue<int> q;
    for (int i = 0; i < M; ++i) {
      if (in_degree[i] == 0) {
        q.push(i);
      }
    }
    vector<int> dp(M, kNoPath);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == belongs_to[0]) {
        dp[u] = kOnePath;
      }
      if (dp[u] != kNoPath) {
        if (groups[u].size() > 1 || self_loop[groups[u][0]]) {
          dp[u] = kInfinitePaths;
        }
      }
      for (int v : adj_scc[u]) {
        dp[v] = combine(dp[v], dp[u]);
        --in_degree[v];
        if (in_degree[v] == 0) {
          q.push(v);
        }
      }
    }
    for (int i = 0; i < N; ++i) {
      printf("%d%c", dp[belongs_to[i]], " \n"[i == N - 1]);
    }
  }
}