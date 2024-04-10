#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////

int N, M;
vector<string> S;

template<typename T>
class Maxflow
{
    struct edge { int to; T cap; int rev; };
    std::vector<std::vector<edge> > edges;
    std::vector<int> level;
    std::vector<int> iter;
    std::vector<int> used;

    void bfs(int s)
    {
        level = std::vector<int>(edges.size(), -1);
        std::queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (edge &e : edges[v])
            {
                if (e.cap > 0 && level[e.to] < 0)
                {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    T dfs_d(int v, int goal, T f)
    {
        if (v == goal) return f;
        for (int &i = iter[v]; i < (int)edges[v].size(); i++)
        {
            edge &e = edges[v][i];
            if (e.cap > 0 && level[v] < level[e.to])
            {
                T d = dfs_d(e.to, goal, std::min(f, e.cap));
                if (d > 0)
                {
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
        for (int i = 0; i < (int)edges[v].size(); i++)
        {
            edge &e = edges[v][i];
            if (e.cap > 0 && !used[e.to])
            {
                T d = dfs_ff(e.to, goal, std::min(f, e.cap));
                if (d > 0)
                {
                    e.cap -= d;
                    edges[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    Maxflow(int N) { edges.resize(N); }
    void add_edge(int from, int to, T capacity)
    {
        edges[from].push_back(edge{to, capacity, (int)edges[to].size()});
        edges[to].push_back(edge{from, (T)0, (int)edges[from].size() - 1});
    }

    T Dinic(int s, int t)
    {
        constexpr T INF = std::numeric_limits<T>::max();
        T flow = 0;
        while (true)
        {
            bfs(s);
            if (level[t] < 0) return flow;
            iter = std::vector<int>(edges.size(), 0);
            T f;
            while ((f = dfs_d(s, t, INF)) > 0) flow += f;
        }
    }

    T FF(int s, int t)
    {
        constexpr T INF = std::numeric_limits<T>::max();
        T flow = 0;
        while (true)
        {
            used = std::vector<int>(edges.size(), 0);
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

        if (capacity_reduce <= e.cap)
        {
            e.cap -= capacity_reduce;
        }
        else
        {
            T flow = capacity_reduce - e.cap;
            e.cap = 0;
            edges[e.to][e.rev].cap -= flow;

            T f_sum = 0;
            while (f_sum != flow)
            {
                used = std::vector<int>(edges.size(), 0);
                f_sum += dfs_ff(t, t_e, flow - f_sum);
            }
            f_sum = 0;
            while (f_sum != flow)
            {
                used = std::vector<int>(edges.size(), 0);
                f_sum += dfs_ff(s_e, s, flow - f_sum);
            }
        }
    }
};

int main()
{
    cin >> N >> M;
    S.resize(N);
    REP(i, N) cin >> S[i];

    Maxflow<int> mf(N * M * 2);
    REP(i, N) REP(j, M)
    {
        if (i < N - 1) mf.add_edge(i * M + j, (i + 1) * M + j + N * M, 2);
        if (j < M - 1) mf.add_edge(i * M + j, i * M + (j + 1) + N * M, 2);
        if (S[i][j] == '.')
        {
            int cap = 1;
            if ((i == 0 and j == 0) or (i == N - 1 and j == M - 1)) cap = 2;
            mf.add_edge(i * M + j + N * M, i * M + j, cap);
        }
    }
    cout << mf.Dinic(0, N * M - 1) << endl;
}