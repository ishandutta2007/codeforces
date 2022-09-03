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

struct custom_hash
{
    // <https://codeforces.com/blog/entry/62393>
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// using us = gp_hash_table<int, null_type, custom_hash>;

template <typename Container>
void anscq(const Container &v) {
    cout << 2 << '\n';
    for (auto x : v) cout << x + 1 << ' ';
    cout << '\n';
}

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    using us = gp_hash_table<int, null_type, custom_hash>;
    gp_hash_table<lint, null_type, custom_hash> edges;
    vector<us> to(N);
    REP(_, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a > b) swap(a, b);
        edges.insert((lint(a) << 32) + b);
        to[a].insert(b), to[b].insert(a);
    }

    if (1LL * K * (K - 1) / 2 > M) {
        cout << -1 << '\n';
        return;
    }

    vector<us> qcands;

    {
        queue<int> q_th, q_less;
        vector<int> ex(N, 1);

        auto ch = [&](int i) {
            if (ex[i]) {
                if (to[i].size() < K - 1) { q_less.emplace(i), ex[i] = 0; }
                if (to[i].size() == K - 1) { q_th.emplace(i), ex[i] = 0; }
            }
        };

        REP(i, N) ch(i);

        while (true) {
            if (q_less.size()) {
                int now = q_less.front();
                q_less.pop();
                for (auto nxt : to[now]) { to[nxt].erase(now), ch(nxt); }
                to[now].clear();
            } else if (q_th.size()) {
                int now = q_th.front();
                q_th.pop();
                if (to[now].size() < K - 1) {
                    q_less.emplace(now);
                    continue;
                }
                qcands.emplace_back(to[now]);
                qcands.back().insert(now);
                for (auto nxt : to[now]) { to[nxt].erase(now), ch(nxt); }
                to[now].clear();
            } else
                break;
        }

        REP(i, N) if (ex[i]) {
            UnionFind uf(N);
            for (auto p : edges) {
                lint a = p >> 32, b = p - (a << 32);
                if (ex[a] and ex[b]) uf.unite(a, b);
            }
            vector<int> ret;
            REP(j, N) {
                if (uf.same(i, j)) ret.emplace_back(j);
            }
            cout << "1 " << ret.size() << '\n';
            for (auto x : ret) cout << x + 1 << ' ';
            cout << '\n';
            return;
        }
    }

    if (K < 300) {
        for (auto vec : qcands) {
            bool flg = true;
            vector<int> ve(vec.begin(), vec.end());
            int S = vec.size();
            REP(i, S) {
                FOR(j, i + 1, S) {
                    lint a = ve[i], b = ve[j];
                    if (a > b) swap(a, b);
                    if (edges.find((a << 32) + b) == edges.end()) {
                        flg = false;
                        break;
                    }
                }
                if (!flg) { break; }
            }
            if (flg) {
                anscq(vec);
                return;
            }
        }
    } else {
        int Q = qcands.size();
        vector<int> nb_e(Q);
        for (auto p : edges) {
            lint a = p >> 32, b = p - (a << 32);
            REP(q, Q) {
                if (qcands[q].find(a) != qcands[q].end() and qcands[q].find(b) != qcands[q].end()) nb_e[q]++;
            }
        }
        REP(q, nb_e.size()) {
            if (nb_e[q] == lint(K) * (K - 1) / 2) {
                anscq(qcands[q]);
                return;
            }
        }
    }
    cout << "-1\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}