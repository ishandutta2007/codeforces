#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

constexpr int INF = 1e9;
int solve()
{
    int N;
    string S, T;
    cin >> N >> S >> T;

    string ss = S, tt = T;
    sort(ALL(ss));
    sort(ALL(tt));
    if (ss != tt) return -1;

    vector<int> pend(26);
    vector<vector<int>> scnt(26, vector<int>(N + 1));
    vector<vector<int>> tcnt(26, vector<int>(N + 1));

    REP(i, N)
    {
        REP(d, 26) scnt[d][i + 1] = scnt[d][i];
        scnt[S[i] - 'a'][i + 1]++;
        REP(d, 26) tcnt[d][i + 1] = tcnt[d][i];
        tcnt[T[i] - 'a'][i + 1]++;
    }

    vector<vector<int>> dp(N + 2, vector<int>(N + 2, -INF));
    dp[0][0] = 0;
    REP(i, N + 1) REP(j, N + 1) if (dp[i][j] > -INF)
    {
        if (i < N and j < N and S[i] == T[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
        if (i < N and scnt[S[i] - 'a'][i + 1] <= tcnt[S[i] - 'a'][j]) chmax(dp[i + 1][j], dp[i][j]);
        chmax(dp[i][j + 1], dp[i][j]);
    }
    return N - dp[N][N];
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}