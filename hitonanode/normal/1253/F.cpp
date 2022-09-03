#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }

int N, M, K, Q;

vector<vector<pint>> e;
vector<lint> D;
vector<lint> ans;

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
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct SizeAwareUnionFind
{
    vector<int> par;
    vector<unordered_set<int, custom_hash>> cou;
    SizeAwareUnionFind(int N = 0) : par(N), cou(N) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y, lint weight) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x].size() < cou[y].size()) swap(x, y); 
        par[y] = x;
        for (auto v : cou[y])
        {
            if (cou[x].count(v))
            {
                ans[v] = weight;
            }
            else cou[x].insert(v);
        }
        cou[y].clear();
        return true;
    }
    int count(int x) { return cou[find(x)].size(); }
    bool same(int x, int y) { return find(x) == find(y); }
};

int main()
{
    cin >> N >> M >> K >> Q;
    e.resize(N + 1);
    REP(_, M)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    
    priority_queue<plint, vector<plint>, greater<plint>> pq;
    D.resize(N + 1, 1e18);

    FOR(i, 1, K + 1) pq.emplace(0, i), D[i] = 0;
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        lint d = p.first;
        int now = p.second;
        if (D[now] < d) continue;
        for (auto q : e[now])
        {
            int nxt = q.first;
            lint len = q.second;
            if (mmin(D[nxt], D[now] + len)) pq.emplace(D[nxt], nxt);
        }
    }
    using P = pair<lint, pint>;
    vector<P> edges;
    REP(i, N + 1) for (auto p : e[i])
    {
        int j = p.first;
        if (j < i) continue;
        edges.emplace_back(D[i] + D[j] + p.second, pint(i, j));
    }

    sort(edges.begin(), edges.end());
    SizeAwareUnionFind uf(N + 1);

    REP(q, Q)
    {
        int a, b;
        cin >> a >> b;
        uf.cou[a].insert(q);
        uf.cou[b].insert(q);
    }
    ans.resize(Q);
    for (auto p : edges)
    {
        uf.unite(p.second.first, p.second.second, p.first);
    }
    for (auto x : ans) printf("%lld\n", x);
}