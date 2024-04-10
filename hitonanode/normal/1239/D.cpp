#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


struct DirectedGraph
{
    int V; // 
    vector<vector<int> > to;
    vector<vector<int> > from;

    vector<bool> used;
    vector<int> vs;

    void dfs(int v)
    {
        used[v] = true;
        for (auto t : to[v]) if (!used[t]) dfs(t);
        vs.push_back(v);
    }
    void rdfs(int v, int k)
    {
        used[v] = true;
        cmp[v] = k;
        for (auto t : from[v]) if (!used[t]) rdfs(t, k);
    }

    vector<int> cmp;
    DirectedGraph(int V) : V(V),
                           to(vector<vector<int> >(V)), 
                           from(vector<vector<int> >(V)),
                           cmp(vector<int>(V))
                           {}
    void add_edge(int from_, int to_)
    {
        to[from_].push_back(to_);
        from[to_].push_back(from_);
    }

    int scc_num = -1;
    int scc()
    {
        used = vector<bool>(V, false);
        vs.clear();
        for (int v = 0; v < V; v++) if (!used[v]) dfs(v);

        used = vector<bool>(V, false);
        scc_num = 0;
        for (int i = vs.size() - 1; i >= 0; i--) if (!used[vs[i]]) rdfs(vs[i], scc_num++);
        return scc_num; // 
    }
};

struct UnionFind // UnionFind Tree (0-indexed)
{
    vector<int> par, rank;
    UnionFind(int N) : par(N), rank(N) { REP(i, N) par[i] = i; }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    void unite(int x, int y) {
        x = find(x), y = find(y); if (x == y) return;
        if (rank[x] < rank[y]) par[x] = y; else par[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
    bool same(int x, int y) { return find(x) == find(y); }
};

void solve()
{
    int N, M;
    cin >> N >> M;
    DirectedGraph g(N * 2);
    REP(_, M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g.add_edge(a, b);
        g.add_edge(b + N, a + N);
    }

    g.scc();
    set<int> s;
    REP(i, N) s.insert(g.cmp[i]);
    if (s.size() == 1)
    {
        puts("No");
        return;
    }
    puts("Yes");
    vector<int> ret1, ret2;
    int lo = *s.begin();
    REP(i, N) if (g.cmp[i] == lo) ret2.push_back(i + 1);
    else ret1.push_back(i + 1);
    printf("%d %d\n", (int)ret1.size(), (int)ret2.size());
    for (auto v : ret1) printf("%d ", v);
    puts("");
    for (auto v : ret2) printf("%d ", v);
    puts("");
}
int main()
{
    int TC;
    cin >> TC;
    REP(_, TC)
    {
        solve();
    }
}