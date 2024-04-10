#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template <typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template <typename V, typename T> void ndfill(V &x, const T &val) { x = val; }
template <typename V, typename T> void ndfill(vector<V> &vec, const T &val) { for (auto &v : vec) ndfill(v, val); }
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

// MaxFlow (Dinic algorithm)
template <typename T>
struct MaxFlow
{
    struct edge { int to; T cap; int rev; };
    std::vector<std::vector<edge>> edges;
    std::vector<int> level;  // level[i] = distance between vertex S and i (Default: -1)
    std::vector<int> iter;  // iteration counter, used for Dinic's DFS
    std::vector<int> used;  // Used for Ford-Fulkerson's Algorithm

    void bfs(int s)
    {
        level.assign(edges.size(), -1);
        std::queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (edge &e : edges[v]) {
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    T dfs_dinic(int v, int goal, T f)
    {
        if (v == goal) return f;
        for (int &i = iter[v]; i < (int)edges[v].size(); i++) {
            edge &e = edges[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                T d = dfs_dinic(e.to, goal, std::min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    edges[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T dfs_ff(int v, int goal, T f)
    {
        if (v == goal) return f;
        used[v] = true;
        for (edge &e : edges[v]) {
            if (e.cap > 0 && !used[e.to]) {
                T d = dfs_ff(e.to, goal, std::min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    edges[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    MaxFlow(int N) { edges.resize(N); }
    void add_edge(int from, int to, T capacity)
    {
        edges[from].push_back(edge{to, capacity, (int)edges[to].size()});
        edges[to].push_back(edge{from, (T)0, (int)edges[from].size() - 1});
    }

    // Dinic algorithm
    // Complexity: O(VE)
    T Dinic(int s, int t)
    {
        constexpr T INF = std::numeric_limits<T>::max();
        T flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            iter.assign(edges.size(), 0);
            T f;
            while ((f = dfs_dinic(s, t, INF)) > 0) flow += f;
        }
    }

    // Ford-Fulkerson algorithm
    // Complexity: O(EF)
    T FF(int s, int t)
    {
        constexpr T INF = std::numeric_limits<T>::max();
        T flow = 0;
        while (true) {
            used.assign(edges.size(), 0);
            T f = dfs_ff(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }

    void back_flow(int s, int t, int s_e, int t_e, T capacity_reduce)
    {
        int i;
        for (i=0; edges[s_e][i].to != t_e; ) i++;
        edge &e = edges[s_e][i];

        if (capacity_reduce <= e.cap) {
            e.cap -= capacity_reduce;
        }
        else {
            T flow = capacity_reduce - e.cap;
            e.cap = 0;
            edges[e.to][e.rev].cap -= flow;

            T f_sum = 0;
            while (f_sum != flow) {
                used.assign(edges.size(), 0);
                f_sum += dfs_ff(t, t_e, flow - f_sum);
            }
            f_sum = 0;
            while (f_sum != flow) {
                used.assign(edges.size(), 0);
                f_sum += dfs_ff(s_e, s, flow - f_sum);
            }
        }
    }
};
int main()
{
    int N;
    vector<int> A(3), B(3);
    cin >> N >> A >> B;

    int ret1 = 0, ret2 = 0;
    REP(d, 3) ret2 += min(A[d], B[(d + 1) % 3]);

    MaxFlow<lint> mf(8);
    REP(d, 3) mf.add_edge(0, d + 1, A[d]);
    REP(d, 3) mf.add_edge(4 + d, 7, B[d]);
    REP(d, 3) mf.add_edge(d + 1, d + 4, 1e18);
    REP(d, 3) mf.add_edge((d + 1) % 3 + 1, d + 4, 1e18);
    ret1 = A[0] + A[1] + A[2] - mf.Dinic(0, 7);
    cout << ret1 << ' ' << ret2 << '\n';
}