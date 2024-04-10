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

vector<vector<int>> status_h, status_w;

const lint bias = 1000000LL;
lint dist(int x, int y, int x2, int y2) {
    if (y < y2) return 1 + bias * status_w[x][y];
    if (y > y2) return 1 + bias * status_w[x][y2];
    if (x < x2) return 1 + bias * status_h[x][y];
    if (x > x2) return 1 + bias * status_h[x2][y];
    throw;
}

template <typename T_E, T_E INF, T_E (*edge_cost)(int, int, int, int)> struct GridGraph {
    const int H, W;
    const std::vector<int> dx{1, -1, 0, 0};
    const std::vector<int> dy{0, 0, 1, -1};

    GridGraph() = default;
    GridGraph(int h, int w) : H(h), W(w) {}

    // Dijkstra's algorithm
    // Complexity: O(HWlog(HW))
    std::vector<std::vector<T_E>> dist;                // Distance from (x_s, y_s)
    std::vector<std::vector<std::pair<int, int>>> prv; // Previous node for Dijkstra optimal path
    void dijkstra(int x_s, int y_s) {
        dist.assign(H, std::vector<T_E>(W, INF));
        prv.assign(H, std::vector<std::pair<int, int>>(W, std::make_pair(-1, -1)));

        using P = std::tuple<T_E, int, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        dist[x_s][y_s] = 0;
        pq.emplace(0, x_s, y_s);
        while (!pq.empty()) {
            T_E dnow;
            int x, y;
            std::tie(dnow, x, y) = pq.top();
            pq.pop();
            if (dist[x][y] < dnow) continue;
            for (unsigned d = 0; d < dx.size(); d++) {
                int xn = x + dx[d], yn = y + dy[d];
                if (xn < 0 or yn < 0 or xn >= H or yn >= W) continue;
                T_E dnxt = dnow + edge_cost(x, y, xn, yn);
                if (dnxt < dist[xn][yn]) {
                    dist[xn][yn] = dnxt;
                    prv[xn][yn] = std::make_pair(x, y);
                    pq.emplace(dnxt, xn, yn);
                }
            }
        }
    }

    void bfs_01(int x_s, int y_s) {
        dist.assign(H, std::vector<T_E>(W, INF));
        prv.assign(H, std::vector<std::pair<int, int>>(W, std::make_pair(-1, -1)));
        std::deque<std::pair<int, int>> deq;
        dist[x_s][y_s] = 0;
        deq.emplace_back(x_s, y_s);
        while (!deq.empty()) {
            int x, y;
            std::tie(x, y) = deq.front();
            const auto dnow = dist[x][y];
            deq.pop_front();
            for (unsigned d = 0; d < dx.size(); d++) {
                int xn = x + dx[d], yn = y + dy[d];
                if (xn < 0 or yn < 0 or xn >= H or yn >= W) continue;
                auto dnxt = dnow + edge_cost(x, y, xn, yn);
                if (dnxt < dist[xn][yn]) {
                    dist[xn][yn] = dnxt;
                    prv[xn][yn] = std::make_pair(x, y);
                    if (dnxt)
                        deq.emplace_back(xn, yn);
                    else
                        deq.emplace_front(xn, yn);
                }
            }
        }
    }
};


lint solve() {
    int N, K;
    cin >> N >> K;
    int dim = K + 1;
    status_h.assign(dim, vector<int>(dim));
    status_w.assign(dim, vector<int>(dim));

    auto mirror = [&](pint p) {
        return make_pair(K - 1, K - 1) - p;
    };

    REP(t, N) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b, --c, --d;
        pint p{a, b}, q{c, d};

        REP(t, 2) {
            if (p > q) swap(p, q);
            if (p.first < q.first) {
                status_w[q.first][q.second]++;
            } else {
                assert(p.second < q.second);
                status_h[q.first][q.second]++;
            }

            p = mirror(p), q = mirror(q);
        }
    }
    dbg(status_h);
    dbg(status_w);
    constexpr lint INF = 1LL << 60;
    GridGraph<lint, INF, dist> graph(dim, dim);
    graph.dijkstra(0, 0);
    lint cost = graph.dist[K / 2][K / 2] / bias;
    if (cost == INF) {
        return -1;
    } else {
        return N - cost;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}