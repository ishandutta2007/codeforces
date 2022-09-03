#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
    fast_ios() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); };
} fast_ios_;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
//
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args>
void ndarray(vector<T>& vec, const V& val, int len, Args... args)
{
    vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); });
}
template <typename T>
bool chmax(T& m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T>
bool chmin(T& m, const T q) { return m > q ? (m = q, true) : false; }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T>
vector<T> srtunq(vector<T> vec) { return sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()), vec; }
template <typename T>
istream& operator>>(istream& is, vector<T>& vec)
{
    return for_each(begin(vec), end(vec), [&](T& v) { is >> v; }), is;
}

// output
template <typename T, typename V>
ostream& dmpseq(ostream&, const T&, const string&, const string&, const string&);
#if __cplusplus >= 201703L
template <typename... T>
ostream& operator<<(ostream& os, const tuple<T...>& tpl)
{
    return apply([&os](auto&&... args) { ((os << args << ','), ...); }, tpl), os;
}
#endif
//
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '(' << p.first << ',' << p.second << ')'; }
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& x) { return dmpseq<vector<T>, T>(os, x, "[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& x) { return dmpseq<deque<T>, T>(os, x, "deq[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const set<T>& x) { return dmpseq<set<T>, T>(os, x, "{", ",", "}"); }
template <typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_set<T, TH>& x) { return dmpseq<unordered_set<T, TH>, T>(os, x, "{", ",", "}"); }
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& x) { return dmpseq<multiset<T>, T>(os, x, "{", ",", "}"); }
template <typename TK, typename T>
ostream& operator<<(ostream& os, const map<TK, T>& x) { return dmpseq<map<TK, T>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename TK, typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_map<TK, T, TH>& x) { return dmpseq<unordered_map<TK, T, TH>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename T, typename V>
ostream& dmpseq(ostream& os, const T& seq, const string& pre, const string& sp, const string& suf)
{
    return os << pre, for_each(begin(seq), end(seq), [&](V x) { os << x << sp; }), os << suf;
}
template <typename T>
void print(const vector<T>& x) { dmpseq<vector<T>, T>(cout, x, "", " ", "\n"); }
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

int main()
{
    string VC;
    cin >> VC;
    int L = VC.length();
    int N, M;
    cin >> N >> M;
    vector<int> P1(M), B1(M), P2(M), B2(M);
    REP(i, M)
    {
        char c1, c2;
        cin >> P1[i] >> c1 >> P2[i] >> c2;
        P1[i]--, P2[i]--;
        B1[i] = (c1 != 'V');
        B2[i] = (c2 == 'V');
    }

    SATSolver solver_(N);
    REP(i, M) solver_.add_x_or_y_constraint(B1[i], P1[i], B2[i], P2[i]);
    if (VC == string(VC.length(), VC[0]))
    {
        bool b = (VC[0] == 'V');
        REP(i, N) solver_.add_x_or_y_constraint(b, i, b, i);
    }

    string ret = "";
    string S;
    cin >> S;

    auto check = [&](string cand) -> bool {
        int K = cand.length();
        string ssub = S.substr(0, K);
        if (ssub > cand) return false;

        SATSolver solver = solver_;
        REP(j, K)
        {
            bool b = (VC[cand[j] - 'a'] == 'V');
            solver.add_x_or_y_constraint(b, j, b, j);
        }
        if (ssub == cand and K < N)
        {
            //  i 
            bool aru_v = false, aru_c = false;
            for (int d = S[K] - 'a' + 1; d < L; d++) {
                if (VC[d] == 'V') aru_v = true;
                else aru_c = true;
            }
            if (!aru_v and !aru_c) return false;
            else if (!aru_c) solver.add_x_or_y_constraint(true, K, true, K);
            else if (!aru_v) solver.add_x_or_y_constraint(false, K, false, K);
        }
        return solver.run();
    };

    int fv = L, fc = L;
    REP(i, L) if (VC[i] == 'V') chmin(fv, i); else chmin(fc, i);
    vector<int> free_cands;
    if (fv < L) free_cands.emplace_back(fv);
    if (fc < L) free_cands.emplace_back(fc);
    sort(ALL(free_cands));

    IREP(i, N) if (ret.empty())
    {
        string tmp = S.substr(0, i);
        while (tmp.length() < N)
        {
            bool flg = false;
            string Scmp = S.substr(0, tmp.length());
            if (Scmp > tmp) break;
            else if (Scmp == tmp)
            {
                bool bv = false, bc = false;
                for (int j = S[i] - 'a' + 1; j < L; j++) {
                    bool st = (VC[j] == 'V' ? bv : bc);
                    if (st) continue;
                    (VC[j] == 'V' ? bv : bc) = true;
                    char c = 'a' + j;
                    string tt = tmp + c;
                    if (check(tt)) {
                        tmp = tt;
                        flg = true;
                        break;
                    }
                }
            }
            else
            {
                for (auto i : free_cands)
                {
                    char c = 'a' + i;
                    string tt = tmp + c;
                    if (check(tt)) {
                        tmp = tt;
                        flg = true;
                        break;
                    }
                }
            }
            if (!flg) break;
        }
        if (tmp.length() == N and check(tmp))
        {
            if (ret.empty() or ret > tmp) ret = tmp;
        }
    }
    if (check(S)) ret = S;

    if (ret.empty()) puts("-1");
    else cout << ret << '\n';
}