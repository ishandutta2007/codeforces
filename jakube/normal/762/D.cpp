#include <bits/stdc++.h>
using namespace std;

struct DP { 
    long long UfL, UfM, UfD, MfU, MfL, MfD, DfL, DfM, DfU, U2L, D2L;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;

    vector<vector<long long>> a(3, vector<long long>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<DP> dp(n + 1);
    long long NEG_INF = numeric_limits<long long>::min() / 2;
    dp[0].UfL = 0;
    dp[0].UfM = NEG_INF;
    dp[0].UfD = NEG_INF;
    dp[0].MfU = NEG_INF;
    dp[0].MfL = NEG_INF;
    dp[0].MfD = NEG_INF;
    dp[0].DfL = NEG_INF;
    dp[0].DfM = NEG_INF;
    dp[0].DfU = NEG_INF;
    dp[0].U2L = NEG_INF;
    dp[0].D2L = NEG_INF;

    for (int i = 0; i < n; i++) {
        DP &last = dp[i];
        DP &cur = dp[i+1];

        cur.UfL = max({last.UfL, last.UfM, last.UfD, last.U2L}) + a[0][i];
        cur.MfL = max({last.MfU, last.MfL, last.MfD}) + a[1][i];
        cur.DfL = max({last.DfL, last.DfM, last.DfU, last.D2L}) + a[2][i];

        if (i >= 1) {
            //  /-
            //  \\
            //  -/
            cur.U2L = last.DfL + a[0][i-1] + a[0][i] + a[1][i-1] + a[1][i] + a[2][i];

            //  -\
            //  //
            //  \-
            cur.D2L = last.UfL + a[0][i] + a[1][i-1] + a[1][i] + a[2][i-1] + a[2][i];
        } else {
            cur.U2L = NEG_INF;
            cur.D2L = NEG_INF;
        }
        
        cur.UfM = cur.MfL + a[0][i];
        cur.UfD = cur.DfL + a[0][i] + a[1][i];

        cur.MfU = cur.UfL + a[1][i];
        cur.MfD = cur.DfL + a[1][i];

        cur.DfM = cur.MfL + a[2][i];
        cur.DfU = cur.UfL + a[2][i] + a[1][i];
    }

    DP &last = dp.back();
    cout << max({last.DfL, last.DfU, last.DfM, last.D2L}) << endl;

    return 0;
}