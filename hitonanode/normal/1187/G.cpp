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
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_by_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

template <typename T>
class MinCostFlow
{
    struct edge
    {
        int to, rev;
        T cap, cost;
    };
    int V;
    std::vector<std::vector<edge> > G;
    std::vector<T> distance;
    std::vector<int> prevv, preve;

    std::vector<T> h;
    using P = std::pair<T, int>;

    T INF = std::numeric_limits<T>::max();

public:
    MinCostFlow(int N) : V(N),
                         G(std::vector<std::vector<edge> >(N)),
                         distance(std::vector<T>(N)),
                         prevv(std::vector<int>(N)),
                         preve(std::vector<int>(N)) {}
    
    void add_edge(int from, int to, T cap, T cost)
    {
        G[from].push_back((edge){to, (int)G[to].size(), cap, cost});
        G[to].push_back((edge){from, (int)G[from].size() - 1, (T)0, -cost});
    }

    // Bellman-Ford based, O(FVE)
    T mcfBellmanFord(int s, int t, T f)
    {
        T res = 0;
        while (f > 0)
        {
            distance = std::vector<T>(V, INF);
            distance[s] = (T)0;
            bool isUpdated = true;
            while (isUpdated)
            {
                isUpdated = false;
                for (int v = 0; v < V; v++)
                {
                    if (distance[v] == INF) continue;
                    for (unsigned i = 0; i < G[v].size(); i++)
                    {
                        edge &e = G[v][i];
                        if (e.cap > 0 && distance[e.to] > distance[v] + e.cost)
                        {
                            distance[e.to] = distance[v] + e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            isUpdated = true;
                        }
                    }
                }
            }

            if (distance[t] == INF)
            {
                return (T)(-1);
            }

            T d = f;
            for (int v = t; v != s; v = prevv[v])
            {
                d = std::min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * distance[t];
            for (int v = t; v != s; v = prevv[v])
            {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }

    // Potential-based method O(FElogV)
    T mcfDijkstra(int s, int t, T f)
    {
        T res = 0;
        h = std::vector<T>(V, (T)0);
        while (f > 0)
        {
            std::priority_queue<P, std::vector<P>, std::greater<P> > que;
            distance = std::vector<T>(V, INF);
            distance[s] = (T)0;
            que.push(P((T)0, s));
            while (!que.empty())
            {
                P p = que.top();
                que.pop();
                int v = p.second;
                if (distance[v] < p.first) continue;
                for (unsigned i = 0; i < G[v].size(); i++)
                {
                    edge &e = G[v][i];
                    if (e.cap > 0 && distance[e.to] > distance[v] + e.cost + h[v] - h[e.to])
                    {
                        distance[e.to] = distance[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(P(distance[e.to], e.to));
                    }
                }
            }
            if (distance[t] == INF)
            {
                return -1;
            }
            for (int v = 0; v < V; v++) h[v] += distance[v];

            T d = f;
            for (int v = t; v != s; v=prevv[v])
            {
                d = std::min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v])
            {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
};

int main()
{
    int N, M, K, C, D, T = 100;
    cin >> N >> M >> K >> C >> D;
    int GOAL = N * (T + 1) + 1;
    MinCostFlow<int> mcf(GOAL + 1);
    REP(t, T + 1)
    {
        mcf.add_edge(N * t + 1, GOAL, K, C * t);
    }
    REP(t, T)
    {
        FOR(i, 1, N + 1) mcf.add_edge(N * t + i, N * (t + 1) + i, K, 0);
    }
    REP(_, K)
    {
        int A;
        cin >> A;
        mcf.add_edge(0, A, 1, 0);
    }
    REP(_, M)
    {
        int a, b;
        cin >> a >> b;
        REP(t, T)
        {
            REP(i, K)
            {
                mcf.add_edge(N * t + a, N * (t + 1) + b, 1, D * (2 * i + 1));
                mcf.add_edge(N * t + b, N * (t + 1) + a, 1, D * (2 * i + 1));
            }
        }
    }
    cout << mcf.mcfDijkstra(0, GOAL, K) << endl;
}