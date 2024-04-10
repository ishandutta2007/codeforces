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

constexpr lint MOD = 1000000007;

// 1-indexed BIT (i : [1, len])
template<typename T>
struct BIT
{
    int len;
    vector<T> val;
    BIT(int num) : len(num), val(num + 1) {}
    BIT() : BIT(0) {}
    void reset() { fill(val.begin(), val.end(), 0); }
    void add(int pos, T v) { while (pos > 0 and pos <= len) val[pos] += v, pos += pos & -pos; }
    T sum(int pos) const // (0, pos]
    {
        T res = 0;
        while (pos > 0) res += val[pos], pos -= pos & -pos;
        return res;
    }
};
template<typename T> ostream &operator<<(ostream &os, const BIT<T> &b){ T prv = 0; os << "["; REP(i, b.len) { T nxt = b.sum(i + 1); os << nxt - prv << ","; prv = nxt; } os << "]"; return os; }

map<lint, int> zaatsu;

lint solve(vector<lint> A)
{
    lint N = A.size();
    BIT<lint> b2(zaatsu.size());
    lint ret = 0;
    REP(i, N)
    {
        b2.add(zaatsu[A[i]], i + 1);
        ret += b2.sum(zaatsu[A[i]] - 1) % MOD * A[i] % MOD * (N - i) % MOD;
    }
    return ret % MOD;
}

int main()
{
    int N;
    cin >> N;
    vector<lint> A(N);
    cin >> A;
    set<lint> se;
    for (auto v : A) se.insert(v);
    int i_ = 1;
    for (auto v : se) zaatsu[v] = i_++;
    lint ret = 0;
    REP(i, N) (ret += A[i] % MOD * (i + 1) % MOD * (N - i) % MOD) %= MOD;
    ret += solve(A);
    reverse(ALL(A));
    ret += solve(A);
    cout << ret % MOD << endl;
}