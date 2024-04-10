#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


using wedges = vector<vector<int>>;

constexpr int INF = 1e9;
pair<vector<int>, vector<set<int>>> dijkstra(int N, int s, const wedges &w)
{
    vector<int> dist(N, INF);
    dist[s] = 0;
    vector<set<int>> prev(N);
    priority_queue<pint, vector<pint>, greater<pint>> pq;
    pq.emplace(0, s);
    while (!pq.empty())
    {
        pint p = pq.top();
        pq.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (auto nx : w[v])
        {
            int dnx = p.first + 1;
            if (dist[nx] > dnx)
            {
                dist[nx] = dnx;
                prev[nx].clear();
                prev[nx].insert(v);
                pq.emplace(dnx, nx);
            }
            else if (dist[nx] == dnx) {
                prev[nx].insert(v);
            }
        }
    }
    return make_pair(dist, prev); // (distance, previous_node)
}


int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> to(N + 1), rev(N + 1);
    REP(_, M)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        rev[v].push_back(u);
    }

    int K;
    cin >> K;
    vector<int> P(K);
    cin >> P;

    auto ret = dijkstra(N + 1, P.back(), rev);
    vector<set<int>> bkt = ret.second;

    // vector<set<int>> nxtcand(N + 1);
    // REP(i, N + 1) for (auto t : bkt[i]) nxtcand[t].insert(i);
    // dbg(nxtcand);
    int lo = 0, hi = 0;
    REP(k, K - 1) {
        int now = P[k], nxt = P[k + 1];
        if (!bkt[now].count(nxt)) lo++, hi++;
        else if (bkt[now].size() > 1) hi++;
    }
    cout << lo << " " << hi << endl;
}