#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

lint so(int X, int Y)
{
    if (X < 0 or Y < 0) return 0;
    if (X == 0 or Y == 0) return (lint)X + Y + 1;
    lint dp[31][2][2];
    memset(dp, 0, sizeof(dp));
    dp[30][1][1] = 1;
    IREP(d, 30)
    {
        bool bx = X & (1 << d);
        bool by = Y & (1 << d);
        REP(ix, 2) REP(iy, 2) if (ix + iy < 2)
        {
            dp[d][0][0] += dp[d + 1][0][0];
            if (by > iy) dp[d][0][0] += dp[d + 1][0][1];
            if (by == iy) dp[d][0][1] += dp[d + 1][0][1];

            if (bx > ix) dp[d][0][0] += dp[d + 1][1][0];
            if (bx == ix) dp[d][1][0] += dp[d + 1][1][0];

            if (bx < ix or by < iy) continue;
            dp[d][bx == ix][by == iy] += dp[d + 1][1][1];
        }
    }
    lint ret = 0;
    REP(i, 2) REP(j, 2) ret += dp[0][i][j];
    return ret;
}

lint solve()
{
    int L, R;
    cin >> L >> R;
    lint ret = so(R, R) - so(L - 1, R) - so(R, L - 1) + so(L - 1, L - 1);
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}