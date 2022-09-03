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
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/


constexpr lint MOD = 1000000007;
lint N, T;

vector<lint> fac, facInv, inv;
void facInit(int nmax)
{
    fac = facInv = inv = vector<lint>(nmax + 1, 1);
    for (int i = 2; i <= nmax; i++)
    {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        facInv[i] = facInv[i-1] * inv[i] % MOD;
    }
}
lint nCr(int n, int r)
{
    if (n<r || r<0) return 0;
    if (n >= (int)fac.size()) facInit(n);
    return (fac[n] * facInv[r] % MOD) * facInv[n-r] % MOD;
}
lint nPr(int n, int r)
{
    if (n<r || r<0) return 0;
    if (n >= (int)fac.size()) facInit(n);
    return fac[n] * facInv[n-r] % MOD;
}
lint power(lint x, lint n, lint mod=MOD)
{
    lint ans = 1;
    while (n>0)
    {
        if (n & 1) (ans *= x) %= mod;
        (x *= x) %= mod;
       n >>= 1;
    }
   return ans;
}

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
    cin >> N >> T;
    vector<lint> t(N);
    REP(i, N) cin >> t[i];
    t.push_back(300000000000000LL);
    N++;
    facInit(N);

    lint ret = 0;
    lint acc_time = 0;
    int i = 0;
    lint prb = 0;
    while (i < N and acc_time < T) acc_time += t[i], i++;
    for (; i > 0; i--) // i
    {
        if (acc_time + i <= T) prb = 1;
        else if (acc_time > T) prb = 0;
        else
        {
            lint d = T - acc_time;
            lint mip = mod_inverse(power(2, i + 1));
            FOR(j, max<lint>(0, d - t[i] + 1), d + 1) prb += nCr(i, j) * mip % MOD;
            FOR(j, max<lint>(0, d - (t[i] + 1) + 1), d + 1) prb += nCr(i, j) * mip % MOD;
        }

        acc_time -= t[i - 1];
        ret += prb;
    }

    cout << ret % MOD << endl;
}