#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

constexpr lint INF = 1e15;

int main()
{
    lint N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<vector<lint>> dp(N + 1, vector<lint>(26));
    dp[0][0] = 1;
    for (auto c : S)
    {
        int d = c - 'a';
        IFOR(i, 1, N + 1)
        {
            lint tmp = 0;
            REP(cc, 26)
            {
                tmp += dp[i - 1][cc];
                if (tmp > INF) tmp = INF;
            }
            dp[i][d] = tmp;
        }
    }
    lint cost = 0;
    IREP(i, N + 1)
    {
        lint k = 0;
        REP(c, 26) k += dp[i][c];
        k = min(k, K);
        K -= k;
        cost += k * (N - i);
        if (!K)
        {
            cout << cost << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}