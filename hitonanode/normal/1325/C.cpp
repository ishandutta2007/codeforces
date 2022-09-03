#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


vector<vector<pint>> to;
int main()
{
    int N;
    cin >> N;
    to.resize(N);
    REP(e, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        to[u].emplace_back(v, e);
        to[v].emplace_back(u, e);
    }
    if (N == 2) {
        puts("0");
        return 0;
    }
    int r = 0;
    while (r < N and to[r].size() <= 2) r++;
    if (r == N) {
        REP(i, N - 1) printf("%d\n", i);
        return 0;
    }
    int id_ = 0;
    vector<int> ret(N - 1, -1);
    for (auto p : to[r]) {
        ret[p.second] = id_++;
    }
    REP(i, ret.size()) if (ret[i] == -1) {
        ret[i] = id_++;
    }
    for (auto x : ret) printf("%d\n", x);
}