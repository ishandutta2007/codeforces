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

lint solve() {
    int N;
    lint A, B, C;
    cin >> N >> A >> B >> C;
    string S;
    cin >> S;
    N = S.size();

    dbg(S);
    int n11 = 0, n00 = 0, n0 = count(ALL(S), '0');
    REP(i, N - 1) {
        if (S[i] == '1' and S[i + 1] == '1') n11++;
        if (S[i] == '0' and S[i + 1] == '0') n00++;
    }
    dbg(n0);
    dbg(n11);
    dbg(n00);
    int last1 = -1;
    vector<int> d1s;
    REP(i, N) {
        if (S[i] == '1') {
            if (last1 >= 0) {
                int d = i - last1;
                if (d >= 2) d1s.push_back(d - 2);
            }
            last1 = i;
        }
    }
    dbg(d1s);
    sort(d1s.begin(), d1s.end());
    vector<lint> d1scs(d1s.size() + 1);
    FOR(i, 1, d1scs.size()) {
        d1scs[i] = d1scs[i - 1] + d1s.at(i - 1);
    }
    dbg(d1scs);
    lint ret = 0;
    REP(n1del, N) {
        if (n1del > n11) {
            int req_join = n1del - n11;
            if (req_join >= int(d1scs.size())) continue;
            int req_0_turn = req_join + d1scs[req_join];
            int req_c = req_join, req_a = d1scs[req_join];
            // lint add_0_val = -req_join * C + A * d1scs[req_join];
            FOR(n0del, n1del - 1, n1del + 2) {
                if (n0del < 0 or n0del > n0) continue;
                if (req_0_turn > n0del) continue;
                if (req_c + req_a > n1del) continue;
                int nc = req_c, na = req_a;
                int can_add_a = min(n0del - na - nc, n00 - na);
                if (can_add_a < 0) continue;
                na += can_add_a;
                nc = n0del - na;
                if (chmax(ret, n1del * B + na * A - nc * C)) {
                    dbg((vector<lint>{ret, n1del, na, nc}));
                }
            }
        } else {
            FOR(n0del, n1del - 1, n1del + 2) {
                if (n0del < 0 or n0del > n0) continue;
                chmax(ret, n1del * B + min(n00, n0del) * A - max(0, n0del - n00) * C);
            }
        }
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