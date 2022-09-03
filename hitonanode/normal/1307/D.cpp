#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


using wedges = vector<set<pint>>; // (to, weight)
constexpr int INF = 1e9;
pair<vector<int>, vector<int>> dijkstra(int N, int s, const wedges &w)
{
    vector<int> dist(N, INF);
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

wedges to;
vector<pint> e;

// Nonrecursive Segment Tree (point-update, range-get)
// - Conditions for operations:
//   - datamerge: [TDATA, TDATA] -> TDATA, e(x, y) == e(y, x)
//   - data2ret: [TDATA, TQUERY] -> TRET
//   - retmerge: [TRET, TRET] -> TRET, g(defaultRET, x) == x, g(x, y) = g(y, x)
//   - commutability f(e(x, y), q) == g(f(x, q), f(y, q))
template<typename TDATA, typename TRET, typename TQUERY>
struct NonrecursiveSegmentTree
{
    int N;
    TRET defaultRET;
    virtual TDATA datamerge(const TDATA &, const TDATA &) = 0;
    virtual TRET data2ret(const TDATA &, const TQUERY &) = 0;
    virtual TRET retmerge(const TRET &, const TRET &) = 0;
    std::vector<TDATA> data;
    inline TDATA& at(int i) { return data[i]; }

    inline void _merge(int i) { at(i) = datamerge(at(i << 1), at((i << 1) + 1)); }
    void initialize(const std::vector<TDATA> &seq, TRET RET_ZERO) {
        N = seq.size();
        defaultRET = RET_ZERO;
        data = seq;
        data.insert(data.end(), seq.begin(), seq.end());
        for (int i = N - 1; i; i--) _merge(i);
    }
    NonrecursiveSegmentTree() = default;
    void update(int pos, const TDATA &x) {
        assert(pos >= 0 and pos < N);
        at(pos + N) = x;
        for (int i = pos + N; i > 1;) i >>= 1, _merge(i);
    }

    // [l, r), 0-indexed
    TRET get(int l, int r, TQUERY query = NULL) {
        assert(l >= 0 and r <= N);
        TRET retl = defaultRET, retr = defaultRET;
        l += N, r += N;
        while (l < r) {
            if (l & 1) retl = retmerge(retl, data2ret(data[l++], query));
            if (r & 1) retr = retmerge(data2ret(data[--r], query), retr);
            l >>= 1, r >>= 1;
        }
        return retmerge(retl, retr);
    }

    template<typename T1, typename T2, typename T3>
    friend std::ostream &operator<<(std::ostream &os, NonrecursiveSegmentTree<T1, T2, T3> s) {
        os << "[SegmentTree (len: " << s.N << ')';
        for (int i = 0; i < s.N; i++) os << s.at(i + s.N) << ',';
        os << "]";
        return os;
    }
};

// Range Counting less than q Query
// - get: return (#{i | l <= i < r, x_i < q}, total sum of them).
using TDATA = vector<pint>;
using TRET = int;
using TQUERY = pint;
struct SegmentTree : public NonrecursiveSegmentTree<TDATA, TRET, TQUERY>
{
    TDATA datamerge(const TDATA &vl, const TDATA &vr) override {
        TDATA ret = vl;
        ret.insert(ret.end(), vr.begin(), vr.end());
        std::sort(ret.begin(), ret.end());
        if (ret.size())
        {
            IREP(i, int(ret.size()) - 1) mmax(ret[i].second, ret[i + 1].second);
            std::sort(ret.begin(), ret.end());
            ret.erase(unique(ret.begin(), ret.end()), ret.end());
            vector<pint> rt;
            for (auto x : ret) {
                if (rt.empty()) rt.push_back(x);
                else {
                    if (rt.back().second - rt.back().first > x.second - x.first) rt.push_back(x);
                }
            }
            return rt;
        }
        return ret;
    }
    TRET data2ret(const TDATA &vec, const TQUERY &q) override {
        int i = lower_bound(vec.begin(), vec.end(), pint(q.second, q.first), [](pint l, pint r) { return l.first - l.second < r.first - r.second; }) - vec.begin();
        int ret = 0;
        FOR(d, -2, 3) if (i + d >= 0 and i + d < vec.size()) {
            mmax(ret, min({q.first + vec[i + d].second + 1, q.second + vec[i + d].first + 1}));
        }
        return ret;
    }
    TRET retmerge(const TRET &l, const TRET &r) override {
        return max(l, r);
    }
    using SegTree = NonrecursiveSegmentTree<TDATA, TRET, TQUERY>;
    SegmentTree(const std::vector<pint> &seq) : SegTree::NonrecursiveSegmentTree(){
        std::vector<TDATA> init;
        for (auto p : seq) init.push_back({p});
        SegTree::initialize(init, 0);
    }
};


int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    to.resize(N);
    vector<int> sp(K);
    cin >> sp;
    for (auto &x : sp) x--;

    while (M--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e.emplace_back(a, b);
        to[a].emplace(b, 1);
        to[b].emplace(a, 1);
    }

    vector<int> d1 = dijkstra(N, 0, to).first;
    vector<int> d2 = dijkstra(N, N - 1, to).first;

    vector<pint> vp;
    for (auto s : sp) vp.emplace_back(d1[s], d2[s]);
    sort(vp.begin(), vp.end());

    SegmentTree st(vp);
    int ret = 0;
    REP(i, vp.size()) {
        mmax(ret, st.get(0, i, vp[i]));
        mmax(ret, st.get(i + 1, vp.size(), vp[i]));
    }
    cout << min(ret, d1.back()) << endl;
}