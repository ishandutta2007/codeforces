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
template <typename T>
bool chmax(T& m, const T q) { return m < q ? (m = q, true) : false; }
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

// Nonrecursive Segment Tree (point-update, range-get)
// - Conditions for operations:
//   - merge_data: [TDATA, TDATA] -> TDATA, e(x, y) == e(y, x)
//   - data2ret: [TDATA, TQUERY] -> TRET
//   - merge_ret: [TRET, TRET] -> TRET, g(defaultRET, x) == x, g(x, y) = g(y, x)
//   - commutability f(e(x, y), q) == g(f(x, q), f(y, q))
template <typename TDATA, typename TRET, typename TQUERY>
struct NonrecursiveSegmentTree {
    int N;
    TRET defaultRET;
    virtual TDATA merge_data(const TDATA&, const TDATA&) = 0;
    virtual TRET data2ret(const TDATA&, const TQUERY&) = 0;
    virtual TRET merge_ret(const TRET&, const TRET&) = 0;
    std::vector<TDATA> data;
    inline TDATA& at(int i) { return data[i]; }

    inline void _merge(int i) { at(i) = merge_data(at(i << 1), at((i << 1) + 1)); }
    void initialize(const std::vector<TDATA>& seq, TRET RET_ZERO)
    {
        N = seq.size();
        defaultRET = RET_ZERO;
        data = seq;
        data.insert(data.end(), seq.begin(), seq.end());
        for (int i = N - 1; i; i--)
            _merge(i);
    }
    NonrecursiveSegmentTree() = default;
    void update(int pos, const TDATA& x)
    {
        assert(pos >= 0 and pos < N);
        at(pos + N) = x;
        for (int i = pos + N; i > 1;)
            i >>= 1, _merge(i);
    }

    // [l, r), 0-indexed
    TRET get(int l, int r, TQUERY query = NULL)
    {
        assert(l >= 0 and r <= N);
        TRET retl = defaultRET, retr = defaultRET;
        l += N, r += N;
        while (l < r) {
            if (l & 1)
                retl = merge_ret(retl, data2ret(data[l++], query));
            if (r & 1)
                retr = merge_ret(data2ret(data[--r], query), retr);
            l >>= 1, r >>= 1;
        }
        return merge_ret(retl, retr);
    }

    // Calculate smallest r that satisfies condition(g(f(x_l, q), ..., f(x_{r - 1}, q)) == true
    // Assumption: Monotonicity of g(x_l, ..., x_r) about r (l: fixed)
    // Complexity: O(log N)
    int binary_search(int l, auto condition, TQUERY query = NULL)
    {
        std::stack<int> rs;
        l += N;
        int r = N * 2;
        TRET retl = defaultRET;
        if (condition(retl))
            return l - N;
        while (l < r) {
            if (l & 1) {
                TRET ret_tmp = merge_ret(retl, data2ret(data[l], query));
                if (condition(ret_tmp)) {
                    while (l * 2 < N * 2) {
                        ret_tmp = merge_ret(retl, data2ret(data[l * 2], query));
                        if (condition(ret_tmp))
                            l *= 2;
                        else
                            retl = ret_tmp, l = l * 2 + 1;
                    }
                    return l - N;
                }
                l++;
                retl = ret_tmp;
            }
            if (r & 1)
                rs.push(--r);
            l >>= 1, r >>= 1;
        }
        while (!rs.empty()) {
            l = rs.top();
            rs.pop();
            TRET ret_tmp = merge_ret(retl, data2ret(data[l], query));
            if (condition(ret_tmp)) {
                while (l * 2 < N * 2) {
                    ret_tmp = merge_ret(retl, data2ret(data[l * 2], query));
                    if (condition(ret_tmp))
                        l *= 2;
                    else
                        retl = ret_tmp, l = l * 2 + 1;
                }
                return l - N;
            }
            retl = ret_tmp;
        }
        return N;
    }

    template <typename T1, typename T2, typename T3>
    friend std::ostream& operator<<(std::ostream& os, NonrecursiveSegmentTree<T1, T2, T3> s)
    {
        os << "[SegmentTree (len: " << s.N << ')';
        for (int i = 0; i < s.N; i++)
            os << s.at(i + s.N) << ',';
        os << "]";
        return os;
    }
};

// Range Maximum Query
// - get: return max(x_l, ..., x_{r - 1})
template <typename T>
struct RangeMaximumQuery : public NonrecursiveSegmentTree<T, T, bool> {
    using SegTree = NonrecursiveSegmentTree<T, T, bool>;
    T merge_data(const T& vl, const T& vr) override { return std::max(vl, vr); };
    T data2ret(const T& v, const bool& q) override { return v; }
    T merge_ret(const T& vl, const T& vr) override { return std::max(vl, vr); };
    RangeMaximumQuery(const std::vector<T>& seq, T defaultmax)
        : SegTree::NonrecursiveSegmentTree()
    {
        SegTree::initialize(seq, defaultmax);
    };
};

constexpr int B = 1000;

int MAX = 100010 + B * 2;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> r2l(MAX, -1);
    REP(_, M)
    {
        int l, r;
        cin >> l >> r;
        if (l == r) continue;
        r2l[r] = l;
    }
    int Q;
    cin >> Q;

    vector<vector<pint>> b2lr(MAX / B);
    vector<pint> queries;
    vector<pair<pint, int>> rets;

    vector<int> dp;
    REP(q, Q)
    {
        int x, y;
        cin >> x >> y;
        queries.emplace_back(x, y);
        if (y - x > B) {
            b2lr[y / B].emplace_back(x, y);
        } else {
            dp.resize(y - x + 1);
            iota(ALL(dp), x);
            IFOR(i, x, y + 1)
            if (r2l[i] >= x) {
                chmax(dp[r2l[i] - x], i);
            }
            int arr = x;
            FOR(i, x, y + 1)
            if (i <= arr) {
                chmax(arr, dp[i - x]);
            }
            rets.emplace_back(pint(x, y), arr);
        }
    }
    REP(t, b2lr.size())
    {
        std::sort(ALL(b2lr[t]));
        const vector<pint>& qlrs = b2lr[t];
        if (qlrs.empty())
            continue;
        const int T = t * B;

        vector<int> hinit(T + B + 10, 0);
        iota(ALL(hinit), 0);
        RangeMaximumQuery<int> rmq(hinit, -1);

        int hnow = T;

        vector<pint> lastl2rs;
        FOR(i, T - 1, T + B + 5) if (r2l[i] != -1) lastl2rs.emplace_back(r2l[i], i);
        sort(ALL(lastl2rs));
        priority_queue<pint> pqlr;
        for (auto [x, y] : qlrs) {
            
            while (hnow >= x) {
                if (r2l[hnow] != -1) {
                    pqlr.emplace(r2l[hnow], hnow);
                }
                while (pqlr.size() and pqlr.top().first == hnow) {
                    auto [l, r] = pqlr.top();
                    pqlr.pop();
                    if (chmax(hinit[l], rmq.get(l, r + 1))) rmq.update(l, hinit[l]);
                }
                hnow--;
            }

            int ret = rmq.get(x, x + 1);
            for (auto [l, r] : lastl2rs)
                if (x <= l and r <= y and ret >= l)
                    chmax(ret, r);
            rets.emplace_back(pint(x, y), ret);
        }
    }

    sort(ALL(rets));
    for (auto p : queries) {
        int ret = lower_bound(ALL(rets), make_pair(p, -1000000))->second;
        cout << ret << '\n';
    }
}