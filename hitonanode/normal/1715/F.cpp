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

using Pt = pair<double, double>;

const double EPS = 1e-14;

pair<vector<Pt>, vector<Pt>> gen_comb(int X, int Y) {
    vector<Pt> poly, ranges;
    poly.emplace_back(0, 0);
    poly.emplace_back(X, 0);
    poly.emplace_back(X, EPS);
    double w = 0.5 / X;
    IFOR(x, 1, X) {
        double ww = w * x;
        poly.emplace_back(x + ww, EPS);
        poly.emplace_back(x + ww, Y);
        poly.emplace_back(x, Y);
        poly.emplace_back(x, EPS);
        ranges.emplace_back(x, x + ww);
    }
    poly.emplace_back(0, EPS);
    return {poly, ranges};
}

double ask(const vector<Pt> poly) {
    int sz = poly.size();
    cout << "? " << sz << '\n';
    for (auto [x, y] : poly) cout << x << ' ' << y << '\n';
    cout.flush();
    double ret;
    cin >> ret;
    return ret;
}

double find_x(int X, int Y) {
    auto [poly, ranges] = gen_comb(X, Y);
    double f = ask(poly);
    double lo = 0.0, hi = X - 1;

    REP(_, 100) {
        double c = (lo + hi) / 2;
        double l = c, r = c + 1;

        double in = 0.0;
        for (auto [l2, r2] : ranges) {
            double ll = max(l, l2), rr = min(r, r2);
            if (ll <= rr) in += rr - ll;
        }
        (in > f + EPS * 100 ? hi : lo) = c;
    }
    vector<Pt> p2;
    p2.emplace_back(hi, 0);
    p2.emplace_back(hi + 1, 0);
    p2.emplace_back(hi + 1, Y);
    p2.emplace_back(hi, Y);

    auto f2 = ask(p2);
    return hi - 1 + f2;
}

double find_y(int X, int Y) {
    auto [poly, ranges] = gen_comb(Y, X);
    for (auto &[x, y] : poly) swap(x, y);
    double f = ask(poly);

    double lo = 0.0, hi = Y - 1;

    REP(_, 100) {
        double c = (lo + hi) / 2;
        double l = c, r = c + 1;

        double in = 0.0;
        for (auto [l2, r2] : ranges) {
            double ll = max(l, l2), rr = min(r, r2);
            if (ll <= rr) in += rr - ll;
        }
        (in > f + EPS * 100 ? hi : lo) = c;
    }
    vector<Pt> p2;
    p2.emplace_back(0, hi);
    p2.emplace_back(0, hi + 1);
    p2.emplace_back(X, hi + 1);
    p2.emplace_back(X, hi);

    auto f2 = ask(p2);
    return hi - 1 + f2;
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(15);
    int N, M;
    cin >> N >> M;
    auto x = find_x(N, M);
    auto y = find_y(N, M);
    cout << "! " << x << ' ' << y << endl;
}