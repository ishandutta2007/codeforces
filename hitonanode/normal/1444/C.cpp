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
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
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
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

// UnionFind, able to rewind to the previous state by undo()
// Written for Educational Codeforces 62 F, although not verified yet.
struct UndoSizeAwareUnionFind
{
    using pint = std::pair<int, int>;
    std::vector<int> par, cou;
    std::stack<std::pair<int, pint>> history;
    UndoSizeAwareUnionFind(int N) : par(N), cou(N, 1) {
        std::iota(par.begin(), par.end(), 0);
    }
    int find(int x) { return (par[x] == x) ? x :find(par[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (cou[x] < cou[y]) std::swap(x, y);
        history.emplace(y, pint(par[y], cou[x]));
        if (x != y) par[y] = x, cou[x] += cou[y];
    }
    void undo() {
        cou[par[history.top().first]] = history.top().second.second;
        par[history.top().first] = history.top().second.first;
        history.pop();
    }
    void reset() {
        while (!history.empty()) undo();
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

int main()
{
    lint N, M, K;
    cin >> N >> M >> K;
    vector<int> C(N);
    cin >> C;
    vector<vector<int>> C2i(K);
    REP(i, N) {
        C[i]--;
        C2i[C[i]].emplace_back(i);
    }
    UndoSizeAwareUnionFind uf(N * 2);
    map<pint, vector<pint>> c2e;
    REP(_, M)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (C[a] > C[b]) swap(a, b);

        if (C[a] == C[b]) {
            uf.unite(a, b + N);
            uf.unite(b, a + N);
        } else {
            c2e[pint(C[a], C[b])].emplace_back(a, b);
        }
    }
    vector<int> ok_clr(K, 1);
    REP(k, K) {
        for (auto r : C2i[k]) {
            if (uf.same(r, r + N)) {
                ok_clr[k] = 0;
            }
        }
    }
    lint nok = accumulate(ALL(ok_clr), 0LL);
    lint nbad = 0;
    for (const auto [cacb, e] : c2e) {
        auto [ca, cb] = cacb;
        if (!ok_clr[ca] or !ok_clr[cb]) {
            continue;
        }
        bool flg = false;
        for (auto [a, b] : e) {
            uf.unite(a, b + N);
            uf.unite(b, a + N);
            if (uf.same(a, a + N) or uf.same(b, b + N)) flg = true;
        }
        REP(_, e.size()) {
            uf.undo();
            uf.undo();
        }
        nbad += flg;
    }
    cout << nok * (nok - 1) / 2 - nbad << '\n';
}