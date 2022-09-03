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
template<typename T> bool mmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
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
// Static sequence sparse table
// Complexity: O(NlogN) for precalculation, O(1) per query
template<typename T, typename F>
struct SparseTable {
    int N, lgN;
    T defaultT;
    F func;
    std::vector<std::vector<T>> data;
    std::vector<int> lgx_table;
    SparseTable() : N(0), func([](int, int) { return T(0); }) {}
    SparseTable(const std::vector<T> &sequence, T defaultT, F func) : N(sequence.size()), defaultT(defaultT), func(func)
    {
        lgx_table.resize(N + 1);
        for (int i = 2; i < N + 1; i++) lgx_table[i] = lgx_table[i >> 1] + 1;
        lgN = lgx_table[N] + 1;
        data.assign(lgN, std::vector<T>(N, defaultT));
        data[0] = sequence;
        for (int d = 1; d < lgN; d++) {
            for (int i = 0; i + (1 << d) <= N; i++) {
                data[d][i] = func(data[d - 1][i], data[d - 1][i + (1 << (d - 1))]);
            }
        }
    }
    T get(int l, int r) { // [l, r), 0-indexed
        assert(l >= 0 and r <= N);
        if (l >= r) return defaultT;
        int d = lgx_table[r - l];
        return func(data[d][l], data[d][r - (1 << d)]);
    }
};
*/
template<typename TDATA>
struct SparseTableVirtual {
    int N, lgN;
    TDATA defaultDATA;
    virtual TDATA datamerge(const TDATA &, const TDATA &) = 0;
    std::vector<std::vector<TDATA>> data;
    std::vector<int> lgx_table;
    SparseTableVirtual() = default;
    void initialize(const std::vector<TDATA> &sequence, TDATA dD)
    {
        defaultDATA = dD;
        N = sequence.size();
        lgx_table.resize(N + 1);
        for (int i = 2; i < N + 1; i++) lgx_table[i] = lgx_table[i >> 1] + 1;
        lgN = lgx_table[N] + 1;
        data.assign(lgN, std::vector<TDATA>(N));
        data[0] = sequence;
        for (int d = 1; d < lgN; d++) {
            for (int i = 0; i + (1 << d) <= N; i++) {
                data[d][i] = datamerge(data[d - 1][i], data[d - 1][i + (1 << (d - 1))]);
            }
        }
    }
    TDATA get(int l, int r) { // [l, r), 0-indexed
        assert(l >= 0 and r <= N);
        if (l >= r) return defaultDATA;
        int d = lgx_table[r - l];
        return datamerge(data[d][l], data[d][r - (1 << d)]);
    }
};

template<typename T>
struct StaticRMQ : public SparseTableVirtual<T>
{
    using ST = SparseTableVirtual<T>;
    static T merge(const T &l, const T &r) { return std::max(l, r); };
    T datamerge(const T &l, const T &r) override { return merge(l, r); };
    StaticRMQ() = default;
    StaticRMQ(const std::vector<T> &seq, T defaultmax) : ST::SparseTableVirtual() {
        ST::initialize(seq, defaultmax);
    }
};
/*
template<typename T, typename F>
struct SparseTable2D {
    int H, lgH, W;
    T defaultT;
    F func;
    std::vector<std::vector<SparseTable<T, F>>> data;
    std::vector<int> lgx_table;
    SparseTable2D(const std::vector<std::vector<T>> &matrix, T defaultT, F func) : defaultT(defaultT), func(func) {
        H = matrix.size(), W = (matrix.size() ? matrix[0].size() : 0);
        lgx_table.resize(H + 1);
        for (int i = 2; i < H + 1; i++) lgx_table[i] = lgx_table[i >> 1] + 1;
        lgH = lgx_table[H] + 1;
        data.resize(lgH);
        for (auto v : matrix) data[0].emplace_back(SparseTable<T, F>(v, defaultT, func));
        for (int d = 1; d < lgH; d++) {
            for (int i = 0; i + (1 << d) <= H; i++) {
                std::vector<T> v(W);
                for (int j = 0; j < W; j++) v[j] = func(data[d - 1][i].data[0][j], data[d - 1][i + (1 << (d - 1))].data[0][j]);
                data[d].emplace_back(SparseTable<T, F>(v, defaultT, func));
            }
        }
    }
    T get(int xl, int xr, int yl, int yr) {
        assert(xl >= 0 and xr <= H and yl >= 0 and yr <= W);
        if (xl >= xr) return defaultT;
        int d = lgx_table[xr - xl];
        return func(data[d][xl].get(yl, yr), data[d][xr - (1 << d)].get(yl, yr));
    }
};
*/
template<typename T, typename SparseTable1D>
struct SparseTable2DV {
    int H, lgH, W;
    T defaultT;
    std::vector<std::vector<SparseTable1D>> data;
    std::vector<int> lgx_table;
    SparseTable2DV(const std::vector<std::vector<T>> &matrix, T defaultT) : defaultT(defaultT) {
        H = matrix.size(), W = (matrix.size() ? matrix[0].size() : 0);
        lgx_table.resize(H + 1);
        for (int i = 2; i < H + 1; i++) lgx_table[i] = lgx_table[i >> 1] + 1;
        lgH = lgx_table[H] + 1;
        data.resize(lgH);
        for (auto v : matrix) data[0].emplace_back(SparseTable1D(v, defaultT));
        for (int d = 1; d < lgH; d++) {
            for (int i = 0; i + (1 << d) <= H; i++) {
                std::vector<T> v(W);
                for (int j = 0; j < W; j++) v[j] = SparseTable1D::merge(data[d - 1][i].data[0][j], data[d - 1][i + (1 << (d - 1))].data[0][j]);
                data[d].emplace_back(SparseTable1D(v, defaultT));
            }
        }
    }
    T get(int xl, int xr, int yl, int yr) {
        assert(xl >= 0 and xr <= H and yl >= 0 and yr <= W);
        if (xl >= xr) return defaultT;
        int d = lgx_table[xr - xl];
        return SparseTable1D::merge(data[d][xl].get(yl, yr), data[d][xr - (1 << d)].get(yl, yr));
    }
};


int main()
{
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<string> S(H);
    for (auto &s : S) cin >> s;

    vector<vector<int>> mat(H, vector<int>(W));
    REP(i, H - 1) REP(j, W - 1) if (S[i][j] == 'R' and S[i][j + 1] == 'G' and S[i + 1][j] == 'Y' and S[i + 1][j + 1] == 'B')
    {
        for (int d = 1;; d++)
        {
            mat[i][j]++;

            if (i - d < 0 or i + 1 + d >= H or j - d < 0 or j + 1 + d >= W) break;

            bool flg = true;
            FOR(x, i - d, i + d + 2) {
                if (S[x][j - d] != S[i + (x > i)][j]) flg = false;
                if (S[x][j + 1 + d] != S[i + (x > i)][j + 1]) flg = false;
            }
            FOR(y, j - d, j + d + 2) {
                if (S[i - d][y] != S[i    ][j + (y > j)]) flg = false;
                if (S[i + 1 + d][y] != S[i + 1][j + (y > j)]) flg = false;
            }
            if (!flg) break;
        }
    }
    // auto f = [](int l, int r) { return max(l, r); };
    // SparseTable2D<int, decltype(f)> st(mat, 0, f);
    SparseTable2DV<int, StaticRMQ<int>> st(mat, 0);
    while (Q--)
    {
        int h1, h2, w1, w2;
        cin >> h1 >> w1 >> h2 >> w2;
        h1--, w1--;
        int l = 0, r = 251;
        while (r - l > 1) {
            int c = (l + r) / 2;
            (st.get(h1 + c - 1, h2 - c, w1 + c - 1, w2 - c) >= c ? l : r) = c;
        }
        printf("%d\n", l * l * 2 * 2);
    }
}