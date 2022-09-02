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
#define dbg(x) 0
#define dbgif(cond, x) 0
#endif

constexpr int D = 12;
vector<vector<pint>> memo(1 << D);

void precalc() {
    FOR(S, 1, 1 << D) {
        const int N = floor_lg(S - 1) + 1;
        string s(N, '0');
        REP(i, N) s[i] += (S >> (N - 1 - i)) & 1;
        REP(sdiv, S / 2) {
            int sum = 0;
            int carry = 0;
            REP(i, N) {
                carry = carry * 2 + (s[i] == '1');
                if ((sdiv >> i) & 1) {
                    sum += carry;
                    carry = 0;
                }
            }
            sum += carry;
            if (__builtin_popcount(sum) == 1) {
                vector<pint> ret;
                int last = 0;
                REP(i, N) {
                    if ((sdiv >> i) & 1) {
                        ret.emplace_back(last, i + 1);
                        last = i + 1;
                    }
                }
                ret.emplace_back(last, N);
                memo[S] = ret;
                break;
            }
        }
    }
}

vector<pint> solve(const string &S) {

    const int N = S.size();
    const int n1 = count(S.begin(), S.end(), '1');

    if (n1 == 0) return {};
    if (__builtin_popcount(n1) == 1) {
        vector<pint> ret(N);
        REP(i, N) ret[i] = make_pair(i, i + 1);
        return ret;
    }

    if (S == string(S.size(), '1')) {
        return {pint(0, S.size() - 1), pint(S.size() - 1, S.size())};
    }

    int n0 = 0;
    while (n0 < N and S[n0] == '0') ++n0;
    if (N - n0 < D) {
        int m = 0;
        FOR(i, n0, N) m = m * 2 + (S[i] == '1');
        auto ret = memo[m];
        if (ret.empty()) return ret;
        for (auto &[a, b] : ret) a += n0, b += n0;
        if (n0) ret.insert(ret.begin(), pint(0, n0));
        return ret;
    }

    const int target = 2 << floor_lg(n1);
    int req = target - n1;
    // dbg(S);
    // dbg(target);
    // dbg(req);

    auto eval_inc = [&](int l, int r) {
        int ret = 0;
        FOR(i, l, r) ret = ret * 2 + (S[i] == '1');
        FOR(i, l, r) ret -= (S[i] == '1');
        return ret;
    };

    int headlen = n0 + 1;
    while (headlen <= N and eval_inc(n0, headlen) <= req) ++headlen;
    --headlen;

    vector<pint> state;
    if (n0) state.emplace_back(0, n0);
    state.emplace_back(n0, headlen);

    req -= eval_inc(n0, headlen);
    // dbg(req);

    FOR(i, headlen, N) {
        int d1 = 1;
        IFOR(d, 2, 20) {
            if (i + d <= N and eval_inc(i, i + d) <= req) {
                d1 = d;
                break;
            }
        }
        state.emplace_back(i, i + d1);
        req -= eval_inc(i, i + d1);
        i += d1 - 1;
    }
    // dbg(req);
    if (req) {
        REP(i, N - 2) {
            if (S[i] == '1' and S[i + 1] == '0') {
                vector<pint> ret;
                REP(j, i) ret.emplace_back(j, j + 1);
                ret.emplace_back(i, i + 3);
                FOR(j, i + 3, N) ret.emplace_back(j, j + 1);
                return ret;
            }
        }
    }

    return state;
}

string s_;

void checker(const string &S, const vector<pint> &ret) {
    const int N = S.size();
    if (ret.empty()) {
        dbg(S);
        return;
    }
    assert(ret[0].first == 0);
    assert(ret.back().second == N);
    for (auto [a, b] : ret) {
        if (a >= b) {
            dbg(make_tuple(S, ret));
            throw;
        }
    }
    FOR(i, 1, ret.size()) {
        assert(ret[i - 1].second == ret[i].first);
    }

    int sum = 0;
    for (auto [l, r] : ret) {
        int tmp = 0;
        FOR(i, l, r) tmp = tmp * 2 + (S[i] == '1');
        sum += tmp;
    }
    if (__builtin_popcount(sum) != 1) {
        dbg(make_tuple(S, ret, sum));
        throw;
    }
};

void rec() {
    if (s_.size() > 20) return;
    auto s = solve(s_);
    checker(s_, s);
    s_ += '0';
    rec();
    s_.back() = '1';
    rec();
    s_.pop_back();
}

int main() {
    precalc();
    // rec();
    // dbg(solve("110000000111"));
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        auto ret = solve(S);
        // checker(S, ret);
        if (ret.empty()) {
            cout << "-1\n\n";
        } else {
            cout << ret.size() << '\n';
            for (auto [a, b] : ret) cout << a + 1 << ' ' << b << '\n';
            cout << '\n';
        }
    }
}