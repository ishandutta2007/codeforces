#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

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
int N, M;
vector<unordered_set<int, custom_hash>> e;

// void solve()
// {
//     UnionFind uf(N);
//     REP(i, N) REP(j, i) if (!e[i].count(j)) uf.unite(i, j);
//     set<int> rs;
//     REP(i, N) rs.insert(uf.find(i));
//     cout << (int)rs.size() - 1 << endl;
// }

int main()
{
    cin >> N >> M;
    e.resize(N);
    REP(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[a].insert(b);
        e[b].insert(a);
    }
    vector<pint> sz2i(N);
    REP(i, N) sz2i[i] = make_pair(e[i].size(), i);
    sort(ALL(sz2i));
    UnionFind uf(N);
    int r = sz2i[0].second;
    vector<int> bad;
    REP(i, N)
    {
        if (!e[r].count(i)) uf.unite(i, r);
        else bad.push_back(i);
    }
    for (auto x : bad)
    {
        REP(i, N) if (!e[x].count(i)) uf.unite(i, x);
    }
    set<int> ret;
    REP(i, N) ret.insert(uf.find(i));
    cout << (int)ret.size() - 1 << endl;
}