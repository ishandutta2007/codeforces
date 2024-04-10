#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

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
    int M;
    cin >> M;
    vector<int> A(M);
    cin >> A;
    sort(A.begin(), A.end());

    constexpr int Vmax = 70, Emax = Vmax * (Vmax - 1) / 2;
    vector dp(Vmax + 1, vector(M + 1, vector<int>(Emax + 1, 0)));
    vector prv(Vmax + 1, vector(M + 1, vector<pint>(Emax + 1, pint(-1, -1))));
    dp[0][0][0] = true;

    int N = -1, E = -1, mnans = -1;
    REP(i, Vmax)
    {
        REP(m, M + 1) REP(e, Emax + 1) if (dp[i][m][e] == true)
        {
            int in = i + 1;
            FOR(mn, m, m + 2) if (mn > 0 and mn <= M)
            {
                int enxt = e + A.at(mn - 1);
                if (enxt < in * (in - 1) / 2 or enxt > Emax) continue;
                dp[in][mn][enxt] = true, prv[in][mn][enxt] = pint(m, e);
                if (enxt == in * (in - 1) / 2 and mn == M)
                {
                    N = in;
                    mnans = mn;
                    E = enxt;
                    break;
                }
            }
            if (N >= 0) break;
        }
        if (N >= 0) break;
    }

    if (N < 0)
    {
        puts("=(");
        return 0;
    }

    vector<int> es;
    IREP(i, N)
    {
        es.emplace_back(A.at(mnans - 1));
        pint p = prv.at(i + 1).at(mnans).at(E);
        mnans = p.first, E = p.second;
    }

    MaxFlow<int> mf(N + 2);
    REP(i, N)
    {
        REP(j, i)
        {
            mf.add_edge(i, j, 1);
        }
        int wtmp = N - 1 - i;
        mf.add_edge(N, i, 1 + max(0, es[i] - wtmp));
        mf.add_edge(i, N + 1, 1 + max(0, wtmp - es[i]));
    }

    mf.Dinic(N, N + 1);
    vector ret(N, string(N, '0'));
    REP(i, N) for (auto e : mf.edges[i])
    {
        if (e.to < N and e.cap == 0) ret[i][e.to] = '1';
    }
    cout << ret.size() << '\n';
    for (auto s : ret) cout << s << '\n';
}