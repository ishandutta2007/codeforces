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

// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind {
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<int> dir(N);
    vector<int> v2e(N * 2);
    REP(e, N) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        dir[e] = a < b;
        if (a < N and b < N) {
            puts("-1");
            return 0;
        }
        if (a > b) swap(a, b);
        A[e] = a, B[e] = b;
        v2e[a] = v2e[b] = e;
    }

    vector<int> exists_smaller(N);
    vector<int> exists_greater(N);
    stack<pint, vector<pint>> st;
    REP(x, v2e.size()) {
        int e = v2e[x];
        int a = A[e], b = B[e];
        if (x == b) {
            while (st.size()) {
                auto [f, y] = st.top();
                if (y < a) break;
                st.pop();
                if (y > a) exists_greater[f] = 1;
            }
        } else {
            st.emplace(e, x);
        }
    }
    while (st.size()) st.pop();
    IREP(x, v2e.size()){
        int e = v2e[x];
        int a = A[e], b = B[e];
        if (x == a) {
            while (st.size()) {
                auto [f, y] = st.top();
                if (y > b) break;
                st.pop();
                if (y < b) exists_smaller[f] = 1;
            }
        } else {
            st.emplace(e, x);
        }
    }
    REP(i, N) {
        if (exists_greater[i] and exists_smaller[i]) {
            puts("-1");
            return 0;
        }
    }
    dbg(exists_smaller);
    dbg(exists_greater);

    UnionFind uf(N * 2);
    REP(i, N) uf.cou[i] = dir[i];
    REP(i, N) uf.cou[i + N] = !dir[i];

    stack<int, vector<int>> edges;

    vector<int> erased_edges(N);
    REP(x, v2e.size()) {
        int e = v2e[x];
        int a = A[e], b = B[e];
        if (erased_edges[e]) continue;
        if (x == b) {
            int rightest_edge = -1;
            while (true) {
                auto f = edges.top();
                edges.pop();
                erased_edges[f] = 1;
                if (f == e) break;
                uf.unite(f, e + N);
                uf.unite(e, f + N);
                if (rightest_edge < 0 or B[rightest_edge] < B[f]) rightest_edge = f;
            }
            if (rightest_edge >= 0) {
                edges.push(rightest_edge);
                erased_edges[rightest_edge] = false;
            }
        } else {
            edges.push(e);
        }
    }
    vector<int> seen_root(N * 2);
    int ret = 0;
    REP(i, N) {
        if (uf.same(i, i + N)) {
            puts("-1");
            return 0;
        }
        auto r = uf.find(i);
        if (!seen_root[r]) ret += min(uf.count(i), uf.count(i + N));
        seen_root[uf.find(i)] = seen_root[uf.find(i + N)] = 1;
    }
    cout << ret << '\n';
}