#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }
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
#define dbgif(cond, x) ((cond) ? cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl : cerr)
#else
#define dbg(x) (x)
#define dbgif(cond, x) 0
#endif

struct DoubleHash : public std::pair<unsigned, unsigned> {
    using ull = unsigned long long;
    using pair = std::pair<unsigned, unsigned>;
    static std::pair<unsigned, unsigned> MODs;
    DoubleHash(std::pair<unsigned, unsigned> x) : pair(x) {}
    DoubleHash(unsigned x, unsigned y) : pair(x, y) {}
    DoubleHash(unsigned x) : DoubleHash(x, x) {}
    DoubleHash() : DoubleHash(0) {}
    static inline DoubleHash mod_subtract(pair x) {
        if (x.first >= MODs.first) x.first -= MODs.first;
        if (x.second >= MODs.second) x.second -= MODs.second;
        return x;
    }
    DoubleHash operator+(const DoubleHash &x) const {
        return mod_subtract({this->first + x.first, this->second + x.second});
    }
    DoubleHash operator+(unsigned x) const { return mod_subtract({this->first + x, this->second + x}); }
    DoubleHash operator-(const DoubleHash &x) const {
        return mod_subtract({this->first + MODs.first - x.first, this->second + MODs.second - x.second});
    }
    DoubleHash operator*(const DoubleHash &x) const {
        return {unsigned(ull(this->first) * x.first % MODs.first), unsigned(ull(this->second) * x.second % MODs.second)};
    }
    DoubleHash operator*(unsigned x) const {
        return {unsigned(ull(this->first) * x % MODs.first), unsigned(ull(this->second) * x % MODs.second)};
    }
    static DoubleHash gen_b(bool force_update = false) {
        static DoubleHash b{0, 0};
        if (b == DoubleHash{0, 0} or force_update) {
            std::mt19937 mt(std::chrono::steady_clock::now().time_since_epoch().count());
            std::uniform_int_distribution<unsigned> d(1 << 16, 1 << 29);
            b = {d(mt), d(mt)};
        }
        return b;
    }
};
std::pair<unsigned, unsigned> DoubleHash::MODs{1000000007, 998244353};

// Rolling Hash (Rabin-Karp), 1dim
template <typename V = DoubleHash> struct rolling_hash {
    int N;
    const V B;
    std::vector<V> hash;         // hash[i] = s[0] * B^(i - 1) + ... + s[i - 1]
    static std::vector<V> power; // power[i] = B^i
    void _extend_powvec() {
        while (static_cast<int>(power.size()) <= N) {
            auto tmp = power.back() * B;
            power.push_back(tmp);
        }
    }
    template <typename Int> rolling_hash(const std::vector<Int> &s, V b = V::gen_b()) : N(s.size()), B(b), hash(N + 1) {
        for (int i = 0; i < N; i++) hash[i + 1] = hash[i] * B + s[i];
        _extend_powvec();
    }
    rolling_hash(const std::string &s = "", V b = V::gen_b()) : N(s.size()), B(b), hash(N + 1) {
        for (int i = 0; i < N; i++) hash[i + 1] = hash[i] * B + s[i];
        _extend_powvec();
    }
    void addchar(const char &c) {
        V hnew = hash[N] * B + c;
        N++, hash.emplace_back(hnew);
        _extend_powvec();
    }
    V get(int l, int r) const { // s[l] * B^(r - l - 1) + ... + s[r - 1]
        return hash[r] - hash[l] * power[r - l];
    }
    int lcplen(int l1, int l2) const {
        return longest_common_prefix(*this, l1, *this, l2);
    }
};
template <typename V> std::vector<V> rolling_hash<V>::power{1};

// Longest common prerfix between s1[l1, N1) and s2[l2, N2)
template <typename T>
int longest_common_prefix(const rolling_hash<T> &rh1, int l1, const rolling_hash<T> &rh2, int l2) {
    int lo = 0, hi = std::min(rh1.N + 1 - l1, rh2.N + 1 - l2);
    while (hi - lo > 1) {
        const int c = (lo + hi) / 2;
        auto h1 = rh1.get(l1, l1 + c), h2 = rh2.get(l2, l2 + c);
        (h1 == h2 ? lo : hi) = c;
    }
    return lo;
}
// Longest common suffix between s1[0, r1) and s2[0, r2)
template <typename T>
int longest_common_suffix(const rolling_hash<T> &rh1, int r1, const rolling_hash<T> &rh2, int r2) {
    int lo = 0, hi = std::min(r1, r2) + 1;
    while (hi - lo > 1) {
        const int c = (lo + hi) / 2;
        auto h1 = rh1.get(r1 - c, r1), h2 = rh2.get(r2 - c, r2);
        (h1 == h2 ? lo : hi) = c;
    }
    return lo;
}


int main() {
    int N;
    string S;
    cin >> N >> S;
    rolling_hash rh(S);

    vector<int> addmaxlen(N + 1, -1);

    for (int cl = 0, cr = N - 1; cl < cr; cl++, cr--) {
        int ok = -1, ng = cl + 1;
        // S[cl - ok:cl + ok + 1] == S[cr - ok:cr + ok + 1]
        while (ng - ok > 1) {
            const int len = (ok + ng) / 2;
            auto hl = rh.get(cl - len, cl + len + 1), hr = rh.get(cr - len, cr + len + 1);
            (hl == hr ? ok : ng) = len;
        }
        dbg((vector<int>{cl, cr, ok}));
        if (ok >= 0) chmax(addmaxlen[cl - ok], cl);
    }
    dbg(addmaxlen);
    REP(i, (N + 1) / 2) {
        chmax(addmaxlen[i + 1], addmaxlen[i]);
        int ret = (addmaxlen[i] - i) * 2 + 1;
        cout << max(ret, -1) << ' ';
    }
    cout << endl;
}