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
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_by_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

struct rand_int_
{
    mt19937 mt;
    rand_int_() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } // [0, x)
    lint operator()(lint l, lint r) {
        uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;
using SingleHash = lint;
using DoubleHash = pair<SingleHash, SingleHash>;
struct UndirectedTree
{
    using Edges = vector<vector<int>>; // vector<set<int>>;
    int V;
    int root;
    Edges e;
    UndirectedTree(int v, int root) : V(v), root(root), e(v) {}
    void add_edge(int u, int v)
    {
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    vector<SingleHash> _hash_single; 
    vector<SingleHash> _hash_des_single;
    vector<SingleHash> _hash_par_single;
    vector<DoubleHash> hash;     // hash of the tree, each node regarded as root
    vector<DoubleHash> hash_des; // hash of the subtree
    vector<DoubleHash> hash_par;
    lint hash_p, hmod; // hmod : prime, \in [0, 2^63). hash_p: \in [1, hmod)
    SingleHash hash_dfs1_(int now, int prv)
    {
        _hash_des_single[now] = hash_p;
        for (auto nxt : e[now]) if (nxt != prv) (_hash_des_single[now] += hash_dfs1_(nxt, now)) %= hmod;
        return _hash_des_single[now] * _hash_des_single[now] % hmod;
    }
    void hash_dfs2_(int now, int prv)
    {
        (_hash_single[now] += _hash_des_single[now]) %= hmod;
        if (prv >= 0) _hash_par_single[now] = (_hash_single[prv] - _hash_des_single[now] * _hash_des_single[now] % hmod + hmod) % hmod;
        for (auto nxt : e[now]) if (nxt != prv)
        {
            SingleHash tmp = (_hash_single[now] - _hash_des_single[nxt] * _hash_des_single[nxt] % hmod + hmod) % hmod;
            (_hash_single[nxt] += tmp * tmp) %= hmod;
            hash_dfs2_(nxt, now);
        }
    }
    void build_hash(lint p1, lint mod1, lint p2, lint mod2)
    {
        hash.resize(V), hash_des.resize(V), hash_par.resize(V);
        _hash_single.assign(V, 0), _hash_des_single.resize(V), _hash_par_single.assign(V, 0), hash_p = p1, hmod = mod1;
        hash_dfs1_(root, -1), hash_dfs2_(root, -1);
        REP(i, V) hash[i].first = _hash_single[i], hash_des[i].first = _hash_des_single[i], hash_par[i].first = _hash_par_single[i];
        _hash_single.assign(V, 0), hash_p = p2, hmod = mod2;
        hash_dfs1_(root, -1), hash_dfs2_(root, -1);
        REP(i, V) hash[i].second = _hash_single[i], hash_des[i].second = _hash_des_single[i], hash_par[i].second = _hash_par_single[i];
    }
};
map<DoubleHash, int> cou;
UndirectedTree tree(1, 0);
int ans;
lint maxi;
void dfs(int now, int prv)
{
    if (mmax(maxi, SZ(cou))) ans = now;
    for (auto nxt : tree.e[now]) if (nxt != prv)
    {
        DoubleHash hash_del = tree.hash_des[nxt];
        DoubleHash hash_add = tree.hash_par[nxt];
        cou[hash_del]--;
        if (cou[hash_del] == 0) cou.erase(hash_del);
        cou[hash_add]++;
        dfs(nxt, now);
        cou[hash_add]--;
        if (cou[hash_add] == 0) cou.erase(hash_add);
        cou[hash_del]++;
    }
}

int main()
{
    int N;
    cin >> N;
    tree = UndirectedTree(N, 0);
    REP(_, N - 1)
    {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u - 1, v - 1);
    }
    tree.build_hash(rnd(1, 1000000007), 1000000007, rnd(1, 998244353), 998244353);

    REP(i, N) cou[tree.hash_des[i]]++;
    ans = maxi = -1;
    dfs(0, -1);
    cout << ans + 1 << endl;
}