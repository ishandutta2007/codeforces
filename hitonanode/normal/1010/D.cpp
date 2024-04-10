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

int main() {
    int N;
    cin >> N;
    vector<int> state(N);
    const int AND = 1, OR = 2, XOR = 3, NOT = 4;
    vector<vector<int>> ch(N);
    vector<int> isleaf(N);
    vector<int> bitdefault(N);
    REP(i, N) {
        string s;
        cin >> s;
        if (s == "IN") {
            int b;
            cin >> b;
            isleaf[i] = 1;
            bitdefault[i] = b;
        } else {
            if (s == "AND") state[i] = AND;
            if (s == "OR") state[i] = OR;
            if (s == "XOR") state[i] = XOR;
            if (s == "NOT") state[i] = NOT;
            REP(t, 2) {
                int c;
                cin >> c;
                c--;
                ch[i].push_back(c);
                if (s == "NOT") break;
            }
        }
    }
    auto rec = [&](auto &&self, int now) -> void {
        if (isleaf[now]) return;
        for (auto nxt : ch[now]) self(self, nxt);

        if (state[now] == AND) {
            bitdefault[now] = 1;
            for (auto nxt : ch[now]) {
                bitdefault[now] &= bitdefault[nxt];
            }
        }
        if (state[now] == OR) {
            bitdefault[now] = 0;
            for (auto nxt : ch[now]) {
                bitdefault[now] |= bitdefault[nxt];
            }
        }
        if (state[now] == NOT) {
            for (auto nxt : ch[now]) {
                bitdefault[now] = !bitdefault[nxt];
            }
        }
        if (state[now] == XOR) {
            for (auto nxt : ch[now]) bitdefault[now] ^= bitdefault[nxt];
        }
    };
    rec(rec, 0);
    dbg(isleaf);
    dbg(bitdefault);

    vector<int> is_relevant(N);
    is_relevant[0] = 1;
    auto rec2 = [&](auto &&self, int now) -> void {
        if (state[now] == AND) {
            if (bitdefault[now] == 1) {
                for (auto nxt : ch[now]) {
                    is_relevant[nxt] = 1;
                }
            } else {
                int n1 = 0;
                for (auto c : ch[now]) n1 += bitdefault[c];
                if (n1 == 1) for (auto c : ch[now]) if (bitdefault[c] == 0) is_relevant[c] = 1;
            }
        } else if (state[now] == OR) {
            if (bitdefault[now] == 0) {
                for (auto nxt : ch[now]) is_relevant[nxt] = 1;
            } else {
                int n1 = 0;
                for (auto c : ch[now]) n1 += bitdefault[c];
                if (n1 == 1) for (auto c : ch[now]) if (bitdefault[c] == 1) is_relevant[c] = 1;
            }
        } else {
            for (auto nxt : ch[now]) is_relevant[nxt] = 1;
        }
        for (auto nxt : ch[now]) if (is_relevant[nxt]) self(self, nxt);
    };
    rec2(rec2, 0);
    dbg(is_relevant);
    string ret;
    REP(i, N) {
        if (isleaf[i]) {
            int r = bitdefault[0];
            if (is_relevant[i]) r ^= 1;
            ret += (char)('0' + r);
        }
    }
    cout << ret << '\n';
}