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
using namespace __gnu_pbds; // find_by_order(), order_by_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

int N;
vector<lint> l, r, n;
vector<lint> prob;
constexpr lint MOD = 1000000007;
// Solve ax+by=gcd(a, b)
lint extgcd(lint a, lint b, lint &x, lint &y)
{
    lint d = a;
    if (b != 0) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    else x = 1, y = 0;
    return d;
}
// Calc a^(-1) (MOD m)
lint mod_inverse(lint a, lint m = MOD)
{
    lint x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

lint solveA()
{
    lint ret = 0;
    REP(i, N)
    {
        lint pattern = n[i + 1] * n[i] % MOD;
        lint bad = max(0LL, min(r[i + 1], r[i]) - max(l[i + 1], l[i]) + 1);
        prob[i] = (pattern - bad + MOD) % MOD * mod_inverse(pattern) % MOD;
        ret += prob[i];
    }
    return ret % MOD;
}

lint solveB()
{
    lint ret = 0;
    REP(i, N - 1)
    {
        lint pattern = n[i] * n[i + 1] % MOD * n[i + 2] % MOD;
        lint bad2 = max(0LL, min({r[i], r[i + 1], r[i + 2]}) - max({l[i], l[i + 1], l[i + 2]}) + 1);
        lint bad1a = max(0LL, min(r[i + 1], r[i]) - max(l[i + 1], l[i]) + 1) * n[i + 2] % MOD;
        lint bad1c = max(0LL, min(r[i + 1], r[i + 2]) - max(l[i + 1], l[i + 2]) + 1) * n[i] % MOD;
        ret += (pattern - bad1a - bad1c + bad2 + 2 * MOD) % MOD * mod_inverse(pattern) % MOD;
    }
    return ret % MOD;
}

lint solveC()
{
    lint tot = accumulate(ALL(prob), 0LL) % MOD;
    lint ret = 0;
    REP(i, N)
    {
        ret += prob[i] * (tot + 3 * MOD - prob[i] - (i ? prob[i - 1] : 0) - (i < N - 1 ? prob[i + 1] : 0)) % MOD;
    }
    return ret % MOD;
}

int main()
{
    cin >> N;
    l.resize(N + 1);
    r.resize(N + 1);
    n.resize(N + 1);
    REP(i, N) cin >> l[i + 1];
    REP(i, N) cin >> r[i + 1];
    REP(i, N + 1) n[i] = r[i] - l[i] + 1;

    prob.resize(N);
    lint retA = solveA();
    lint retB = solveB();
    lint retC = solveC();
    cout << (retA + retB * 2 + retC) % MOD << endl;
}