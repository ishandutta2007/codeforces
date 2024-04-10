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

// StarrySkyTree: segment tree for Range Minimum Query & Range Add Query
// Complexity: (N)$ (construction), (\log N)$ (add / get / prod)
// - RangeAddRangeMin(std::vector<Tp> data_init) : Initialize array x by data_init.
// - add(int begin, int end, Tp vadd) : Update x[i] <- x[i] + vadd for all begin <= i < end.
// - get(int pos) : Get x[pos].
// - prod(int begin, int end) : Get min(x[begin], ..., x[end - 1]).
template <typename Tp, Tp defaultT = std::numeric_limits<Tp>::max() / 2> struct RangeAddRangeMin {
    int N, head;
    std::vector<Tp> range_min, range_add;
    static inline Tp f(Tp x, Tp y) noexcept { return std::min(x, y); }

    inline void _merge(int pos) {
        range_min[pos] = f(range_min[pos * 2] + range_add[pos * 2], range_min[pos * 2 + 1] + range_add[pos * 2 + 1]);
    }
    void initialize(const std::vector<Tp> &data_init) {
        N = data_init.size(), head = 1;
        while (head < N) head <<= 1;
        range_min.assign(head * 2, defaultT);
        range_add.assign(head * 2, 0);
        std::copy(data_init.begin(), data_init.end(), range_min.begin() + head);
        for (int pos = head; --pos;) _merge(pos);
    }
    RangeAddRangeMin() = default;
    RangeAddRangeMin(const std::vector<Tp> &data_init) { initialize(data_init); }
    void _add(int begin, int end, int pos, int l, int r, Tp vadd) noexcept {
        if (r <= begin or end <= l) return;
        if (begin <= l and r <= end) {
            range_add[pos] += vadd;
            return;
        }
        _add(begin, end, pos * 2, l, (l + r) / 2, vadd);
        _add(begin, end, pos * 2 + 1, (l + r) / 2, r, vadd);
        _merge(pos);
    }
    // Add `vadd` to (x_begin, ..., x_{end - 1})
    void add(int begin, int end, Tp vadd) noexcept { return _add(begin, end, 1, 0, head, vadd); }
    Tp _get(int begin, int end, int pos, int l, int r) const noexcept {
        if (r <= begin or end <= l) return defaultT;
        if (begin <= l and r <= end) return range_min[pos] + range_add[pos];
        return f(_get(begin, end, pos * 2, l, (l + r) / 2), _get(begin, end, pos * 2 + 1, (l + r) / 2, r)) + range_add[pos];
    }
    // Return f(x_begin, ..., x_{end - 1})
    Tp get(int pos) const noexcept { return prod(pos, pos + 1); }
    Tp prod(int begin, int end) const noexcept { return _get(begin, end, 1, 0, head); }
};


string solve() {
    int N, M;
    cin >> N >> M;
    vector<lint> A(N);
    cin >> A;
    sort(A.begin(), A.end());
    vector<vector<lint>> grps(M);
    vector<int> init(N + 1);
    REP(i, init.size()) init[i] = N - i;
    RangeAddRangeMin<int> tree(init);

    for (auto &vec : grps) {
        int k;
        cin >> k;
        vec.resize(k);
        cin >> vec;
        lint sum = accumulate(vec.begin(), vec.end(), 0LL);
        lint avg = (sum + k - 1) / k;
        int i = arglb(A, avg);
        tree.add(0, i + 1, -1);
    }
    string ret;
    for (const auto &vec : grps) {
        lint sum = accumulate(vec.begin(), vec.end(), 0LL);
        const int k = vec.size();
        lint avg = (sum + k - 1) / k;
        const int i = arglb(A, avg);
        tree.add(0, i + 1, 1);
        for (auto x : vec) {
            lint newavg = (sum - x + k - 2) / (k - 1);
            int newi = arglb(A, newavg);
            tree.add(0, newi + 1, -1);
            auto mi = tree.prod(0, init.size());
            if (mi >= 0) {
                ret += '1';
            } else {
                ret += '0';
            }
            tree.add(0, newi + 1, 1);
        }
        tree.add(0, i + 1, -1);
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
        // cout << (solve() ? "YES" : "NO") << '\n';
    }
}