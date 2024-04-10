#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

// Directed graph library to find strongly connected components 
// 0-indexed directed graph
// Complexity: O(V + E)
struct DirectedGraphSCC {
    int V; // # of Vertices
    std::vector<std::vector<int>> to, from;
    std::vector<int> used;  // Only true/false
    std::vector<int> vs;
    std::vector<int> cmp;
    int scc_num = -1;

    DirectedGraphSCC(int V = 0) : V(V), to(V), from(V), cmp(V) {}

    void _dfs(int v) {
        used[v] = true;
        for (auto t : to[v]) if (!used[t]) _dfs(t);
        vs.push_back(v);
    }
    void _rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for (auto t : from[v]) if (!used[t]) _rdfs(t, k);
    }

    void add_edge(int from_, int to_) {
        assert(from_ >= 0 and from_ < V and to_ >= 0 and to_ < V);
        to[from_].push_back(to_);
        from[to_].push_back(from_);
    }

    // Detect strongly connected components and return # of them.
    // Also, assign each vertex `v` the scc id `cmp[v]` (0-indexed)
    int FindStronglyConnectedComponents() {
        used.assign(V, false);
        vs.clear();
        for (int v = 0; v < V; v++) if (!used[v]) _dfs(v);
        used.assign(V, false);
        scc_num = 0;
        for (int i = (int)vs.size() - 1; i >= 0; i--) if (!used[vs[i]]) _rdfs(vs[i], scc_num++);
        return scc_num;
    }

    // Find and output the vertices that form a closed cycle.
    // output: {v_1, ..., v_C}, where C is the length of cycle,
    //         {} if there's NO cycle (graph is DAG)
    std::vector<int> DetectCycle()
    {
        int ns = FindStronglyConnectedComponents();
        if (ns == V) return {};
        std::vector<int> cnt(ns);
        for (auto x : cmp) cnt[x]++;
        const int c = std::find_if(cnt.begin(), cnt.end(), [](int x) { return x > 1; }) - cnt.begin();
        const int init = std::find(cmp.begin(), cmp.end(), c) - cmp.begin();
        used.assign(V, false);
        std::vector<int> ret;
        auto dfs = [&](auto &&dfs, int now, bool b0) -> bool {
            if (now == init and b0) return true;
            for (auto nxt : to[now]) if (cmp[nxt] == c and !used[nxt])
            {
                ret.emplace_back(nxt), used[nxt] = 1;
                if (dfs(dfs, nxt, true)) return true;
                ret.pop_back();
            }
            return false;
        };
        dfs(dfs, init, false);
        return ret;
    }

    // After calling `FindStronglyConnectedComponents()`, generate a new graph by uniting all vertices
    // belonging to the same component(The resultant graph is DAG).
    DirectedGraphSCC GenerateTopologicalGraph() {
        DirectedGraphSCC newgraph(scc_num);
        for (int s = 0; s < V; s++) for (auto t : to[s]) {
            if (cmp[s] != cmp[t]) newgraph.add_edge(cmp[s], cmp[t]);
        }
        return newgraph;
    }
};

// 2-SAT solver: Find a solution for  `(Ai v Aj) ^ (Ak v Al) ^ ... = true`
// - `nb_sat_vars`: Number of variables
// - Considering a graph with `2 * nb_sat_vars` vertices
// - Vertices [0, nb_sat_vars) means `Ai`
// - vertices [nb_sat_vars, 2 * nb_sat_vars) means `not Ai`
struct SATSolver : DirectedGraphSCC {
    int nb_sat_vars;
    std::vector<int> solution;
    SATSolver(int nb_variables = 0) : DirectedGraphSCC(nb_variables * 2), nb_sat_vars(nb_variables), solution(nb_sat_vars) {}
    void add_x_or_y_constraint(bool is_x_true, int x, bool is_y_true, int y) {
        assert(x >= 0 and x < nb_sat_vars);
        assert(y >= 0 and y < nb_sat_vars);
        if (!is_x_true) x += nb_sat_vars;
        if (!is_y_true) y += nb_sat_vars;
        add_edge((x + nb_sat_vars) % (nb_sat_vars * 2), y);
        add_edge((y + nb_sat_vars) % (nb_sat_vars * 2), x);
    }
    // Solve the 2-SAT problem. If no solution exists, return `false`.
    // Otherwise, dump one solution to `solution` and return `true`.
    bool run() {
        FindStronglyConnectedComponents();
        for (int i = 0; i < nb_sat_vars; i++) {
            if (cmp[i] == cmp[i + nb_sat_vars]) return false;
            solution[i] = cmp[i] > cmp[i + nb_sat_vars];
        }
        return true;
    }
};

void SAME()
{
    puts("SIMILAR");
    exit(0);
}

void dump(SATSolver &solver, int N) {
    solver.run();
    REP(i, N) cout << solver.solution[i] << ' ';
    cout << '\n';
    exit(0);
}

int main()
{
    int N;
    vector<int> M(2);
    cin >> N >> M;
    vector<SATSolver> sats(2, N);
    vector<int> sat_ret(2);
    REP(d, 2)
    {
        REP(_, M[d]) {
            int i, j;
            cin >> i >> j;
            int bi = (i > 0), bj = (j > 0);
            i = abs(i) - 1, j = abs(j) - 1;
            sats[d].add_x_or_y_constraint(bi, i, bj, j);
        }
        sat_ret[d] = sats[d].run();
    }

    if (!sat_ret[0] and !sat_ret[1]) SAME();
    if (sat_ret[0] != sat_ret[1]) {
        if (!sat_ret[0]) swap(sats[0], sats[1]);
        REP(i, N) cout << sats[0].solution[i] << ' ';
        cout << '\n';
        return 0;
    }

    vector<vector<vector<int>>> reach(2, vector<vector<int>>(N * 2));
    vector<vector<int>> cmp_fix(2);

    vector<DirectedGraphSCC> graphs;
    using BS = bitset<1024>;
    vector<vector<BS>> reach_cmp(2);

    REP(d, 2) graphs.emplace_back(sats[d].GenerateTopologicalGraph());
    REP(d, 2)
    {
        cmp_fix[d].resize(sats[d].scc_num, -1);
        int V = sats[d].scc_num;
        reach_cmp[d].resize(V);
        IREP(i, sats[d].scc_num) {
            reach_cmp[d][i][i] = 1;
            for (auto j : graphs[d].to[i]) {
                reach_cmp[d][i] |= reach_cmp[d][j];
            }
        }
        REP(i, N * 2) {
            vector<int> visited(N * 2);
            REP(j, N * 2) if (reach_cmp[d][sats[d].cmp[i]][sats[d].cmp[j]]) visited[j] = 1;
            reach[d][i] = visited;
            if (i < N and visited[i + N]) {
                cmp_fix[d][sats[d].cmp[i]] = 0;
                cmp_fix[d][sats[d].cmp[i + N]] = 1;
            }
            if (i >= N and visited[i - N]) {
                cmp_fix[d][sats[d].cmp[i]] = 0;
                cmp_fix[d][sats[d].cmp[i - N]] = 1;
            }
        }

        REP(i, N * 2) REP(j, N * 2) if (reach[d][i][j]) {
            if (cmp_fix[d][sats[d].cmp[i]] == 1) cmp_fix[d][sats[d].cmp[j]] = 1;
            if (cmp_fix[d][sats[d].cmp[j]] == 0) cmp_fix[d][sats[d].cmp[i]] = 0;
        }
    }

    REP(i, N) {
        int c0 = cmp_fix[0][sats[0].cmp[i]], c1 = cmp_fix[1][sats[1].cmp[i]];
        if (c0 != c1) {
            if (c0 >= 0 and c1 >= 0) {
                dump(sats[0], N);
            } else {
                int de = (c0 < 0 ? 0 : 1);
                int b = 1 - max(c0, c1);
                sats[de].add_x_or_y_constraint(b, i, b, i);
                dump(sats[de], N);
            }
        }
    }

    REP(i, N * 2) {
        REP(j, N * 2) {
            if (cmp_fix[0][sats[0].cmp[i]] > -1 and cmp_fix[0][sats[0].cmp[j]] > -1) continue;
            if (reach[0][i][j] != reach[1][i][j]) {
                int de = reach[0][i][j];
                if (cmp_fix[de][sats[0].cmp[i]] == 0) continue;
                if (cmp_fix[de][sats[0].cmp[j]] == 1) continue;
                sats[de].add_x_or_y_constraint(i < N, i % N, i < N, i % N);
                sats[de].add_x_or_y_constraint(j >= N, j % N, j >= N, j % N);
                dump(sats[de], N);
            }
        }
    }
    SAME();
}