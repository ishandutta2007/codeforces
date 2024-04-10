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
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

constexpr int DD = 63;


using wedges = vector<set<plint>>; // (to, weight)
wedges edges;

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
    return make_pair(dist, prev); // (distance, previous_node)
}

int N;

int main()
{
    cin >> N;
    vector<lint> A(N);
    REP(i, N) cin >> A[i];
    vector<int> bit_count(DD);
    for (auto a : A) REP(d, DD) if ((a >> d) & 1) bit_count[d]++;
    for (auto v : bit_count) if (v > 2)
    {
        puts("3");
        return 0;
    }
    vector<lint> e_use;
    for (auto v : A) if (__builtin_popcountll(v) > 1) e_use.push_back(v);
    N = e_use.size();
    edges.resize(N);
    REP(i, N) REP(j, N) if (i != j and (e_use[i] & e_use[j])) edges[i].emplace(j, 1);

    lint ret = INF;
    REP(i, N)
    {
        for (auto pa : edges[i])
        {
            wedges w = edges;
            int j = pa.first;
            w[i].erase(pa);
            w[j].erase(plint(i, 1));
            auto red = dijkstra(N, i, w);
            mmin(ret, red.first[j] + 1);
        }
    }
    cout << (ret < INF ? ret : -1) << endl;
}