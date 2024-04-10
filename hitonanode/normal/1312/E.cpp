#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    vector<vector<int>> dp(N, vector<int>(N + 1, -1));
    REP(i, N) dp[i][i + 1] = A[i];
    FOR(d, 2, N + 1) REP(l, N) {
        int r = l + d;
        if (r > N) continue;
        FOR(c, l + 1, r) if (dp[l][c] >= 0 and dp[l][c] == dp[c][r]) {
            dp[l][r] = dp[l][c] + 1;
        }
    }
    vector<int> D(N + 1, 1e9);
    D[0] = 0;
    REP(l, N) FOR(r, l, N + 1) if (dp[l][r] >= 0) mmin(D[r], D[l] + 1);
    cout << D.back() << endl;
}