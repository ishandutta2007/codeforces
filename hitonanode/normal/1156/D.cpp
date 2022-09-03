#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

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
vector<set<int>> e;

int main()
{
    int N;
    cin >> N;
    SizeAwareUnionFind uf0(N + 1), uf1(N + 1);
    e.resize(N + 1);
    REP(_, N - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].insert(c);
        e[b].insert(c);
        if (c) uf1.unite(a, b);
        else uf0.unite(a, b);
    }

    map<int, lint> zero, one;
    FOR(i, 1, N + 1) zero[uf0.find(i)] = uf0.count(i), one[uf1.find(i)] = uf1.count(i);
    lint ret = 0;
    for (auto pa : zero) ret += pa.second * (pa.second - 1);
    for (auto pa : one) ret += pa.second * (pa.second - 1);
    FOR(i, 1, N + 1) if (e[i].size() == 2)
    {
        ret += (uf0.count(i) - 1LL) * (uf1.count(i) - 1LL);
    }
    cout << ret << endl;
}