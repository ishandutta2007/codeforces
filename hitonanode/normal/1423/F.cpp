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
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args>
void ndarray(vector<T>& vec, const V& val, int len, Args... args)
{
    vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); });
}
template <typename T>
bool chmax(T& m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T>
bool chmin(T& m, const T q) { return m > q ? (m = q, true) : false; }
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

// output
template <typename T, typename V>
ostream& dmpseq(ostream&, const T&, const string&, const string&, const string&);
#if __cplusplus >= 201703L
template <typename... T>
ostream& operator<<(ostream& os, const tuple<T...>& tpl)
{
    return apply([&os](auto&&... args) { ((os << args << ','), ...); }, tpl), os;
}
#endif
//
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '(' << p.first << ',' << p.second << ')'; }
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& x) { return dmpseq<vector<T>, T>(os, x, "[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& x) { return dmpseq<deque<T>, T>(os, x, "deq[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const set<T>& x) { return dmpseq<set<T>, T>(os, x, "{", ",", "}"); }
template <typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_set<T, TH>& x) { return dmpseq<unordered_set<T, TH>, T>(os, x, "{", ",", "}"); }
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& x) { return dmpseq<multiset<T>, T>(os, x, "{", ",", "}"); }
template <typename TK, typename T>
ostream& operator<<(ostream& os, const map<TK, T>& x) { return dmpseq<map<TK, T>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename TK, typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_map<TK, T, TH>& x) { return dmpseq<unordered_map<TK, T, TH>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename T, typename V>
ostream& dmpseq(ostream& os, const T& seq, const string& pre, const string& sp, const string& suf)
{
    return os << pre, for_each(begin(seq), end(seq), [&](V x) { os << x << sp; }), os << suf;
}
template <typename T>
void print(const vector<T>& x) { dmpseq<vector<T>, T>(cout, x, "", " ", "\n"); }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

// template <>
// struct std::numeric_limits<__int128> {
//     static __int128 max() noexcept { return ((__int128(1) << 126) - 1) * 2 + 1; }
//     static __int128 min() noexcept { return -max() - 1; }
//     static __int128 lowest() noexcept { return min(); }
// };
__int128 str2i128(std::string str)
{
    __int128 ret = 0;
    bool minus = false;
    for (auto c : str) {
        if (c == '-')
            minus = true;
        else
            ret = ret * 10 + c - '0';
    }
    return minus ? -ret : ret;
}
std::istream& operator>>(std::istream& is, __int128& x)
{
    std::string s;
    is >> s;
    x = str2i128(s);
    return is;
}
std::ostream& operator<<(std::ostream& os, const __int128& x)
{
    __int128 tmp = x;
    if (tmp == 0)
        return os << 0;
    std::vector<int> ds;
    if (tmp < 0) {
        os << '-';
        while (tmp) {
            int d = tmp % 10;
            if (d > 0)
                d -= 10;
            ds.emplace_back(-d), tmp = (tmp - d) / 10;
        }
    } else {
        while (tmp)
            ds.emplace_back(tmp % 10), tmp /= 10;
    }
    std::reverse(ds.begin(), ds.end());
    for (auto i : ds)
        os << i;
    return os;
}

using Int = lint;
// Solve ax+by=gcd(a, b)
Int extgcd(Int a, Int b, Int &x, Int &y)
{
    Int d = a;
    if (b != 0) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    else x = 1, y = 0;
    return d;
}
// Calc a^(-1) (MOD m)
Int mod_inverse(Int a, Int m)
{
    Int x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

vector<vector<Int>> matmul(const vector<vector<Int>> &A, const vector<vector<Int>> &B, Int mod)
{
    int H = A.size(), W = B[0].size(), K = B.size();
    vector<vector<Int>> C(H, vector<Int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < K; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

vector<Int> matmul(const vector<vector<Int>> &A, const vector<Int> &v, Int mod)
{
    vector<Int> res(A.size());
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)v.size(); j++) {
            res[i] += A[i][j] * v[j];
        }
    }
    return res;
}
vector<vector<Int>> matpower(vector<vector<Int>> X, Int n, Int mod)
{
    vector<vector<Int>> res(X.size(), vector<Int>(X.size()));
    for (int i = 0; i < (int)res.size(); i++) res[i][i] = 1;
    while (n)
    {
        if (n & 1) res = matmul(res, X, mod);
        X = matmul(X, X, mod); n >>= 1;
    }
    return res;
}

vector<vector<vector<Int>>> mats;

vector<Int> trans(vector<Int> now, int dt) {
    REP(d, 30) if ((dt >> d) & 1) {
        now = matmul(mats[d], now, -1);
    }
    return now;
}

int main()
{
    int N, K;
    cin >> N >> K;
    map<int, lint> a2b;
    long long tot = 0;
    REP(t, K) {
        int a, b;
        cin >> a >> b;
        a2b[a] += b;
        tot += b;
    }
    if (tot != N) {
        cout << (tot < N ? 1 : -1) << '\n';
        return 0;
    }
    a2b[1] += 0;
    a2b[N] += 0;

    vector<pint> ab;
    for (auto p : a2b) ab.emplace_back(p);


    vector<vector<Int>> mat(4, vector<Int>(4));
    REP(d, 4) mat[d][d] = 1;
    mat[1][0] = 1;
    mat[2][0] = mat[3][1] = 1;
    mats.emplace_back(mat);
    while (mats.size() < 30) {
        vector<vector<Int>> m = mats.back();
        mats.emplace_back(matmul(m, m, -1));
    }


    vector<Int> vec { 1, 1 - ab[0].second, 1, 0 };
    int last = 2;
    for (auto [i, b] : ab) {
        if (i == 1) continue;
        vec = trans(vec, i - last);
        last = i + 1;
        vec[2] += vec[0], vec[3] += vec[1];
        vec[1] += vec[0] - b;
    }
    cout << (vec[3] % vec[2] == 0 ? 1 : -1) << '\n';
}