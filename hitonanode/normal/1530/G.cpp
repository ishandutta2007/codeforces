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

pair<vector<int>, vector<pint>> hyojunkei(vector<int> v, int K) {
    vector<pint> procedure;
    auto mv = [&](int i, int j, int quantity) -> void {
        if (i == j) return;
        else if (i < j) {
            int l = accumulate(v.begin(), v.begin() + i, 0) + i + v[i] - quantity;
            int r = accumulate(v.begin(), v.begin() + j, 0) + j;
            procedure.emplace_back(l + 1, r);
        } else {
            int l = accumulate(v.begin(), v.begin() + j, 0) + j + v[j];
            int r = accumulate(v.begin(), v.begin() + i, 0) + i + quantity;
            procedure.emplace_back(l + 1, r);
        }
        v[i] -= quantity;
        v[j] += quantity;
        reverse(v.begin() + min(i, j) + 1, v.begin() + max(i, j));
    };

    if (K == 0) {
        
    } else if (K >= int(v.size())) {

    } else if (K == int(v.size()) - 1) {
        mv(v.size() - 1, 0, v.back());
        if (v.size() >= 4) {
            auto a = v;
            reverse(a.begin() + 1, a.end() - 1);
            if (a < v) mv(0, v.size() - 1, 0);
        }
    } else if (K == 1) {
        IREP(i, v.size() - 1) {
            mv(i + 1, i, v[i + 1]);
        }
    } else {
        IFOR(i, 2, v.size()) {
            int j = i + K;
            if (j < int(v.size())) {
                mv(j, i, v[j]);
            }
        }
        REP(t, K) {
            if (t % 2 == 0) {
                mv(1, K + 1, v[1]);
            } else {
                mv(K, 0, v[K]);
            }
        }
        if (K % 2 == 0) {
            mv(K + 1, 1, v[K + 1]);
        } else {
            mv(K + 1, 1, v[K + 1]);
            REP(t, K - 1) {
                if (t % 2 == 0) mv(0, K, 0);
                else mv(K + 1, 1, 0);
            }
            mv(K, 0, v[K]);
        }
    }
    dbg(v);
    return {v, procedure};
}

void solve() {
    int N, K;
    string S, T;
    cin >> N >> K >> S >> T;
    N = S.size();
    const int n1 = count(S.begin(), S.end(), '1');
    if (n1 != count(T.begin(), T.end(), '1')) {
        cout << "-1\n";
        return;
    }
    auto genseq = [](const string &s) {
        int len = 0;
        vector<int> ret;
        for (auto c : s) {
            if (c == '1')
                ret.push_back(len), len = 0;
            else
                len++;
        }
        ret.push_back(len);
        return ret;
    };
    dbg(S);
    dbg(T);
    auto v1 = genseq(S), v2 = genseq(T);
    dbg(v1);
    dbg(v2);
    auto [r1, seq1] = hyojunkei(v1, K);
    auto [r2, seq2] = hyojunkei(v2, K);
    if (r1 != r2) {
        cout << "-1\n";
        return;
    }
    reverse(ALL(seq2));
    seq1.insert(seq1.end(), ALL(seq2));

    dbg(K);
    dbg(seq1);
    dbg(S);
    dbg(T);
    for (auto [l, r] : seq1) {
        reverse(S.begin() + l - 1, S.begin() + r);
    }
    dbg(S);
    assert(S == T);
    assert(seq1.size() <= 4 * S.size());
    cout << seq1.size() << '\n';
    for (auto [l, r] : seq1) cout << l << ' ' << r << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}