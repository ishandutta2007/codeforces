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

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    cin >> S;

    int K = 0;
    vector<int> xv(8, -2), yv(8, -2);
    vector<pint> bombs;
    int gs = -1, gt = -1;
    int nv = 0;
    REP(i, H) REP(j, W) {
        if (isdigit(S[i][j]) or S[i][j] == 'B') {
            K++;
            if (S[i][j] == 'B') {
                bombs.emplace_back(i, j);
            } else {
                int d = S[i][j] - '1';
                xv[d] = i, yv[d] = j;
                nv++;
            }
        }
        if (S[i][j] == 'S') {
            gs = i, gt = j;
        }
    }
    xv.resize(nv), yv.resize(nv);
    vector<int> V(nv);
    cin >> V;

    V.resize(K, -2000);

    dbg(xv);
    dbg(yv);
    dbg(nv);
    dbg(V);
    dbg(K);
    dbg(bombs);

    while (bombs.size()) {
        xv.emplace_back(bombs.back().first);
        yv.emplace_back(bombs.back().second);
        bombs.pop_back();
    }

    vector to(H, vector(W, vector<tuple<int, int, int>>{}));
    array<int, 4> dx{1, -1, 0, 0};
    array<int, 4> dy{0, 0, 1, -1};
    REP(i, H) REP(j, W) {
        REP(d, dx.size()) {
            int nx = i + dx[d], ny = j + dy[d];
            if (nx < 0 or ny < 0 or nx >= H or ny >= W or S[nx][ny] == 'B') continue;
            if (isdigit(S[nx][ny])) continue;
            if (S[nx][ny] == '#') continue;
            int m = 0;
            REP(k, K) {
                if (j > yv[k] and (xv[k] < i) ^ (xv[k] < nx)) m ^= 1 << k;
            }
            to[i][j].emplace_back(nx, ny, m);
        }
    }

    constexpr int INF = 1;
    vector dp(H, vector(W, vector<short>(1 << K, INF)));
    dp[gs][gt][0] = 0;
    int ret = 0;

    vector<int> scores(1 << K);
    REP(s, 1 << K) {
        REP(i, K) if ((s >> i) & 1) scores[s] += V[i];
    }


    FOR(t, 1, 1602) {
        vector nxt(H, vector(W, vector<short>(1 << K, INF)));
        REP(i, H) REP(j, W) REP(s, 1 << K) if (dp[i][j][s] == 0) {
            for (auto [ni, nj, m] : to[i][j]) {
                nxt[ni][nj][s ^ m] = 0;
            }
        }
        dp = nxt;
        if (t % 2 == 0) {
            REP(s, 1 << K) if (dp[gs][gt][s] == 0) chmax(ret, scores[s] - t);
        }
    }
    cout << ret << '\n';
}