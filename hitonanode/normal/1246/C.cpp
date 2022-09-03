#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


constexpr lint MOD = 1000000007;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    cin >> S;
    if (N == 1 and M == 1)
    {
        puts("1");
        return 0;
    }
    vector<vector<vector<int>>> mright;
    ndarray(mright, 2, N, M);
    vector<vector<vector<lint>>> dp;
    ndarray(dp, 2, N + 2, M + 2);
    REP(h, N)
    {
        int k = 0;
        IREP(w, M)
        {
            mright[0][h][w] = k;
            if (S[h][w] == '.') k++;
        }
    }
    REP(w, M)
    {
        int k = 0;
        IREP(h, N)
        {
            mright[1][h][w] = k;
            if (S[h][w] == '.') k++;
        }
    }
    dp[0][0][0] = dp[1][0][0] = 1;
    dp[1][0][1] = dp[0][1][0] = MOD - 1;
    REP(h, N) REP(w, M)
    {
        (dp[1][h][w + 1] += dp[1][h][w]) %= MOD;
        (dp[0][h + 1][w] += dp[0][h][w]) %= MOD;

        if (mright[0][h][w])
        {
            (dp[1][h][w + 1] += dp[0][h][w]) %= MOD;
            (dp[1][h][min(w + mright[0][h][w] + 1, M)] += MOD - dp[0][h][w]) %= MOD;
        }
        if (mright[1][h][w])
        {
            (dp[0][h + 1][w] += dp[1][h][w]) %= MOD;
            (dp[0][min(N, h + mright[1][h][w] + 1)][w] += MOD - dp[1][h][w]) %= MOD;
        }
    }
    cout << (dp[0][N - 1][M - 1] + dp[1][N - 1][M - 1]) % MOD << endl;
}