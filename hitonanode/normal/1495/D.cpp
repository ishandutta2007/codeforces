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

template <int mod> struct ModInt {
#if __cplusplus >= 201402L
#define MDCONST constexpr
#else
#define MDCONST
#endif
    using lint = long long;
    MDCONST static int get_mod() { return mod; }
    static int get_primitive_root() {
        static int primitive_root = 0;
        if (!primitive_root) {
            primitive_root = [&]() {
                std::set<int> fac;
                int v = mod - 1;
                for (lint i = 2; i * i <= v; i++)
                    while (v % i == 0) fac.insert(i), v /= i;
                if (v > 1) fac.insert(v);
                for (int g = 1; g < mod; g++) {
                    bool ok = true;
                    for (auto i : fac)
                        if (ModInt(g).pow((mod - 1) / i) == 1) {
                            ok = false;
                            break;
                        }
                    if (ok) return g;
                }
                return -1;
            }();
        }
        return primitive_root;
    }
    int val;
    MDCONST ModInt() : val(0) {}
    MDCONST ModInt &_setval(lint v) { return val = (v >= mod ? v - mod : v), *this; }
    MDCONST ModInt(lint v) { _setval(v % mod + mod); }
    MDCONST explicit operator bool() const { return val != 0; }
    MDCONST ModInt operator+(const ModInt &x) const { return ModInt()._setval((lint)val + x.val); }
    MDCONST ModInt operator-(const ModInt &x) const { return ModInt()._setval((lint)val - x.val + mod); }
    MDCONST ModInt operator*(const ModInt &x) const { return ModInt()._setval((lint)val * x.val % mod); }
    MDCONST ModInt operator/(const ModInt &x) const { return ModInt()._setval((lint)val * x.inv() % mod); }
    MDCONST ModInt operator-() const { return ModInt()._setval(mod - val); }
    MDCONST ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    MDCONST ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    MDCONST ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    MDCONST ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    friend MDCONST ModInt operator+(lint a, const ModInt &x) { return ModInt()._setval(a % mod + x.val); }
    friend MDCONST ModInt operator-(lint a, const ModInt &x) { return ModInt()._setval(a % mod - x.val + mod); }
    friend MDCONST ModInt operator*(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.val % mod); }
    friend MDCONST ModInt operator/(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.inv() % mod); }
    MDCONST bool operator==(const ModInt &x) const { return val == x.val; }
    MDCONST bool operator!=(const ModInt &x) const { return val != x.val; }
    MDCONST bool operator<(const ModInt &x) const { return val < x.val; } // To use std::map<ModInt, T>
    friend std::istream &operator>>(std::istream &is, ModInt &x) {
        lint t;
        return is >> t, x = ModInt(t), is;
    }
    MDCONST friend std::ostream &operator<<(std::ostream &os, const ModInt &x) { return os << x.val; }
    MDCONST ModInt pow(lint n) const {
        lint ans = 1, tmp = this->val;
        while (n) {
            if (n & 1) ans = ans * tmp % mod;
            tmp = tmp * tmp % mod, n /= 2;
        }
        return ans;
    }

    static std::vector<long long> facs, invs;
    MDCONST static void _precalculation(int N) {
        int l0 = facs.size();
        if (N <= l0) return;
        facs.resize(N), invs.resize(N);
        for (int i = l0; i < N; i++) facs[i] = facs[i - 1] * i % mod;
        long long facinv = ModInt(facs.back()).pow(mod - 2).val;
        for (int i = N - 1; i >= l0; i--) {
            invs[i] = facinv * facs[i - 1] % mod;
            facinv = facinv * i % mod;
        }
    }
    MDCONST lint inv() const {
        if (this->val < 1 << 20) {
            while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
            return invs[this->val];
        } else {
            return this->pow(mod - 2).val;
        }
    }
    MDCONST ModInt fac() const {
        while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
        return facs[this->val];
    }

    MDCONST ModInt doublefac() const {
        lint k = (this->val + 1) / 2;
        return (this->val & 1) ? ModInt(k * 2).fac() / (ModInt(2).pow(k) * ModInt(k).fac()) : ModInt(k).fac() * ModInt(2).pow(k);
    }
    MDCONST ModInt nCr(const ModInt &r) const { return (this->val < r.val) ? 0 : this->fac() / ((*this - r).fac() * r.fac()); }

    ModInt sqrt() const {
        if (val == 0) return 0;
        if (mod == 2) return val;
        if (pow((mod - 1) / 2) != 1) return 0;
        ModInt b = 1;
        while (b.pow((mod - 1) / 2) == 1) b += 1;
        int e = 0, m = mod - 1;
        while (m % 2 == 0) m >>= 1, e++;
        ModInt x = pow((m - 1) / 2), y = (*this) * x * x;
        x *= (*this);
        ModInt z = b.pow(m);
        while (y != 1) {
            int j = 0;
            ModInt t = y;
            while (t != 1) j++, t *= t;
            z = z.pow(1LL << (e - j - 1));
            x *= z, z *= z, y *= z;
            e = j;
        }
        return ModInt(std::min(x.val, mod - x.val));
    }
};
template <int mod> std::vector<long long> ModInt<mod>::facs = {1};
template <int mod> std::vector<long long> ModInt<mod>::invs = {0};
using mint = ModInt<998244353>;


template <typename T, T INF = std::numeric_limits<T>::max() / 2, int INVALID = -1> struct ShortestPath {
    int V, E;
    bool single_positive_weight;
    T wmin, wmax;
    std::vector<std::vector<std::pair<int, T>>> to;

    ShortestPath(int V = 0) : V(V), E(0), single_positive_weight(true), wmin(0), wmax(0), to(V) {}
    void add_edge(int s, int t, T w) {
        assert(0 <= s and s < V);
        assert(0 <= t and t < V);
        to[s].emplace_back(t, w);
        E++;
        if (w > 0 and wmax > 0 and wmax != w) single_positive_weight = false;
        wmin = std::min(wmin, w);
        wmax = std::max(wmax, w);
    }

    std::vector<T> dist;
    std::vector<int> prev;

    // Dijkstra algorithm
    // Complexity: O(E log E)
    void Dijkstra(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF);
        dist[s] = 0;
        prev.assign(V, INVALID);
        using P = std::pair<T, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        pq.emplace(0, s);
        while (!pq.empty()) {
            T d;
            int v;
            std::tie(d, v) = pq.top();
            pq.pop();
            if (dist[v] < d) continue;
            for (auto nx : to[v]) {
                T dnx = d + nx.second;
                if (dist[nx.first] > dnx) {
                    dist[nx.first] = dnx, prev[nx.first] = v;
                    pq.emplace(dnx, nx.first);
                }
            }
        }
    }
};


int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> to(N);
    ShortestPath<int> graph(N);
    REP(e, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        to[a].push_back(b), to[b].push_back(a);
        graph.add_edge(a, b, 1);
        graph.add_edge(b, a, 1);
    }

    vector ret(N, vector<mint>(N, 0));
    vector<vector<int>> dij(N);

    REP(i, N) {
        graph.Dijkstra(i);
        dij[i] = graph.dist;
    }

    REP(x, N) {
        const vector<int> depth = dij[x];
        vector<int> income(N);
        vector<int> prv(N, -1);
        REP(i, N) {
            for (auto j : to[i]) {
                if (depth[j] <= depth[i]) income[i]++, prv[i] = j;
            }
            if (income[i] != 1) prv[i] = -1;
        }

        REP(y, N) {
            int now = y;
            bool ok = true;
            vector<int> skip(N);
            while ((now != x) and ok) {
                skip[now] = 1;
                if (prv[now] < 0) {
                    ok = false;
                } else {
                    now = prv[now];
                }
            }
            if (!ok) continue;


            vector<mint> deg(N);
            REP(i, N) for (auto j : to[i]) {
                if (dij[x][j] < dij[x][i] and dij[y][j] < dij[y][i]) deg[i] += 1;
            }

            mint tmp = 1;

            REP(i, N) if (i != x and i != y and !skip[i]) tmp *= deg[i];

            ret[x][y] = tmp;
        }
    }

    for (auto v : ret) {
        for (auto x : v) cout << x << ' ';
        cout << '\n';
    }
}