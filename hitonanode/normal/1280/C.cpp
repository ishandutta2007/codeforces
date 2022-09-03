#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


vector<vector<plint>> e;
int N;
lint ret0, ret1;
int dfs(int now, int prv) {

    int stsz = 1;
    for (auto nxt : e[now]) if (nxt.first != prv) {
        auto ss = dfs(nxt.first, now);
        if (ss % 2) ret0 += nxt.second;
        ret1 += nxt.second * min(ss, N - ss);
        stsz += ss;
    }
    return stsz;
}
void solve()
{
    int K;
    cin >> K;
    N = 2 * K;
    e.clear();
    e.resize(K * 2);
    REP(_, K * 2 - 1) {
        int a, b, t;
        cin >> a >> b >> t;
        e[a - 1].emplace_back(b - 1, t);
        e[b - 1].emplace_back(a - 1, t);
    }
    ret0 = 0, ret1 = 0;
    dfs(0, -1);
    printf("%lld %lld\n", ret0, ret1);
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}