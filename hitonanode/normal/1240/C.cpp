#include <bits/stdc++.h>
using namespace std;
#define int long long
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int N, K;
vector<vector<pint>> edges;

pint dfs(int now, int prv) // (prv<->now, )
{
    int val = 0;
    vector<int> vdiff;
    for (auto nxt : edges[now]) if (nxt.first != prv)
    {
        pint p = dfs(nxt.first, now);
        p.second += nxt.second;
        val += p.first;
        vdiff.emplace_back(p.second - p.first);
    }
    sort(vdiff.rbegin(), vdiff.rend());
    while (vdiff.size() and vdiff.back() < 0) vdiff.pop_back();
    int n1 = min(K, (int)vdiff.size());
    int n2 = min(K - 1, (int)vdiff.size());
    pint ret;
    ret.first = val + accumulate(vdiff.begin(), vdiff.begin() + n1, 0LL);
    ret.second = val + accumulate(vdiff.begin(), vdiff.begin() + n2, 0LL);
    return ret;
}

int solve()
{
    cin >> N >> K;
    edges.assign(N + 1, {});
    REP(_, N - 1)
    {
        int U, V, W;
        cin >> U >> V >> W;
        edges[U].emplace_back(V, W);
        edges[V].emplace_back(U, W);
    }
    return dfs(1, 0).first;
}

signed main()
{
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        printf("%lld\n", solve());
    }
}