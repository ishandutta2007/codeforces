#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

bool solve()
{
    int N, M;
    cin >> N >> M;
    vector<lint> P(N), H(N);
    cin >> P >> H;
    vector<vector<int>> to(N);
    REP(_, N - 1)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        to[x].emplace_back(y);
        to[y].emplace_back(x);
    }
    bool ret = true;

    vector<lint> ch_good(N), ch_bad(N);
    auto dfs1 = [&](auto &&dfs1, int now, int prv) -> void {
        lint good_tmp = 0, bad_tmp = 0;
        for (auto nxt : to[now]) if (nxt != prv)
        {
            dfs1(dfs1, nxt, now);
            good_tmp += ch_good[nxt];
            bad_tmp += ch_bad[nxt];
        }
        if (abs(good_tmp + bad_tmp + P[now] + H[now]) % 2) ret = false;
        if (good_tmp + bad_tmp + P[now] < H[now] or good_tmp - bad_tmp - P[now] > H[now]) ret = false;
        lint tot = good_tmp + bad_tmp + P[now];
        ch_good[now] = (tot + H[now]) / 2, ch_bad[now] = (tot - H[now]) / 2;
    };
    dfs1(dfs1, 0, -1);

    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "YES" : "NO") << '\n';
}