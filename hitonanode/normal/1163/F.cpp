#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
#define FI first
#define SE second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))

using wedges = vector<vector<plint>>; // (to, weight)
constexpr lint INF = 1e17;
pair<vector<lint>, vector<int>> dijkstra(int N, int s, const wedges &w)
{
    vector<lint> dist(N, INF);
    dist[s] = 0;
    vector<int> prev(N, -1);
    priority_queue<plint, vector<plint>, greater<plint>> pq;
    pq.emplace(0, s);
    while (!pq.empty())
    {
        plint p = pq.top();
        pq.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (auto nx : w[v])
        {
            lint dnx = p.first + nx.second;
            if (dist[nx.first] > dnx)
            {
                dist[nx.first] = dnx, prev[nx.first] = v;
                pq.emplace(dnx, nx.first);
            }
        }
    }
    return make_pair(dist, prev);
}

set<pint> shortest_pairs;
map<pint, int> spc;
vector<int> dij2(int N, int s, const wedges &w, unordered_map<int, int> pid, const vector<lint> &d_pre)
{
    vector<lint> dist(N, INF);
    vector<int> ret(N, pid.size());
    priority_queue<plint, vector<plint>, greater<plint>> pq;
    for (auto pa : pid)
    {
        dist[pa.first] = d_pre[pa.first];
        ret[pa.first] = pa.second;
        pq.emplace(d_pre[pa.first], pa.first);
    }

    while (!pq.empty())
    {
        plint p = pq.top();
        pq.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (auto nx : w[v])
        {
            lint dnx = p.first + nx.second;
            if (dist[nx.first] >= dnx)
            {
                if (dist[nx.first] > dnx)
                {
                    pq.emplace(dnx, nx.first);
                    mmin(dist[nx.first], dnx);
                    ret[nx.first] = ret[v];
                }
                pint enow(v, nx.first);
                if (!shortest_pairs.count(enow) or spc[enow] != 1) mmin(ret[nx.first], ret[v]);
            }
        }
    }
    return ret;
}

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    wedges e(N + 1);
    vector<pair<pint, lint>> edges(M);
    REP(i, M)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
        edges[i] = make_pair(pint(u, v), (lint)w);
    }

    vector<lint> D1 = dijkstra(N + 1, 1, e).first;
    auto pd = dijkstra(N + 1, N, e);
    vector<lint> DN = pd.first;

    vector<int> shortest_path{1};
    while (shortest_path.back() != N) shortest_path.push_back(pd.second[shortest_path.back()]);
    REP(i, shortest_path.size() - 1)
    {
        shortest_pairs.emplace(shortest_path[i], shortest_path[i + 1]);
        shortest_pairs.emplace(shortest_path[i + 1], shortest_path[i]);
    }
    unordered_map<int, int> pid1N, pidN1;
    for (auto v : shortest_path) pid1N[v] = pid1N.size() + 1;
    for (auto itr = shortest_path.rbegin(); itr != shortest_path.rend(); itr++) pidN1[*itr] = pidN1.size() + 1;

    int L = shortest_path.size();
    vector<vector<plint>> seq(L + 1);
    REP(i, M)
    {
        int u = edges[i].first.first, v = edges[i].first.second;
        lint w = edges[i].second;
        if (shortest_pairs.count(pint(u, v)) and w == abs(D1[u] - D1[v]))
        {
            spc[pint(u, v)]++;
            spc[pint(v, u)]++;
        }
    }

    vector<int> vl = dij2(N + 1, 1, e, pid1N, D1);
    vector<int> vr = dij2(N + 1, N, e, pidN1, DN);

    // dbg(vl);
    // dbg(vr);
    // dbg(shortest_pairs);
    REP(i, M)
    {
        int u = edges[i].first.first, v = edges[i].first.second;
        lint w = edges[i].second;
        if (shortest_pairs.count(pint(u, v)) and w == abs(D1[u] - D1[v])) continue;
        REP(_, 2)
        {
            lint wadd = D1[u] + DN[v] + w - D1[N];
            seq[vl[u]].emplace_back(L + 1 - vr[v], wadd);
            swap(u, v);
        }
    }
    // dbg(seq);
    vector<lint> penalty(L);
    priority_queue<plint, vector<plint>, greater<plint>> pq;
    pq.emplace(INF, INF);
    FOR(i, 1, L)
    {
        for (auto pa : seq[i]) pq.emplace(pa.second, pa.first);
        while (pq.top().second <= i) pq.pop();
        penalty[i] = pq.top().first;
    }
    // dbg(penalty);

    REP(_, Q)
    {
        int t;
        lint x;
        cin >> t >> x;
        int u = edges[t - 1].first.first, v = edges[t - 1].first.second;
        if (shortest_pairs.count(pint(u, v)) and edges[t - 1].second == abs(D1[u] - D1[v]) and spc[pint(u, v)] == 1)
        {
            // 
            lint w = abs(D1[u] - D1[v]);
            if (x < w) // 
            {
                printf("%lld\n", D1[N] - w + x);
            }
            else
            {
                lint ret_cand = D1[N] - w + x;
                printf("%lld\n", min(ret_cand, D1[N] + penalty[min(pid1N[u], pid1N[v])]));
            }
        }
        else
        {
            lint ret = min(D1[N], min(D1[u] + DN[v] + x, D1[v] + DN[u] + x));
            printf("%lld\n", ret);
        }
    }
}