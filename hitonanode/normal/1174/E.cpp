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
constexpr lint MOD = 1000000007;
int N;

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
lint doublefac(lint n)
{
    if (n < 0) return 0;
    lint k = (n + 1) / 2;
    if (n & 1) return fac[k * 2] * power(facInv[2], k) % MOD * power(fac[k], MOD - 2) % MOD;
    else return fac[k] * power(facInv[2], k) % MOD;
}

lint solve(vector<int> vec)
{
    int gcdnow = accumulate(ALL(vec), 1, multiplies<int>());
    int used = 1;
    lint ret = 1;
    for (auto v : vec)
    {
        gcdnow /= v;
        int use_new = N / gcdnow - used;
        ret = ret * nCr(N - used - 1, use_new - 1) % MOD * fac[use_new] % MOD;
        used += use_new;
    }
    return ret;
}

int main()
{
    cin >> N;
    facInit(N);
    int D = 0;
    while (POW2(D + 1) <= N) D++;
    lint ret = solve(vector<int>(D, 2));
    if (D and POW2(D - 1) * 3 <= N)
    {
        vector<int> tmp(D, 2);
        REP(i, D)
        {
            vector<int> tt = tmp;
            tt[i] = 3;
            ret += solve(tt);
        }
    }
    cout << ret % MOD << endl;
}