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

constexpr lint mod = 1000000007;
lint extgcd(lint a, lint b, lint &x, lint &y)
{
    lint d = a;
    if (b != 0) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    else x = 1, y = 0;
    return d;
}
// Calc a^(-1) (MOD m)
lint mod_inverse(lint a, lint m=mod)
{
    lint x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
vector<vector<lint>> matmul(const vector<vector<lint>> &A, const vector<vector<lint>> &B)
{
    int H = A.size(), W = B[0].size(), K = B.size();
    vector<vector<lint>> C(H, vector<lint>(W));
    REP(i, H) REP(j, W) REP(k, K) (C[i][j] += A[i][k] * B[k][j]) %= mod;
    return C;
}
vector<lint> matmul(const vector<vector<lint>> &A, const vector<lint> &v)
{
    vector<lint> res(A.size());
    REP(i, A.size()) REP(j, v.size()) (res[i] += A[i][j] * v[j]) %= mod;
    return res;
}
vector<vector<lint>> matpower(vector<vector<lint>> X, lint n)
{
    vector<vector<lint>> res(X.size(), vector<lint>(X.size()));
    REP(i, res.size()) res[i][i] = 1;
    while (n)
    {
        if (n & 1) res = matmul(res, X);
        X = matmul(X, X); n >>= 1;
    }
    return res;
}


int main()
{
    lint N, K;
    cin >> N >> K;
    vector<int> a(N);
    cin >> a;
    int n_on = accumulate(ALL(a), 0);

    int m, ok_start = 0;
    if (n_on < N / 2)
    {
        m = n_on;
        FOR(i, N - n_on, N) ok_start += a[i];
    }
    else
    {
        m = N - n_on;
        REP(i, N - n_on) ok_start += 1 - a[i];
    }

    vector<vector<lint>> trans(m + 1, vector<lint>(m + 1));

    lint denom = mod_inverse(N * (N - 1) / 2);
    REP(i, m + 1)
    {
        if (i > 0) trans[i - 1][i] = denom * i % mod * (N + i - 2 * m) % mod;
        if (i < m) trans[i + 1][i] = denom * (m - i) % mod * (m - i) % mod;
        trans[i][i] = (1LL - (i > 0 ? trans[i - 1][i] : 0) - (i < m ? trans[i + 1][i] : 0) + 2 * mod) % mod;
    }
    vector<lint> initvec(m + 1);
    initvec[ok_start] = 1;
    vector<lint> ret = matmul(matpower(trans, K), initvec);
    cout << ret.back() << endl;
}