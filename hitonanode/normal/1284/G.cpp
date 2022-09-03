#include <bits/stdc++.h>
using namespace std;

#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

using Element = int;
using State = vector<char>;
// Matroid intersection solver
// Algorithm based on <http://dopal.cs.uec.ac.jp/okamotoy/lect/2015/matroid/>
// Complexity: O(CE^2 + E^3) (C : circuit query)
template <typename T_M1, typename T_M2>
State MatroidIntersection(T_M1 matroid1, T_M2 matroid2)
{
    assert(matroid1.M == matroid2.M);

    const int M = matroid1.M;
    const Element S = M, T = M + 1;
    State I(M);

    while (true) {
        vector<vector<Element>> to(M + 2);
        for (int e = 0; e < M; e++) if (!I[e]) {
            vector<Element> c1 = matroid1.circuit(I, e);
            if (c1.empty()) to[e].push_back(T);
            for (Element f : c1) to[e].push_back(f);
            vector<Element> c2 = matroid2.circuit(I, e);
            if (c2.empty()) to[S].push_back(e);
            for (Element f : c2) to[f].push_back(e);
        }
        vector<Element> backtrack(M + 2, -1);
        queue<Element> q;
        q.push(S);
        while (!q.empty()) {
            Element now = q.front();
            q.pop();
            if (now == T) break;
            for (Element nxt : to[now]) {
                if (backtrack[nxt] == -1) backtrack[nxt] = now, q.push(nxt);
            }
        }
        Element e = backtrack[T];
        if (e == -1) break;
        while (e != S) I[e] = !I[e], e = backtrack[e];
    }
    return I;
}


// GraphMatroid: subgraph of undirected graphs, without loops
struct GraphMatroid
{
    using Vertex = int;
    int M;
    int V; // # of vertices of graph
    vector<vector<pair<Vertex, Element>>> to;
    vector<pair<Vertex, Vertex>> edges;
    GraphMatroid() = default;
    GraphMatroid(int V, vector<pair<Vertex, Vertex>> edges_)
        : M(edges_.size()), V(V), to(V), edges(edges_)
    {
        for (size_t e = 0; e < edges_.size(); e++) {
            assert(edges_[e].first < V and edges_[e].second < V);
            to[edges_[e].first].emplace_back(edges_[e].second, e);
            to[edges_[e].second].emplace_back(edges_[e].first, e);
        }
    }
    vector<Element> circuit(State I, Element e)
    {
        if (I[e]) return {};
        assert(int(I.size()) == M and e < M);
        vector<Element> backtrack(V, -1);
        Vertex S = edges[e].first, T = edges[e].second;
        queue<Vertex> q;
        q.push(S);
        while (!q.empty()) {
            Vertex now = q.front();
            q.pop();
            for (auto nxt : to[now]) if (I[nxt.second]) {
                I[nxt.second] = 0;
                backtrack[nxt.first] = nxt.second;
                q.push(nxt.first);
            }
        }
        vector<Element> ret;
        while (backtrack[T] != -1) {
            ret.push_back(backtrack[T]);
            T = edges[backtrack[T]].first + edges[backtrack[T]].second - T;
        }
        return ret;
    }
};


struct PartitionMatroid
{
    int M;
    vector<vector<Element>> parts;
    vector<int> belong;
    vector<int> maxi;
    PartitionMatroid() = default;
    PartitionMatroid(int M, const vector<vector<int>> &parts, const vector<int> &maxi)
        : M(M), parts(parts), belong(M, -1), maxi(maxi)
    {
        for (size_t i = 0; i < parts.size(); i++) {
            for (Element x : parts[i]) belong[x] = i;
        }
        for (Element e = 0; e < M; e++) {
            // assert(belong[e] != -1);
            if (belong[e] == -1) {
                belong[e] = this->parts.size();
                this->parts.emplace_back(vector<int>{e});
                this->maxi.push_back(1);
            }
        }
    }

    vector<Element> circuit(const State &I, Element e) {
        if (I[e]) return {};
        assert(int(I.size()) == M and e < M);
        vector<Element> ret;
        int p = belong[e];
        int cnt = 0;
        for (Element x : parts[p]) cnt += I[x];
        if (cnt == maxi[p]) {
            for (Element x : parts[p]) if (I[x]) ret.push_back(x);
        }
        return ret;
    }
};


struct SizeAwareUnionFind
{
    vector<int> par, cou;
    SizeAwareUnionFind(int N) : par(N), cou(N) { REP(i, N) par[i] = i, cou[i] = 1; }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    void unite(int x, int y) {
        x = find(x), y = find(y); if (x == y) return;
        if (cou[x] < cou[y]) swap(x, y); 
        par[y] = x, cou[x] += cou[y];
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    REP(i, N) cin >> S[i];
    vector<vector<Element>> to(N * M);
    vector<pair<int, int>> edges;
    REP(i, N) REP(j, M) if (S[i][j] == 'O')
    {
        int u = i * M + j;
        if (j < M - 1 and S[i][j + 1] == 'O') {
            int v = u + 1;
            to[u].push_back(edges.size());
            to[v].push_back(edges.size());
            edges.emplace_back(u, v);
        }
        if (i < N - 1 and S[i + 1][j] == 'O') {
            int v = u + M;
            to[u].push_back(edges.size());
            to[v].push_back(edges.size());
            edges.emplace_back(u, v);
        }
    }

    vector<vector<Element>> grps;
    REP(i, N) REP(j, M) if ((i + j) % 2 == 0 and S[i][j] == 'O') {
        if (to[i * M + j].size()) grps.emplace_back(to[i * M + j]);
    }
    vector<int> maxi(grps.size(), 2);
    if (maxi.size()) maxi[0] = 1;
    PartitionMatroid mat1(edges.size(), grps, maxi);
    GraphMatroid mat2(N * M, edges);
    State ret = MatroidIntersection(mat1, mat2);
    if (accumulate(ret.begin(), ret.end(), 0) < accumulate(maxi.begin(), maxi.end(), 0))
    {
        puts("NO");
        return;
    }
    SizeAwareUnionFind uf(N * M);
    vector<string> T(N * 2 - 1, string(M * 2 - 1, ' '));
    REP(i, N) REP(j, M) T[i * 2][j * 2] = S[i][j];
    REP(i, edges.size()) if (ret[i]) {
        int u = edges[i].first, v = edges[i].second;
        uf.unite(u, v);
        int h = u / M, w = u % M;
        T[h * 2 + (v == u + M)][w * 2 + (v == u + 1)] = 'O';
    }
    REP(i, edges.size()) if (!ret[i]) {
        int u = edges[i].first, v = edges[i].second;
        if (uf.same(u, v)) continue;
        uf.unite(u, v);
        int h = u / M, w = u % M;
        T[h * 2 + (v == u + M)][w * 2 + (v == u + 1)] = 'O';
    }
    puts("YES");
    for (auto s : T) printf("%s\n", s.c_str());
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) solve();
}