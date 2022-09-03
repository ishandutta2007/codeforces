#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////


// Solve ax+by=gcd(a, b)
lint extgcd(lint a, lint b, lint &x, lint &y)
{
    lint d = a;
    if (b != 0) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    else x = 1, y = 0;
    return d;
}
// Calc a^(-1) (MOD m)
lint mod_inverse(lint a, lint m)
{
    lint x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

struct UndirectedTree
{
    int V;
    int root;
    int dfs_cnt;
    vector<vector<int>> edge;
    UndirectedTree(int N = 0) : V(N), dfs_cnt(0), edge(N) {}
    void add_edge(int u, int v)
    {
        edge[u].emplace_back(v);
        edge[v].emplace_back(u);
    }
    vector<int> par;
    vector<int> subtree_size;
    vector<int> dfs_id;
    void _tree_dfs(int now, int prv)
    {
        par[now] = prv;
        subtree_size[now] = 1;
        dfs_id[now] = dfs_cnt++;
        for (auto nxt : edge[now]) if (nxt != prv)
        {
            _tree_dfs(nxt, now);
            subtree_size[now] += subtree_size[nxt];
        }
    }
    void tree_dfs(int r)
    {
        root = r;
        par.resize(V, -1);
        subtree_size.resize(V, -1);
        dfs_id.resize(V, 0);
        dfs_cnt = 0;
        _tree_dfs(root, -1);
    }

    vector<int> prev_heavy;
    int DT;
    void _tree_dfs_th(int now, int prv, int ph)
    {
        prev_heavy[now] = ph;
        if ((int)edge[now].size() >= DT) ph = now;
        for (auto nxt : edge[now]) if (nxt != prv)
        {
            _tree_dfs_th(nxt, now, ph);
        }
    }
    void tree_dfs_th(int B)
    {
        DT = B;
        prev_heavy.assign(V, -1);
        _tree_dfs_th(root, -1, -1);
    }
    vector<vector<int>> parinfo;
    void _hp_dfs(int now, int prv, int c, int r)
    {
        parinfo[r][now] = c;
        for (auto nxt : edge[now]) if (nxt != prv) _hp_dfs(nxt, now, c, r);
    }
    void heavy_prepare()
    {
        parinfo.resize(V);
        REP(now, V) if ((int)edge[now].size() >= DT)
        {
            parinfo[now].resize(V);
            for (auto nxt : edge[now]) if (nxt != par[now]) _hp_dfs(nxt, now, nxt, now);
        }
    }
};

constexpr lint MOD = 998244353;
struct BIT
{
    using T = lint;
    int len;
    vector<T> val;
    BIT(int num) : len(num), val(num + 1) {}
    BIT() : BIT(0) {}
    void reset() { fill(val.begin(), val.end(), 0); }
    void _add(int pos, T v) {
        while (pos > 0 and pos <= len)
        {
            val[pos] += v;
            if (val[pos] >= MOD) val[pos] -= MOD;
            pos += pos & -pos;
        }
    }
    T _sum(int pos) const // (0, pos]
    {
        T res = 0;
        while (pos > 0) res += val[pos], pos -= pos & -pos;
        return res % MOD;
    }
    void range_add(int l, int r, T v)
    {
        _add(l + 1, v);
        _add(r + 1, MOD - v);
    }
    T get(int x)
    {
        return _sum(x + 1);
    }
};

vector<lint> cache;

constexpr int B = 200;
int main()
{
    int N, Q;
    cin >> N >> Q;
    UndirectedTree tree(N);
    REP(_, N - 1)
    {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u - 1, v - 1);
    }
    tree.tree_dfs(0);
    tree.tree_dfs_th(B);
    tree.heavy_prepare();
    lint Ninv = mod_inverse(N, MOD);
    BIT bit(N);

    cache.resize(N);
    REP(_, Q)
    {
        int q, v;
        cin >> q >> v;
        v--;
        int bid = tree.dfs_id[v];
        if (q == 1)
        {
            lint d;
            cin >> d;

            lint stsz = tree.subtree_size[v];
            lint A = N - stsz;

            bit.range_add(0, N, d * stsz % MOD * Ninv % MOD);
            bit.range_add(bid, bid + stsz, d * A % MOD * Ninv % MOD);
            if ((int)tree.edge[v].size() >= B)
            {
                (cache[v] += d) %= MOD;
            }
            else
            {
                for (auto nxt : tree.edge[v]) if (nxt != tree.par[v])
                {
                    lint cid = tree.dfs_id[nxt], cstsz = tree.subtree_size[nxt];
                    bit.range_add(cid, cid + cstsz, MOD - d * cstsz % MOD * Ninv % MOD);
                }
            }
        }
        else
        {
            lint ret = bit.get(bid);
            while (tree.prev_heavy[v] >= 0)
            {
                int p = tree.prev_heavy[v];
                int c = tree.parinfo[p][v];
                ret = ret + MOD - cache[p] * tree.subtree_size[c] % MOD * Ninv % MOD;
                v = p;
            }
            ret %= MOD;
            printf("%lld\n", ret);
        }
    }
}