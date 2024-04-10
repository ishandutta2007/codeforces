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


int N, M;
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

    // scc()
    DirectedGraph generateTopologicalGraph()
    {
        DirectedGraph newgraph(scc_num);
        REP(s, V) for (auto t : to[s])
        {
            if (cmp[s] != cmp[t]) newgraph.add_edge(cmp[s], cmp[t]);
        }
        return newgraph;
    }
};
vector<pint> p;

int main()
{
    cin >> N >> M;
    DirectedGraph g(N);
    REP(_, M)
    {
        int u, v;
        cin >> u >> v;
        p.emplace_back(u, v);
        g.add_edge(u - 1, v - 1);
    }
    int scc = g.scc();
    if (scc == N)
    {
        puts("1");
        REP(_, M) printf("1 ");
        puts("");
    }
    else
    {
        puts("2");
        for (auto pa : p) printf("%d ", pa.first < pa.second ? 1 : 2);
        puts("");
    }
}