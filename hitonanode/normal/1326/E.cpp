#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


// CUT begin
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


// Range Minimum Query
// - get: return min(x_l, ..., x_{r - 1})
using T = pint;
struct SegTree : public NonrecursiveSegmentTree<T, T, bool>
{
    T datamerge(const T &vl, const T &vr) override {
        pint ret;
        if (vl.second < vr.first)
        {
            ret.first = vr.first + vl.first - vl.second;
            ret.second = vr.second;
        }
        else {
            ret.first = vl.first;
            ret.second = vl.second - vr.first + vr.second;
        }
        return ret;
    };
    T data2ret(const T &v, const bool &q) override { return v; }
    T retmerge(const T &vl, const T &vr) override { return datamerge(vl, vr); };
    SegTree(const std::vector<T> &seq) : SegTree::NonrecursiveSegmentTree()
    {
        SegTree::initialize(seq, pint(0, 0));
    };
};

int main()
{
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    cin >> P >> Q;
    vector<int> p2pos(N + 1);
    REP(i, N) p2pos[P[i]] = i;

    vector<int> ret(N + 1, N);

    vector<pint> status(N, pint(0, 0));
    SegTree st(status);

    int h = 0;
    IFOR(p, 1, N + 1) {
        int pos = p2pos[p];
        status[pos].second++;
        if (status[pos].first and status[pos].second) status[pos] = make_pair(0, 0);
        st.update(pos, status[pos]);
        while (st.get(0, N).second) {
            int qp = Q[h] - 1;
            status[qp].first++;
            if (status[qp].first and status[qp].second) status[qp] = make_pair(0, 0);
            st.update(qp, status[qp]);
            h++;
        }
        ret[h] = p - 1;
    }
    REP(i, N) chmin(ret[i + 1], ret[i]);
    REP(i, N) printf("%d ", ret[i]);
    puts("");
}