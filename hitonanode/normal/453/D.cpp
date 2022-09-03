#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#else
#define dbg(x) {}
#endif


// Fast Walsh-Hadamard transform and its abstraction
// Tutorials: <https://codeforces.com/blog/entry/71899>
//            <https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it>
template <typename T, typename F> void abstract_fwht(std::vector<T> &seq, F f) {
    const int n = seq.size();
    assert(__builtin_popcount(n) == 1);
    for (int w = 1; w < n; w *= 2) {
        for (int i = 0; i < n; i += w * 2) {
            for (int j = 0; j < w; j++) { f(seq[i + j], seq[i + j + w]); }
        }
    }
}


lint power(__int128 x, lint n, lint MOD) {
    x %= MOD;
    __int128 ans = 1;
    while (n) {
        if (n & 1) (ans *= x) %= MOD;
        (x *= x) %= MOD;
       n >>= 1;
    }
   return ans;
}

int main()
{
    int M;
    lint T_, P;
    cin >> M >> T_ >> P;
    vector<lint> e(1 << M), b(M + 1);
    cin >> e >> b;
    vector<lint> trans(1 << M), tmp(1 << M);
    REP(s, trans.size()) trans[s] = b[__builtin_popcount(s)] % P;

    lint md = P << M;
    using T = lint;
    auto f = [&md](T &lo, T &hi) {
        T c = lo + hi;
        hi = lo - hi, lo = c;
        if (hi < 0) hi += md;
        if (lo >= md) lo -= md;
    };
    abstract_fwht(trans, f);

    vector<__int128> cnt2v(M + 1, -1);
    REP(i, trans.size()) {
        auto x = trans[i];
        int pc = __builtin_popcount(i);
        if (cnt2v[pc] >= 0) trans[i] = cnt2v[pc];
        else trans[i] = cnt2v[pc] = power(x, T_, P << M);
    }
    abstract_fwht(e, f);
    REP(i, e.size()) e[i] = (__int128(e[i]) * trans[i]) % (P << M);
    abstract_fwht(e, f);

    for (auto x : e) cout << ((x >> M) % P + P) % P << '\n';
}