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

vector<int> calcvs(const string &S) {
    vector<int> cnt(4);
    REP(j, S.size() / 2) {
        int a = (S[j * 2] - '0') * 2 + (S[j * 2 + 1] - '0');
        cnt[a]++;
    }
    return cnt;
}
vector<int> calcvt(const string &T) {
    auto v = calcvs(T);
    swap(v[1], v[2]);
    return v;
}

vector<int> solve(string S, string T) {
    int m = S.size() / 2;
    vector<int> ret;
    vector<int> cnts = calcvs(S), cntt = calcvt(T);

    if (cnts[0] != cntt[0] or cnts[3] != cntt[3]) return {-1};

    auto do_rev = [&](int i) {
        if (i <= 0) return;
        if (ret.size() and ret.back() == i) {
            ret.pop_back();
        } else {
            ret.push_back(i);
        }
        reverse(S.begin(), S.begin() + i);
    };

    if (cnts != cntt) {
        int cum = cnts[1];
        map<int, int> mp;
        mp[cum] = 0;
        REP(j, m) {
            int a = (S[j * 2] - '0') * 2 + (S[j * 2 + 1] - '0');
            if (a == 1) cum--;
            if (a == 2) cum++;
            mp[cum] = (j + 1) * 2;
        }
        cum = cntt[1];
        if (mp.count(cum)) {
            reverse(S.begin(), S.begin() + mp[cum]);
            auto v = solve(S, T);
            if (mp[cum]) v.insert(v.begin(), mp[cum]);
            return v;
        }
        mp.clear();
        mp[cum] = 0;
        REP(j, m) {
            int b = (T[j * 2] - '0') + (T[j * 2 + 1] - '0') * 2;
            if (b == 1) cum--;
            if (b == 2) cum++;
            mp[cum] = (j + 1) * 2;
        }
        cum = cnts[1];
        if (mp.count(cum)) {
            reverse(T.begin(), T.begin() + mp[cum]);
            auto v = solve(S, T);
            if (mp[cum]) v.push_back(mp[cum]);
            return v;
        }
        exit(9);
    }
    REP(i, m) {
        int j = i * 2;
        while (T[S.size() - (i + 1) * 2] != S[j + 1] or T[S.size() - (i + 1) * 2 + 1] != S[j]) j += 2;
        do_rev(j);
        do_rev(j + 2);
    }
    assert(S == T);
    return ret;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S, T;
        cin >> S >> T;
        auto ret = solve(S, T);
        int i = 0;
        while (i + 1 < int(ret.size())) {
            if (ret[i] == ret[i + 1]) {
                ret.erase(ret.begin() + i);
                ret.erase(ret.begin() + i);
            } else {
                i++;
            }
        }
        if (ret.size() and ret[0] < 0) {
            cout << "-1\n";
        } else {
            cout << ret.size() << '\n';
            for (auto x : ret) cout << x << ' ';
            cout << '\n';
        }
    }
}