#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 201;

double dp[MAXN][MAXN];
double ndp[MAXN][MAXN];
//double sdp[MAXN][MAXN];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int h1, d1, l1, r1, p1;
    int h2, d2, l2, r2, p2;
    int test = 0;
    while (cin >> h1 >> d1 >> l1 >> r1 >> p1 >> h2 >> d2 >> l2 >> r2 >> p2) {
        test++;

        p1 = 100 - p1;
        p2 = 100 - p2;

        if (p1 == 0) {
            cout << 0 << endl;
            continue;
        }
        if (p2 == 0) {
            cout << 1 << endl;
            continue;
        }

        int o = d1 / __gcd(d1, d2) * d2; 
        vector<int> tm;
        for (int i = 0; i < o; i += d1) tm.push_back(i);
        for (int i = 0; i < o; i += d2) tm.push_back(i);

        sort(tm.begin(), tm.end());
        for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
            dp[i][j] = 0.0;
            ndp[i][j] = 0.0;
        } 
        dp[h1][h2] = 1.0;
        ndp[h1][h2] = 1.0;

        double ans = 0;
        int ii = 0;
        int i = 0;
        while (1) {
            double curTime = clock() / (double)CLOCKS_PER_SEC;
            if (curTime > 1.95 * test * 0.5) break;
            
            int turn;
            if (i == 0) turn = 0;
            else if (i == 1) turn = 1;
            else if (tm[i] % d1 == 0) turn = 0;
            else turn = 1;

            int cl, cr;
            if (turn == 0) cl = l1, cr = r1;
            else cl = l2, cr = r2;
            
            double pr1 = 1.0 / (cr - cl + 1);
            double pr2;
            if (turn == 0) pr2 = p1 / 100.0;
            else pr2 = p2 / 100.0;

            double opr2 = 1 - pr2;
            for (int c1 = 0; c1 <= h1; c1++) for (int c2 = 0; c2 <= h2; c2++) {
                ndp[c1][c2] *= opr2;
            }
            double X = pr1 * pr2;
            if (turn == 0) {
                for (int c1 = 0; c1 <= h1; c1++) {
                    for (int c2 = 1; c2 <= h2; c2++) {
                        dp[c1][c2] += dp[c1][c2 - 1];
                    }
                }
                for (int nc2 = -cr; nc2 <= h2; nc2++) {
                    int c2 = max(0, nc2);
                    int R = max(0, min(h2, nc2 + cr));
                    int L = max(0, min(h2, nc2 + cl - 1));
                    if (L != R) for (int c1 = 0; c1 <= h1; c1++) {
                        ndp[c1][c2] += (dp[c1][R] - dp[c1][L]) * X;
                    }
                }
            } else {
                for (int c2 = 0; c2 <= h2; c2++) {
                    for (int c1 = 1; c1 <= h1; c1++) {
                        dp[c1][c2] += dp[c1 - 1][c2];
                    }
                }
                for (int nc1 = -cr; nc1 <= h1; nc1++) {
                    int c1 = max(nc1, 0);
                    int R = max(0, min(h1, nc1 + cr));
                    int L = max(0, min(h1, nc1 + cl - 1));
                    if (L != R) for (int c2 = 0; c2 <= h2; c2++) {
                        ndp[c1][c2] += (dp[R][c2] - dp[L][c2]) * X;
                    }
                }
            }
            if (i != 0) {
                for (int c1 = 0; c1 <= h1; c1++) {
                    ans += ndp[c1][0]; 
                }
                for (int c1 = 0; c1 <= h1; c1++) ndp[c1][0] = 0;
                for (int c2 = 0; c2 <= h2; c2++) ndp[0][c2] = 0; 
            }
            memcpy(dp, ndp, sizeof(dp)); // 2
            i = (i + 1) % tm.size();
            ii++;
        }
        cerr << ii << endl;
        printf("%.15f\n", ans);
    }

    return 0;
}