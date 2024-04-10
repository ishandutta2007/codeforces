#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
template<typename Edge>
class GraphIterator {
public:
    class OutgoingEdges {
    public:
        OutgoingEdges(const GraphIterator *g, int l, int r): g(g), l(l), r(r) {
        }

        const Edge* begin() const {
            if (l == r) {
                return 0;
            }
            return &g->prepared_edges[l];
        }

        const Edge* end() const {
            if (l == r) {
                return 0;
            }
            return &g->prepared_edges[r];
        }

    private:
        int l, r;
        const GraphIterator *g;
    };

    void add_edge(int from, const Edge &e) {
        edges.push_back({from, e});
    }

    void prepare() {
        int n = 0;
        for (const auto &e : edges) {
            n = max(n, e.first);
        }
        n += 2;
        start.resize(n);
        for (const auto &e : edges) {
            ++start[e.first + 1];
        }
        for (int i = 1; i < n; ++i) {
            start[i] += start[i - 1];
        }
        prepared_edges.resize(edges.size() + 1);
        auto counter = start;
        for (const auto &e : edges) {
            prepared_edges[counter[e.first]++] = e.second;
        }
    }

    OutgoingEdges operator [] (int from) const {
        if (from < 0 || from + 1 >= start.size()) {
            return {this, 0, 0};
        }
        return {this, start[from], start[from + 1]};
    }

private:
    vector<Edge> prepared_edges;
    vector<pair<int, Edge>> edges;
    vector<int> start;
};

class two_sat {
public:
    two_sat(int n): answer(n, -1) {
    }

    void OR(int x, int y) {
        g.add_edge(x ^ 1, y);
        g.add_edge(y ^ 1, x);
    }
    pair<bool, vector<int>> solve() {
        g.prepare();
        for (int i = 0; i < answer.size(); ++i) {
            if (answer[i] == -1) {
                lastv.clear();
                if (!dfs(2 * i)) {
                    for (int v : lastv) {
                        answer[v] = -1;
                    }
                    if (!dfs(2 * i + 1)) {
                        return {false, {}};
                    }
                }
            }
        }
        return {true, answer};
    }

    bool dfs(int v) {
        lastv.push_back(v / 2);
        answer[v / 2] = v % 2;
        for (int to : g[v]) {
            if ((answer[to / 2] != -1 && answer[to / 2] != to % 2) || (answer[to / 2] == -1 && !dfs(to))) {
                return false;
            }
        }
        return true;
    }

    vector<int> answer, lastv;
    GraphIterator<int> g;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,p,M,m; cin >> n >> p >> M >> m;
    ++M;
    two_sat sat(p+(M+1));
    sat.OR((p+M)*2^1,(p+M)*2^1);
    for(int i=0;i<M;++i) {
        sat.OR((i+p)*2,(i+p+1)*2^1);
    }
    for(int i=0;i<n;++i) {
        int x,y; cin >> x >> y;
        --x,--y;
        sat.OR(x*2+1,y*2+1);
    }
    for(int i=0;i<p;++i) {
        int l,r; cin >> l >> r;
        sat.OR(i*2,(p+l)*2);
        sat.OR(i*2, (p+r+1)*2 ^1);
    }
    while(m--) {
        int u,v; cin >> u >> v;
        --u,--v;
        sat.OR(u*2,v*2);
    }
    auto [good,assignment] = sat.solve();
    if(good) {
        vi res;

        for(int i=0;i<p;++i) if(assignment[i]) {
            res.push_back(i+1);
        }
        int f=0;
        while(!assignment[f+p]) ++f;
        --f;
        cout << res.size() << ' ' << f << '\n' << res << '\n';
    } else cout << "-1\n";
}