#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////


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
    vector<DoubleHash> hash;     // hash of the tree, each node regarded as root
    vector<DoubleHash> hash_des; // hash of the subtree
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
        for (auto nxt : e[now]) if (nxt != prv)
        {
            SingleHash tmp = (_hash_single[now] - _hash_des_single[nxt] * _hash_des_single[nxt] % hmod + hmod) % hmod;
            (_hash_single[nxt] += tmp * tmp) %= hmod;
            hash_dfs2_(nxt, now);
        }
    }
    void build_hash(lint p1, lint mod1, lint p2, lint mod2)
    {
        hash.resize(V), hash_des.resize(V);
        _hash_single.assign(V, 0), _hash_des_single.resize(V), hash_p = p1, hmod = mod1;
        hash_dfs1_(root, -1), hash_dfs2_(root, -1);
        REP(i, V) hash[i].first = _hash_single[i], hash_des[i].first = _hash_des_single[i];
        _hash_single.assign(V, 0), hash_p = p2, hmod = mod2;
        hash_dfs1_(root, -1), hash_dfs2_(root, -1);
        REP(i, V) hash[i].second = _hash_single[i], hash_des[i].second = _hash_des_single[i];
    }
};

void NO() { puts("-1"); exit(0); }

UndirectedTree tree(0, 0);

map<int, set<DoubleHash>> ma;
void dfs(int now, int prv, int d)
{
    ma[d].insert(tree.hash[now]);
    for (auto nxt : tree.e[now]) if (nxt != prv) dfs(nxt, now, d + 1);
}
void check(int r)
{
    dfs(r, -1, 0);
    for (auto pa : ma) if (pa.second.size() > 1) NO();
    cout << r + 1 << endl;
}
int main()
{
    int N;
    cin >> N;
    if (N == 1)
    {
        puts("1");
        return 0;
    }
    tree = UndirectedTree(N, 0);
    REP(_, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree.add_edge(a, b);
    }
    tree.build_hash(rnd(1, 1000000007), 1000000007, rnd(1, 1000000009), 1000000009);

    int now = -1, prv = -1;
    vector<map<DoubleHash, vector<int>>> h(N);
    REP(i, N)
    {
        for (auto j : tree.e[i]) h[i][tree.hash[j]].push_back(j);
        if (h[i].size() > 2) NO();
        if (h[i].size() == 1) continue;
        if (tree.e[i].size() > 2) for (auto pa : h[i]) if (pa.second.size() == 1) now = i;
    }

    if (now < 0)
    {
        REP(i, N) if (tree.e[i].size() == 1)
        {
            check(i);
            return 0;
        }
    }
    else
    {
        while (tree.e[now].size() > 1 and h[now].size() > 1)
        {
            int nxt = -1;
            for (auto pa : h[now]) if (pa.second[0] != prv and pa.second.size() == 1) nxt = pa.second[0];
            if (nxt < 0) break;
            prv = now;
            now = nxt;
        }
        check(now);
        return 0;
    }
}