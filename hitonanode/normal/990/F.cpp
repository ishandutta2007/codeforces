#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind
{
    std::vector<int> par;
    vector<lint> cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};



int main()
{
    int N;
    cin >> N;
    vector<lint> S(N);
    cin >> S;
    int M;
    cin >> M;
    vector<pint> edges(M, pint(-1, -1));
    vector<set<int>> to(N);
    UnionFind uf(N);
    uf.cou = S;
    REP(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (uf.unite(u, v)) {
            to[u].insert(i);
            to[v].insert(i);
            edges[i] = make_pair(u, v);
        }
    }

    REP(i, N) if (uf.count(i)) {
        puts("Impossible");
        return 0;
    }

    queue<int> q;
    REP(i, N) if (to[i].size() == 1) {
        q.emplace(i);
    }
    vector<lint> ret(M);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (to[now].empty()) continue;

        lint v = S[now];
        if (v) {
            int e = *to[now].begin();
            int nxt = now ^ edges[e].first ^ edges[e].second;
            ret[e] += (now != edges[e].first ? S[now] : -S[now]);
            S[nxt] += S[now];
            S[now] = 0;
        }

        for (auto e : to[now]) {
            int nxt = now ^ edges[e].first ^ edges[e].second;
            if (to[nxt].size() == 2) {
                q.emplace(nxt);
            }
            to[nxt].erase(e);
        }
        to[now].clear();
    }
    puts("Possible");
    for (auto x : ret) printf("%lld\n", x);
}