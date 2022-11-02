#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;
const int K = 4021;

double prob[2][K][222], pp[2], alive[2][K];

int hp[2], dt[2], l[2], r[2], p[2];

int main() {
    for (int i = 0; i < 2; ++i) {
        cin >> hp[i] >> dt[i] >> l[i] >> r[i] >> p[i];
        if (p[i] == 100) {
            cout << i << endl;
            exit(0);
        }
        pp[i] = p[i] / 100.;
    }
    for (int i = 0; i < 2; ++i) {
        prob[i][0][hp[i]] = 1.;
        for (int j = 0; j + 1 < K; ++j) {
            for (int k = 0; k <= hp[i]; ++k) {
                if (prob[i][j][k] < eps) continue;
                prob[i][j + 1][k] += prob[i][j][k] * pp[1 - i];
                double tprob = prob[i][j][k] * (1. - pp[1 - i]) /
                               (r[1 - i] - l[1 - i] + 1);
                for (int u = l[1 - i]; u <= r[1 - i]; ++u)
                    prob[i][j + 1][max(0, k - u)] += tprob;
            }
            for (int k = 1; k <= hp[i]; ++k) alive[i][j] += prob[i][j][k];
        }
    }
    double ans = 0.0;
    for (int i = 1; i < K; ++i) {
        int cc = max(0, ((i - 1) * dt[0] + dt[1] - 1) / dt[1]);
        if (cc >= K) break;
        double tp = alive[1][i - 1] - alive[1][i];
        double ap = alive[0][cc];
        ans += tp * ap;
    }
    printf("%.12f\n", ans);
    return 0;
}