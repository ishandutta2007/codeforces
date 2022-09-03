#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

struct custom_hash
{
    // <https://codeforces.com/blog/entry/62393>
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using umap = gp_hash_table<lint, int, custom_hash>; // fast unordered_set / unordered_map

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
    inline TDATA& at(int i) { return data[i]; }

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
};

struct T
{
    int ret, rlim;
    T() = default;
    constexpr bool operator==(const T &x) const {
        return (ret == x.ret and rlim == x.rlim);
    }
};



T better(const T &x, const T &y)
{
    if (x.ret != y.ret)
    {
        return x.ret > y.ret ? x : y;
    }
    if (x.rlim != y.rlim)
    {
        return x.rlim < y.rlim ? x : y;
    }
    return x;
}

struct RangeMaximumQuery : public NonrecursiveSegmentTree<T, T, bool>
{
    using SegTree = NonrecursiveSegmentTree<T, T, bool>;
    T merge_data(const T &vl, const T &vr) override { return better(vl, vr); };
    T data2ret(const T &v, const bool &q) override { return v; }
    T merge_ret(const T &vl, const T &vr) override { return better(vl, vr); };
    RangeMaximumQuery(const std::vector<T> &seq, T defaultmax) : SegTree::NonrecursiveSegmentTree() {
        SegTree::initialize(seq, defaultmax);
    };
};



int main()
{
    int N;
    cin >> N;
    vector<lint> A(N), B(N);
    cin >> A >> B;
    umap mpa, mpb, mpab;
    mpa[0] = mpb[0] = mpab[0] = 0;
    lint aa = 0, ab = 0;
    T t0{0, 0};

    vector<T> v1(N + 1, t0);
    RangeMaximumQuery sta1(v1, t0), sta2(v1, t0), stb1(v1, t0), stb2(v1, t0);

    auto upd = [&](int i1, int i2, int val) -> void {
        dbg((vector<int>{i1, i2, val}));
        T q{val, i2};
        if (i1 >= i2)
        {
            if (better(sta1.get(i1, i1 + 1), q) == q) sta1.update(i1, q);
        }
        if (i1 <= i2)
        {
            if (better(stb1.get(i1, i1 + 1), q) == q) stb1.update(i1, q);
        }
        q = T{val, i1};
        if (i2 >= i1)
        {
            if (better(sta2.get(i2, i2 + 1), q) == q) sta2.update(i2, q);
        }
        if (i2 <= i1)
        {
            if (better(stb2.get(i2, i2 + 1), q) == q) stb2.update(i2, q);
        }
    };

    FOR(i, 1, N + 1)
    {
        aa += A[i - 1], ab += B[i - 1];
        if (mpa.find(aa) != mpa.end())
        {
            int j = mpa[aa];
            dbg("A");
            dbg((vector<int>{i, j}));
            T tmp = sta1.get(0, j + 1);
            upd(i, tmp.rlim, tmp.ret + 1);

            tmp = stb1.get(0, j + 1);
            upd(i, tmp.rlim, tmp.ret + 1);
        }
        if (mpb.find(ab) != mpb.end())
        {
            int j = mpb[ab];
            dbg("B");
            dbg((vector<int>{i, j}));
            T tmp = sta2.get(0, j + 1);
            upd(tmp.rlim, i, tmp.ret + 1);

            tmp = stb2.get(0, j + 1);
            upd(tmp.rlim, i, tmp.ret + 1);
        }
        if (mpab.find(aa + ab) != mpab.end())
        {
            int j = mpab[aa + ab];
            dbg("AB");
            dbg((vector<int>{i, j}));
            int v = max(sta1.get(0, j + 1).ret, sta2.get(0, j + 1).ret);
            upd(i, i, v + 1);
        }
        mpa[aa] = i;
        mpb[ab] = i;
        mpab[aa + ab] = i;
    }
    cout << max(sta1.get(0, N + 1).ret, sta2.get(0, N + 1).ret) << '\n';
}