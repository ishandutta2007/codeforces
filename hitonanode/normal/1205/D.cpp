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
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

struct Tree
{
    const int NO_PARENT = -1;
    using pint = pair<int, int>;
    int V; // 
    int E;
    vector<vector<pint>> to;  // (neighbor node id, edge_id)
    vector<int> par;          //  par[root] = -1
    vector<vector<int>> chi;  // 
    vector<int> subtree_size; // root

    vector<int> valid_edge;

    Tree() : Tree(0) {}
    Tree(int v) : V(v), E(0), to(v), par(v, NO_PARENT), chi(v), subtree_size(v) {}

    void add_edge(int v1, int v2)
    {
        to[v1].emplace_back(v2, E);
        to[v2].emplace_back(v1, E);
        E++;
        valid_edge.push_back(1);
    }

    int _dfs_fixroot(int now, int prv)
    {
        // dbg(now);
        chi[now].clear();
        subtree_size[now] = 1;
        for (auto nxt : to[now])
        {
            if (nxt.first != prv and valid_edge[nxt.second])
            {
                par[nxt.first] = now;
                chi[now].push_back(nxt.first);
                subtree_size[now] += _dfs_fixroot(nxt.first, now);
            }
        }
        return subtree_size[now];
    }

    void fix_root(int root)
    {
        par[root] = NO_PARENT;
        _dfs_fixroot(root, -1);
    }

    ////  ////
    vector<int> centroid_cand_tmp;
    void _dfs_detect_centroid(int now, int prv, int n)
    {
        bool is_centroid = true;
        for (auto nxt : to[now])
        {
            if (nxt.first != prv and valid_edge[nxt.second])
            {
                _dfs_detect_centroid(nxt.first, now, n);
                if (subtree_size[nxt.first] > n / 2) is_centroid = false;
            }
        }
        if (n - subtree_size[now] > n / 2) is_centroid = false;
        if (is_centroid) centroid_cand_tmp.push_back(now);
    }
    pint detect_centroid(int r) // 
    {
        centroid_cand_tmp.clear();
        while (par[r] != NO_PARENT) r = par[r];
        int n = subtree_size[r];
        _dfs_detect_centroid(r, -1, n);
        if (centroid_cand_tmp.size() == 1) return make_pair(centroid_cand_tmp[0], -1);
        else return make_pair(centroid_cand_tmp[0], centroid_cand_tmp[1]);
    }

    vector<int> ret;
    void dfs_solve(int now, int prv, int d, int dinit)
    {
        ret[now] = dinit;
        dinit = d;
        for (auto nxt : to[now]) if (nxt.first != prv)
        {
            int n = subtree_size[nxt.first];
            dfs_solve(nxt.first, now, d, dinit);
            dinit += d * n;
        }
    }
    void solve(int root)
    {
        ret.resize(V);
        sort(ALL(to[root]), [&](pint l, pint r) { return subtree_size[l.first] > subtree_size[r.first]; });
        int v = subtree_size[root];
        int n = 0, m = 0;
        for (auto nxt : to[root])
        {
            if (n <= v / 3)
            {
                dfs_solve(nxt.first, root, 1, 1 + n);
                n += subtree_size[nxt.first];
            }
            else
            {
                dfs_solve(nxt.first, root, 1 + n, (1 + m) * (1 + n));
                m += subtree_size[nxt.first];
            }
        }
    }
};

int main()
{
    int N;
    cin >> N;
    Tree tree(N + 1);
    REP(_, N - 1)
    {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u, v);
    }
    tree.fix_root(1);
    auto pa = tree.detect_centroid(1);
    int root = pa.first;

    tree.fix_root(root);
    tree.solve(root);
    REP(u, tree.ret.size())
    {
        if (tree.ret[u] == 0) continue;
        printf("%d %d %d\n", u, tree.par[u], tree.ret[u]);
    }
}