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

// Cartesian tree
// Complexity: O(n)
// By default, the smaller node is nearer to the root
// Return : -1 (root), parent_idx (otherwise)
// Example: [1, 0, 2] => [1, -1, 1]
// Verified: https://judge.yosupo.jp/problem/cartesian_tree
template <class T, class Cmp = std::less<T>>
auto cartesian_tree(const std::vector<T> &X) {
    const int n = X.size();
    Cmp comp;
    std::vector<int> st(n);
    int sz = 0;

    std::vector<int> par(n, -1);

    for (int i = 0; i < n; ++i) {
        while (sz >= 2 and comp(X[i], X[st[sz - 1]])) {
            par[st[sz - 1]] = comp(X[i], X[st[sz - 2]]) ? st[sz - 2] : i;
            --sz;
        }
        if (sz == 1 and comp(X[i], X[st[sz - 1]])) par[st[--sz]] = i;
        st[sz++] = i;
    }
    for (; sz > 1; --sz) par[st[sz - 1]] = st[sz - 2];

    int root = -1;
    std::vector<std::vector<int>> to(n);
    for (int i = 0; i < n; ++i) {
        if (par[i] < 0) {
            root = i;
        } else {
            to[par[i]].push_back(i);
        }
    }

    struct tree {
        int root;
        std::vector<int> par;
        std::vector<std::vector<int>> to;
    };
    return tree{root, par, to};
};


int main() {
    int N;
    lint M;
    cin >> N >> M;
    vector<lint> A(N);
    cin >> A;
    auto tree = cartesian_tree(A);
    const auto &to = tree.to;
    const int root = tree.root;

    vector<vector<lint>> dp(N);
    vector<lint> sz(N);
    constexpr lint INF = 1LL << 60;
    auto rec = [&](auto &&self, int now) -> void {
        sz[now] = 1;
        for (auto nxt : to[now]) {
            self(self, nxt);
            sz[now] += sz[nxt];
        }

        dp[now].assign(sz[now] + 1, -INF);
        vector<lint> dpl{0}, dpr{0};

        if (to[now].empty()) {
        } else if (to[now].size() == 1) {
            dpl = dp[to[now][0]];
        } else if (to[now].size() == 2) {
            dpl = dp[to[now][0]];
            dpr = dp[to[now][1]];
        } else {
            throw;
        }
        REP(i, dpl.size()) REP(j, dpr.size()) {
            chmax(dp[now][i + j], dpl[i] + dpr[j] - A[now] * i * j * 2);
            chmax(dp[now][i + j + 1], dpl[i] + dpr[j] + M * A[now] - lint(A[now]) * (i * j * 2 + 1 + i * 2 + j * 2));
        }

        for (auto nxt : to[now]) dp[nxt].clear();
    };
    rec(rec, root);
    cout << dp[root][M] << '\n';
}