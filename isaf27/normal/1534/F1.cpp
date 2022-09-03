/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-10;
const ll INF = (ll)(4e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(4e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 2010;

vector<bool> bad;

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

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
        struct scc_graph {
        public:
            explicit scc_graph(int n) : _n(n) {}

            int num_vertices() { return _n; }

            void add_edge(int from, int to) {
                edges.push_back({from, {to}});
            }

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
                bad.resize(group_num, false);
                for (const auto& edge : edges) {
                    if (ids[edge.first] != ids[edge.second.to]) {
                        bad[ids[edge.second.to]] = true;
                    }
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

string s[M];
int n, m, a[M];

int idx(int i, int j) {
    return i * m + j;
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    vector<vector<int>> down(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++) {
        int last = n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i][j] == '#') {
                last = i;
            }
            down[i][j] = last;
        }
    }
#ifdef ONPC
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cerr << down[i][j] << " ";
        }
        cerr << "\n";
    }
#endif
    atcoder::internal::scc_graph graph(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                if (i > 0 && s[i - 1][j] == '#') {
                    graph.add_edge(idx(i, j), idx(i - 1, j));
                }
                if (j > 0 && down[i][j - 1] != n) {
                    graph.add_edge(idx(i, j), idx(down[i][j - 1], j - 1));
                }
                if (j + 1 < m && down[i][j + 1] != n) {
                    graph.add_edge(idx(i, j), idx(down[i][j + 1], j + 1));
                }
                if (i + 1 < n && down[i + 1][j] != n) {
                    graph.add_edge(idx(i, j), idx(down[i + 1][j], j));
                }
            }
        }
    }
    auto res = graph.scc_ids();
    /*for (const auto& t : res.second) {
        cerr << t << " ";
    }
    cerr << "\n";*/
    set<int> qr;
    for (int j = 0; j < m; j++) {
        int i = down[0][j];
        if (i == n) {
            continue;
        }
        int id = idx(i, j);
        if (bad[res.second[id]]) {
            continue;
        }
        //cerr << i + 1 << " " << j + 1 << "\n";
        qr.insert(res.second[id]);
    }
    cout << qr.size() << "\n";
    return 0;
}