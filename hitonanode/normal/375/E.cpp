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
#define dbg(x) (x)
#endif

struct rand_int_ {
    using lint = long long;
    mt19937 mt;
    rand_int_() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } // [0, x)
    lint operator()(lint l, lint r) {
        uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;


int main() {
    int N, X;
    cin >> N >> X;
    const int root = rnd(N);
    vector<vector<pint>> to(N);
    vector<int> C(N);
    cin >> C;
    REP(i, N - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        to[u].emplace_back(v, w);
        to[v].emplace_back(u, w);
    }

    constexpr lint INF = 1LL << 40;

    vector<int> stsz(N);

    auto dfsst = [&](auto &self, int now, int prv) -> int {
        int ret = 1;
        for (auto [nxt, w] : to[now]) if (nxt != prv) ret += self(self, nxt, now);
        return stsz[now] = ret;
    };
    dfsst(dfsst, root, -1);

    auto dfs = [&](auto &&self, int now, int prv) -> vector<vector<lint>> {
        // dp[#b->r][#r->b] 
        vector dp(2, vector<lint>(2, -INF));
        if (C[now]) {
            dp[0][0] = X;
            dp[1][0] = -1;
        } else {
            dp[0][0] = -1;
            dp[0][1] = X;
        }
        vector<tuple<int, int, int>> sz2ch;
        for (auto [nxt, w] : to[now]) if (nxt != prv) sz2ch.emplace_back(stsz[nxt], nxt, w);
        sort(ALL(sz2ch));
        for (auto [sz, nx, w] : sz2ch) {
            vector<vector<lint>> ch = self(self, nx, now);
            vector nxt(dp.size() + ch.size() - 1, vector<lint>(dp[0].size() + ch[0].size() - 1, -INF));
            REP(i, dp.size()) REP(j, dp[i].size()) if (dp[i][j] > -INF) {
                REP(k, ch.size()) REP(l, ch[k].size()) if (ch[k][l] > -INF) {
                    auto &nx = nxt[i + k][j + l];
                    if (dp[i][j] < 0) {
                        if (ch[k][l] - w >= abs(dp[i][j]) - 1) {
                            chmax(nx, ch[k][l] - w);
                        } else if (ch[k][l] >= 0) {
                            chmax(nx, dp[i][j]);
                        } else {
                            chmax(nx, min(dp[i][j], ch[k][l] - w));
                        }
                    } else {
                        if (ch[k][l] >= 0) {
                            chmax(nx, max(dp[i][j], ch[k][l] - w));
                        } else if (dp[i][j] + (ch[k][l] - w) >= -1) {
                            chmax(nx, dp[i][j]);
                        } else {
                            chmax(nx, ch[k][l] - w);
                        }
                    }
                }
            }
            dp = nxt;
            if (dp.size() > N / 2 + 1) {
                dp.resize(N / 2 + 1);
                for (auto &v : dp) v.resize(N / 2 + 1);
            }
        }
        return dp;
    };

    auto dp = dfs(dfs, root, -1);
    lint ret = INF;
    REP(i, dp.size()) REP(j, dp[i].size()) {
        if (i == j and dp[i][j] >= 0) chmin<lint>(ret, i);
    }
    cout << (ret == INF ? -1 : ret) << '\n';
}