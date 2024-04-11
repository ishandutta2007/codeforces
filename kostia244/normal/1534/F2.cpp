//This can't possibly AC

// Problem: F2.   ( )
// Contest: Codeforces - Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1534/problem/F2
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>

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
struct dsu {
	vector<int> e;
	dsu(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

const int N = 4e5 + 69420;
int calc[N];
vector<int> g[N];
array<int, 2> dp[N];
array<int, 2> dfs(int v) {
	if(calc[v]) return dp[v];
	calc[v] = 1;
	dp[v] = {v, v};
	for(auto i : g[v]) {
		auto [l, r] = dfs(i);
		dp[v][0] = min(dp[v][0], l);
		dp[v][1] = max(dp[v][1], r);
	}
	return dp[v];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));
	vector<vector<int>> fall(n, vector<int>(m, -1));
	vector<vector<int>> id(n, vector<int>(m, -1));
	vector<int> targ(m);
	for(auto &i : a)
		for(auto &j : i)
			cin >> j;
	for(auto &i : targ) cin >> i;
	int sz = 0;
	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++) {
			if(a[i][j] == '#') id[i][j] = sz++, fall[i][j] = id[i][j];
			if(fall[i][j] == -1 && i) {
				fall[i][j] = fall[i-1][j];
			}
		}
	}
	atcoder::scc_graph sc(sz);
	vector<array<int, 2>> ed;
	auto add_edge = [&](int x, int y) {
		sc.add_edge(x, y);
		ed.push_back({x, y});
	};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(id[i][j] != -1 && i && fall[i-1][j]!=-1) {
				add_edge(fall[i-1][j], fall[i][j]);
			}
			if(i+1<n && id[i][j] != -1 && id[i+1][j] != -1) {
				add_edge(id[i+1][j], id[i][j]);
			}
			if(fall[i][j] != -1 && j && id[i][j-1] != -1)
				add_edge(fall[i][j], id[i][j-1]);
			
			if(fall[i][j] != -1 && j+1<m && id[i][j+1] != -1)
				add_edge(fall[i][j], id[i][j+1]);
		}
	}
	auto scc = sc.scc();
	dsu d(sz);
	vector<int> deg(sz);
	for(auto v : scc) {
		int lst = -1;
		for(auto i : v) {
			if(lst != -1) d.join(lst, i);
			lst = i;
		}
	}
	for(auto [f, t] : ed) {
		f = d.find(f), t = d.find(t);
		if(f != t) {
			deg[t]++;
			g[t].push_back(f);
		}
	}//g = reversed graph
	for(int i = 0; i < sz; i++) {
		if(!calc[i] && d.find(i) == i)
			dfs(i);
	}
			
	//find range
	vector<int> terms;
	for(int i = 0; i < sz; i++) {
		//cout << i << " " << d.find(i) << "  : " << deg[i] << endl;
		if(deg[i] == 0 && d.find(i) == i)
			terms.push_back(i);
	}
	vector<array<int, 2>> ranges;
	for(int j = 0; j < m; j++) if(targ[j]) {
		int i = n;
		do {
			i--;
			targ[j] -= id[i][j] != -1;
			//cout << i << " " << j << " " << targ[j] << endl;
		} while(targ[j]);
		ranges.push_back(dp[d.find(id[i][j])]);
	}
	sort(all(ranges), [](auto &a, auto &b) {
		if(a[1] != b[1]) return a[1] < b[1];
		return a < b;
	});
	int ans = 0, lst = -1;
	//for(auto i : terms) cout << i << ",";cout << endl;
	for(auto [l, r] : ranges) {
		//cout << l << " " << r << endl;
		if(lst < l) {
			lst = *(upper_bound(all(terms), r)-1);
			ans++;
		}
	}
	cout << ans << endl;
}