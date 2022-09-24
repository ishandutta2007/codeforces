#include <bits/stdc++.h>
using namespace std;

const double INF = 1e6;
const int ITERS = 50;

void upd(double &x, double y) {
    x = max(x, y);
}

double slow(int n, int k1, int k2, vector<double> p1, vector<double> p2) {
    vector<vector<double> > dp(k1 + 1, vector<double>(k2 + 1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        auto ndp = dp;
        for (int j1 = 0; j1 <= k1; j1++) {
            for (int j2 = 0; j2 <= k2; j2++) {
                if (j1 < k1) {
                    upd(ndp[j1 + 1][j2], dp[j1][j2] + p1[i]);
                }
                if (j2 < k2) {
                    upd(ndp[j1][j2 + 1], dp[j1][j2] + p2[i]);
                }
                if (j1 < k1 && j2 < k2) {
                    upd(ndp[j1 + 1][j2 + 1], dp[j1][j2] + (1.0 - (1.0 - p1[i]) * (1.0 - p2[i])));
                }
            }
        }
        dp = ndp;
    }
    return dp[k1][k2];
}

double fast(int n, int k1, int k2, vector<double> p1, vector<double> p2) {
    auto solve2 = [&](double lambda1, double lambda2) {
        double dp = 0;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            double dp0 = dp;
            double dp1 = dp + p1[i] - lambda1;
            double dp2 = dp + p2[i] - lambda2;
            double dp3 = dp + (1.0 - (1.0 - p1[i]) * (1.0 - p2[i])) - lambda1 - lambda2;

            dp = max(max(dp0, dp1), max(dp2, dp3));
            if (dp == dp0) {

            } else if (dp == dp1) {
                c1++;
            } else if (dp == dp2) {
                c2++;
            } else if (dp == dp3) {
                c1++; c2++;
            }
        }
        return make_pair(dp, make_pair(c1, c2));
    };

    auto solve1 = [&](double lambda1) {
        double L = -INF, R = +INF;
        for (int it = 0; it < ITERS; it++) {
            double M = (L + R) / 2;

            auto o = solve2(lambda1, M);
            if (o.second.second < k2) R = M;
            else L = M;
        }
        auto res = solve2(lambda1, L);
        /*if (res.second.second != k2) {
            auto resR = solve2(lambda1, R);
            cerr << "here" << endl;
        }*/
        //assert(res.second.second == k2);
        res.first += L * k2;
        return res;
    };

    auto solve0 = [&]() {
        double L = -INF, R = +INF;
        for (int it = 0; it < ITERS; it++) {
            double M = (L + R) / 2;

            auto o = solve1(M);
            if (o.second.first < k1) R = M;
            else L = M;
        }
        auto res = solve1(L);
        res.first += L * k1;
        //assert(res.second.first == k1);
        return res;
    };

    return solve0().first;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n, k1, k2;
    while (cin >> n >> k1 >> k2) {
        vector<double> p1(n), p2(n);
        for (int i = 0; i < n; i++) cin >> p1[i];
        for (int i = 0; i < n; i++) cin >> p2[i];

        printf("%.15f\n", fast(n, k1, k2, p1, p2));
    }

    return 0;
}