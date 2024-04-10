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
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////

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
    SizeAwareUnionFind uf(N + 1);

    map<int, vector<pint>> e;
    REP(_, N - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[w].emplace_back(u, v);
    }
    map<int, lint> m;

    lint c = 0;
    m[0] = c;
    for (auto we : e)
    {
        int w = we.first;
        for (auto pa : we.second)
        {
            lint su = uf.count(pa.first);
            lint sv = uf.count(pa.second);
            c += su * sv;
            uf.unite(pa.first, pa.second);
        }
        m[w] = c;
    }
    REP(_, M)
    {
        int q;
        cin >> q;
        printf("%lld ", prev(m.upper_bound(q))->second);
    }
}