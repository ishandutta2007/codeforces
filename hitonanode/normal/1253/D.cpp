#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios
{
    fast_ios()
    {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    };
} fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }


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


int main()
{
    int N, M;
    cin >> N >> M;
    SizeAwareUnionFind uf(N);
    REP(_, M)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        uf.unite(u, v);
    }
    map<int, int> lo, hi;
    REP(i, N)
    {
        int r = uf.find(i);
        hi[r] = i;
        if (!lo.count(r)) lo[r] = i;
    }
    vector<pint> seg;
    for (auto p : lo) seg.emplace_back(p.second, hi[p.first]);
    sort(seg.begin(), seg.end());
    int ret = 0;
    int end = -1;
    for (auto p : seg)
    {
        if (p.first <= end) ret++;
        mmax(end, p.second);
    }
    cout << ret << endl;
}