#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FI first
#define SE second
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

constexpr lint MOD = 998244353;

// Solve ax+by=gcd(a, b)
lint extgcd(lint a, lint b, lint &x, lint &y)
{
    lint d = a;
    if (b != 0) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    else x = 1, y = 0;
    return d;
}
// Calc a^(-1) (MOD m)
lint mod_inverse(lint a, lint m=MOD)
{
    lint x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
int main()
{
    lint N, M;
    cin >> N >> M;
    vector<int> like(N);
    vector<lint> w(N);
    cin >> like >> w;
    lint w_tot_1 = 0, w_tot_0 = 0;
    REP(i, N)
    {
        if (like[i]) w_tot_1 += w[i];
        else w_tot_0 += w[i];
    }

    vector<vector<lint>> dp(M + 1, vector<lint>(M + 1)); // prob (like, dislike)
    dp[0][0] = 1;
    REP(i, M) REP(j, M) if (dp[i][j] and i + j < M)
    {
        lint w1 = w_tot_1 + i;
        lint w0 = w_tot_0 - j;
        if (w0 < 0 or w0 + w1 <= 0) continue;
        (dp[i + 1][j] += dp[i][j] * w1 % MOD * mod_inverse(w0 + w1)) %= MOD;
        (dp[i][j + 1] += dp[i][j] * w0 % MOD * mod_inverse(w0 + w1)) %= MOD;
    }

    lint exp_1 = 0, exp_0 = 0;
    REP(i, M + 1)
    {
        (exp_0 += dp[M - i][i] * i) %= MOD;
        (exp_1 += dp[i][M - i] * i) %= MOD;
    }
    REP(i, N)
    {
        lint ret = 0;
        if (like[i])
        {
            ret = (w[i] + w[i] * exp_1 % MOD * mod_inverse(w_tot_1) % MOD) % MOD;
        }
        else
        {
            ret = (w[i] - w[i] * exp_0 % MOD * mod_inverse(w_tot_0) % MOD + MOD) % MOD;
        }
        printf("%lld\n", ret);
    }
}