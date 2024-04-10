#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

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


int main()
{
    int N;
    cin >> N;
    UnionFind uf(N + 1);
    vector<pint> xy(N);
    REP(i, N) cin >> xy[i].first >> xy[i].second;
    vector<lint> C(N), K(N);
    cin >> C >> K;
    using P = pair<lint, pint>;
    priority_queue<P, vector<P>, greater<P>> pq;
    REP(i, N) pq.emplace(C[i], pint(i, N));
    REP(i, N) REP(j, i) pq.emplace((abs(xy[i].first - xy[j].first) + abs(xy[i].second - xy[j].second)) * (K[i] + K[j]), pint(j, i));
    lint cost = 0;
    set<int> s;
    vector<pint> e;
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        if (uf.same(p.second.first, p.second.second)) continue;

        uf.unite(p.second.first, p.second.second);
        cost += p.first;

        if (p.second.second == N) s.insert(p.second.first);
        else e.emplace_back(p.second);
    }
    printf("%lld\n%d\n", cost, (int)s.size());
    for (auto x : s) printf("%d ", x + 1);
    puts("");
    printf("%d\n", (int)e.size());
    for (auto p : e) printf("%d %d\n", p.first + 1, p.second + 1);
}