#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int solve()
{
    string S;
    cin >> S;
    int N = S.length();
    vector<vector<int>> dp(10, vector<int>(10));
    for (auto c : S)
    {
        REP(d, 10) REP(e, 10)
        {
            if (dp[d][e] % 2 == 0 and c == '0' + d) dp[d][e]++;
            else if (dp[d][e] % 2 == 1 and c == '0' + e) dp[d][e]++;
        }
    }
    int ret = N;
    REP(d, 10) REP(e, 10)
    {
        if (d == e) chmin(ret, N - dp[d][e]);
        else chmin(ret, N - dp[d][e] / 2 * 2);
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}