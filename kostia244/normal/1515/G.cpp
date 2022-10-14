// Problem: G. Phoenix and Odometers
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

#include <algorithm>

#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
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

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    scc_graph(int n) : _n(n) {}

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

#include <cassert>
#include <vector>

namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}

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

#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int maxn = 2e5 + 55;
#define int long long
int n, m;
vector<array<int, 2>> Gr[maxn];
int vis[maxn];
int solve(int s, int g, vector<int32_t> &comp) {
	for(auto i : comp) vis[i] = -1;
	queue<int> q;
	int res = g;
	auto add = [&](int x, int y) {
		if(vis[x] == -2) return;
		if(g) y %= g;
		if(vis[x] != -1 && vis[x] != y) {
			res = __gcd(res, abs(vis[x]-y));
		}
		if(vis[x] != -1) return;
		vis[x] = y;
		q.push(x);
	};
	add(s, 0);
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(auto [to, l] : Gr[v]) {
			add(to, vis[v]+l);
		}
	}
	for(auto i : comp) vis[i] = -2;
	return res;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> m;
	atcoder::scc_graph s(n);
	for(int f, t, l, i = 0; i < m; i++) {
		cin >> f >> t >> l;f--,t--;
		Gr[f].push_back({t, l});
		s.add_edge(f, t);
	}
	auto scc = s.scc();
	vector<int> G(n);
	for(int i = 0; i < n; i++) vis[i] = -2;
	for(auto comp : scc) {
		int s = comp[0];
		int g = solve(s, 0, comp), t;
		while((t=solve(s, g, comp))!=g) {
			g = t;
		}
		for(auto i : comp) G[i] = g;
	}
	//for(auto i : G) cout << i << " "; cout << endl;
	{
	int q, x, s, m;
	cin >> q;
	while(q--) {
		cin >> x >> s >> m;x--;
		m = __gcd(m, G[x]);
		s%=m;
		report(s==0);
	}}
}