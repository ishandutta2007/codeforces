#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> cou(M + 1);
    REP(_, N)
    {
        int a;
        cin >> a;
        cou[a]++;
    }
    vector<vector<vector<int>>> dp(M + 1, vector<vector<int>>(5, vector<int>(5, -1e9)));
    dp[0][0][0] = 0;

    REP(i, M)
    {
        REP(j, 5) REP(k, 5) REP(d, 5) // dp[i][j][k] -> dp[i][d][e]
        {
            int n = cou[i + 1] - d;
            if (n < 0) continue;
            int s = min({n, j, k});
            REP(ss, s + 1) mmax(dp[i + 1][d][j - ss], dp[i][j][k] + (n - ss) / 3 + ss);
        }
        IREP(j, 5) IREP(k, 4) mmax(dp[i + 1][j][k], dp[i + 1][j][k + 1]);
        IREP(j, 4) IREP(k, 5) mmax(dp[i + 1][j][k], dp[i + 1][j + 1][k]);
    }
    cout << dp[M][0][0] << endl;
}