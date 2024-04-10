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

// Nonrecursive Segment Tree (point-update, range-get)
// - Conditions for operations:
//   - merge_data: [TDATA, TDATA] -> TDATA, e(x, y) == e(y, x)
//   - data2ret: [TDATA, TQUERY] -> TRET
//   - merge_ret: [TRET, TRET] -> TRET, g(defaultRET, x) == x, g(x, y) = g(y, x)
//   - commutability f(e(x, y), q) == g(f(x, q), f(y, q))
template <typename TDATA, typename TRET, typename TQUERY>
struct NonrecursiveSegmentTree
{
    int N;
    TRET defaultRET;
    virtual TDATA merge_data(const TDATA &, const TDATA &) = 0;
    virtual TRET data2ret(const TDATA &, const TQUERY &) = 0;
    virtual TRET merge_ret(const TRET &, const TRET &) = 0;
    std::vector<TDATA> data;
    inline TDATA &at(int i) { return data[i]; }

    inline void _merge(int i) { at(i) = merge_data(at(i << 1), at((i << 1) + 1)); }
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
            if (l & 1) retl = merge_ret(retl, data2ret(data[l++], query));
            if (r & 1) retr = merge_ret(data2ret(data[--r], query), retr);
            l >>= 1, r >>= 1;
        }
        return merge_ret(retl, retr);
    }

    // Calculate smallest r that satisfies condition(g(f(x_l, q), ..., f(x_{r - 1}, q)) == true
    // Assumption: Monotonicity of g(x_l, ..., x_r) about r (l: fixed)
    // Complexity: O(log N)
    int binary_search(int l, auto condition, TQUERY query = NULL) {
        std::stack<int> rs;
        l += N;
        int r = N * 2;
        TRET retl = defaultRET;
        if (condition(retl)) return l - N;
        while (l < r) {
            if (l & 1) {
                TRET ret_tmp = merge_ret(retl, data2ret(data[l], query));
                if (condition(ret_tmp)) {
                    while (l * 2 < N * 2) {
                        ret_tmp = merge_ret(retl, data2ret(data[l * 2], query));
                        if (condition(ret_tmp)) l *= 2;
                        else retl = ret_tmp, l = l * 2 + 1;
                    }
                    return l - N;
                }
                l++;
                retl = ret_tmp;
            }
            if (r & 1) rs.push(--r);
            l >>= 1, r >>= 1;
        }
        while (!rs.empty()) {
            l = rs.top();
            rs.pop();
            TRET ret_tmp = merge_ret(retl, data2ret(data[l], query));
            if (condition(ret_tmp)) {
                while (l * 2 < N * 2) {
                    ret_tmp = merge_ret(retl, data2ret(data[l * 2], query));
                    if (condition(ret_tmp)) l *= 2;
                    else retl = ret_tmp, l = l * 2 + 1;
                }
                return l - N;
            }
            retl = ret_tmp;
        }
        return N;
    }

    template <typename T1, typename T2, typename T3>
    friend std::ostream &operator<<(std::ostream &os, NonrecursiveSegmentTree<T1, T2, T3> s)
    {
        os << "[SegmentTree (len: " << s.N << ')';
        for (int i = 0; i < s.N; i++) os << s.at(i + s.N) << ',';
        os << "]";
        return os;
    }
};


// Range Minimum Query
// - get: return min(x_l, ..., x_{r - 1})

constexpr lint INF = 1e18;
struct T
{
    array<lint, 4> a;
    T() = default;
    T(lint v) {
        a[0] = a[3] = 0;
        a[1] = v;
        a[2] = -v;
    }
};

T merge(const T &l, const T &r)
{
    T ret = l;
    REP(i, 4) REP(j, 4) if (i % 2 == j / 2)
    {
        chmax(ret.a[i / 2 * 2 + j % 2], l.a[i] + r.a[j]);
    }
    return ret;
}
struct ST : public NonrecursiveSegmentTree<T, T, bool>
{
    using SegTree = NonrecursiveSegmentTree<T, T, bool>;
    T merge_data(const T &vl, const T &vr) override { return merge(vl, vr); };
    T data2ret(const T &v, const bool &q) override { return v; }
    T merge_ret(const T &vl, const T &vr) override { return merge(vl, vr); };
    ST(const std::vector<T> &seq, T defaultmin) : SegTree::NonrecursiveSegmentTree() {
        SegTree::initialize(seq, defaultmin);
    };
};


void solve()
{
    int N, Q;
    cin >> N >> Q;
    vector<lint> A(N);
    cin >> A;

    vector<T> v(N);
    REP(i, N) v[i] = T(A[i]);
    ST tree(v, T());

    cout << tree.get(0, N).a[1] << '\n';
    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        swap(v[l], v[r]);
        tree.update(l, v[l]);
        tree.update(r, v[r]);
        cout << tree.get(0, N).a[1] << '\n';
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}