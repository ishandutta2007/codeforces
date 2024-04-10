#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template <typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template <typename V, typename T> void ndfill(V &x, const T &val) { x = val; }
template <typename V, typename T> void ndfill(vector<V> &vec, const T &val) { for (auto &v : vec) ndfill(v, val); }
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
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
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

// // Usage
// #include <unordered_map>
// unordered_map<int, int, custom_hash> robust_unordered_map;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, null_type, custom_hash> robust_hash_table; // fast unordered_set / unordered_map
gp_hash_table<lint, int, custom_hash> fast_map; // fast unordered_set / unordered_map

struct rand_int_
{
    using lint = long long;
    mt19937 mt;
    rand_int_() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } // [0, x)
    lint operator()(lint l, lint r) {
        uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;
// Rolling Hash (Rabin-Karp), 1dim
template<typename V>
struct rolling_hash
{
    V B;
    vector<V> hash; // hash[i] = s[0] * B^(i - 1) + ... + s[i - 1]
    vector<V> power; // power[i] = B^i
    rolling_hash() {}
    rolling_hash(const string &s, V b) : B(b)
    {
        int N = s.length();
        hash.resize(N + 1), power.resize(N + 1, 1);
        for (int i = 0; i < N; i++)
        {
            power[i + 1] = power[i] * B;
            hash[i + 1] = hash[i] * B + s[i];
        }
    }
    V get_hash(int l, int r) // s[l] * B^(r - l - 1) + ... + s[r - 1]
    {
        return hash[r] - hash[l] * power[r - l];
    }
};

using lint = long long;
using plint = pair<lint, lint>;
struct DoubleHash : public plint
{
    static plint MODs;
    DoubleHash(plint x) : plint(x) {}
    DoubleHash(lint x, lint y) : plint(x, y) {}
    DoubleHash(lint x) : DoubleHash(x, x) {}
    DoubleHash() : DoubleHash(0) {}
    static inline DoubleHash mod_subtract(plint x)
    {
        if (x.first >= MODs.first) x.first -= MODs.first;
        if (x.second >= MODs.second) x.second -= MODs.second;
        return x;
    }
    DoubleHash operator+(const DoubleHash &x) const
    {
        return mod_subtract(plint(this->first + x.first, this->second + x.second));
    }
    DoubleHash operator+(lint x) const
    {
        return mod_subtract(plint(this->first + x, this->second + x));
    }
    DoubleHash operator-(const DoubleHash &x) const
    {
        return mod_subtract(plint(this->first - x.first + MODs.first, this->second - x.second + MODs.second));
    }
    DoubleHash operator*(const DoubleHash &x) const
    {
        return make_pair(this->first * x.first % MODs.first, this->second * x.second % MODs.second);
    }
    DoubleHash operator*(lint x) const
    {
        return make_pair(this->first * x % MODs.first, this->second * x % MODs.second);
    }
};
plint DoubleHash::MODs = plint(1000000007, 998244353);

// Count elements in [A_begin, ..., A_{end-1}] which satisfy A_i < query
// Complexity: O(N log^2 N) for initialization, O(log^2 N) for each query
// Verified: cntLess <https://codeforces.com/contest/1288/submission/68865506>
struct CountLessThan
{
    using T = int;
    int N;
    int head;
    vector<vector<T>> x;
    inline void merge(int pos) {
        x[pos] = x[pos * 2 + 1];
        x[pos].insert(x[pos].end(), x[pos * 2 + 2].begin(), x[pos * 2 + 2].end());
        sort(x[pos].begin(), x[pos].end());
    }
    int _getless(int begin, int end, int pos, int l, int r, T query) const {
        if (r <= begin or l >= end) return 0;
        if (l >= begin and r <= end) return lower_bound(x[pos].begin(), x[pos].end(), query) - x[pos].begin();
        return _getless(begin, end, 2 * pos + 1, l, (l + r) / 2, query) + _getless(begin, end, 2 * pos + 2, (l + r) / 2, r, query);
    }
    int _getlesseq(int begin, int end, int pos, int l, int r, T query) const {
        if (r <= begin or l >= end) return 0;
        if (l >= begin and r <= end) return upper_bound(x[pos].begin(), x[pos].end(), query) - x[pos].begin();
        return _getlesseq(begin, end, 2 * pos + 1, l, (l + r) / 2, query) + _getlesseq(begin, end, 2 * pos + 2, (l + r) / 2, r, query);
    }
    CountLessThan() = default;
    CountLessThan(const vector<T> &vec) : N(vec.size()) {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.resize(N_tmp*2), head = N_tmp - 1;
        for (int i = 0; i < N; i++) x[head + i] = {vec[i]};
        for (int i = head - 1; i >= 0; i--) merge(i);
    }
    int cntLess(int begin, int end, T query) const { return _getless(begin, end, 0, 0, (int)x.size() / 2, query); }
    int cntLesseq(int begin, int end, T query) const { return _getlesseq(begin, end, 0, 0, (int)x.size() / 2, query); }
    int cntMore(int begin, int end, T query) const {
        int tot = max(0, min(end, N) - max(begin, 0));
        return tot - cntLesseq(begin, end, query);
    }
    int cntMoreeq(int begin, int end, T query) const {
        int tot = max(0, min(end, N) - max(begin, 0));
        return tot - cntLess(begin, end, query);
    }

    friend ostream &operator<<(ostream &os, const CountLessThan &clt) {
        os << '[';
        for (int i = 0; i < clt.N; i++) os << clt.x[clt.head + i][0] << ',';
        os << ']';
        return os;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<lint> C(N);
    cin >> C;
    string S;
    cin >> S;
    vector<vector<int>> to(N);
    REP(_, N - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        to[u].emplace_back(v);
        to[v].emplace_back(u);
    }

    vector<int> vin(N), vout(N);
    vector<lint> dh_seq;

    vector<DoubleHash> hst;
    DoubleHash b(rnd(1e5, 5e8), rnd(1e5, 5e8));

    hst.emplace_back(b);
    int t_now = 0;
    auto dfs = [&](auto &&dfs, int now, int prv) -> void {
        DoubleHash hnow = hst.back() * b + S[now];
        hst.emplace_back(hnow);

        vin[now] = t_now++;
        dh_seq.emplace_back((lint(hnow.first) << 31) + hnow.second);

        for (auto nxt : to[now]) if (nxt != prv)
        {
            dfs(dfs, nxt, now);
        }
        vout[now] = t_now;
        hst.pop_back();
    };
    dfs(dfs, 0, -1);

    vector<int> vec(dh_seq.size());
    IREP(i, dh_seq.size())
    {
        if (fast_map.find(dh_seq[i]) != fast_map.end())
        {
            vec[i] = fast_map[dh_seq[i]];
        }
        else vec[i] = dh_seq.size();
        fast_map[dh_seq[i]] = i;
    }

    CountLessThan segtree(vec);
    vector<lint> vals(N);
    REP(i, N)
    {
        vals[i] = C[i] + vout[i] - vin[i] - segtree.cntLess(vin[i], vout[i], vout[i]);
    }
    lint maxi = *max_element(vals.begin(), vals.end());
    lint nb_maxi = count_if(vals.begin(), vals.end(), [&](lint x) { return x == maxi; });
    cout << maxi << '\n' << nb_maxi << '\n';
}