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
    int NO_PARENT = -1;
    using pint = pair<int, int>;
    int V;
    int E;
    vector<vector<pint>> to;  // (node_id, edge_id)
    vector<int> par;          // parent node_id par[root] = -1
    vector<vector<int>> chi;  // children id's
    vector<int> subtree_size; // size of each subtree
    vector<int> available_edge;

    Tree() : Tree(0) {}
    Tree(int v) : V(v), E(0), to(v), par(v, NO_PARENT), chi(v), subtree_size(v) {}

    void add_edge(int v1, int v2)
    {
        to[v1].emplace_back(v2, E);
        to[v2].emplace_back(v1, E);
        E++;
        available_edge.emplace_back(1);
    }

    int _dfs_fixroot(int now, int prv)
    {
        chi[now].clear();
        subtree_size[now] = 1;
        for (auto nxt : to[now])
        {
            if (nxt.first != prv and available_edge[nxt.second])
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


    vector<int> centroid_cand_tmp;
    void _dfs_detect_centroid(int now, int prv, int n)
    {
        bool is_centroid = true;
        for (auto nxt : to[now])
        {
            if (nxt.first != prv and available_edge[nxt.second])
            {
                _dfs_detect_centroid(nxt.first, now, n);
                if (subtree_size[nxt.first] > n / 2) is_centroid = false;
            }
        }
        if (n - subtree_size[now] > n / 2) is_centroid = false;
        if (is_centroid) centroid_cand_tmp.push_back(now);
    }
    // Centroid Decomposition
    pint detect_centroid(int r) // ([centroid_node_id1], ([centroid_node_id2]|-1))
    {
        centroid_cand_tmp.clear();
        while (par[r] != NO_PARENT) r = par[r];
        int n = subtree_size[r];
        _dfs_detect_centroid(r, -1, n);
        if (centroid_cand_tmp.size() == 1) return make_pair(centroid_cand_tmp[0], -1);
        else return make_pair(centroid_cand_tmp[0], centroid_cand_tmp[1]);
    }
};

Tree tree;
vector<int> ret;
void dfs(int now, int depth)
{
    tree.fix_root(now);
    pint pa = tree.detect_centroid(now);
    int r = pa.first;
    ret[r] = depth;
    for (auto nxt : tree.to[r]) if (tree.available_edge[nxt.second])
    {
        tree.available_edge[nxt.second] = false;
        dfs(nxt.first, depth + 1);
    }
}

int main()
{
    int N;
    cin >> N;
    tree = Tree(N + 1);
    REP(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        tree.add_edge(a, b);
    }
    ret.resize(N + 1);
    dfs(1, 0);
    REP(i, N) printf("%c ", (char)(ret[i + 1] + 'A'));
}