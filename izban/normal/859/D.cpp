#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 18;



int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        n = 1 << n;

        vector<vector<int> > a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        //vector<vector<vector<double> > > dp(n, vector<vector<double> >(n, vector<double>(n, 0.0)));
        vector<vector<double> > dp(n, vector<double>(n, 0.0));
        vector<vector<double> > p(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        for (int i = 0; i < n; i++) p[i][i] = 1;

        for (int k = 0; (1 << k) < n; k++) {
            int len = 1 << k;
            vector<vector<double> > ndp(n, vector<double>(n, 0.0));
            vector<vector<double> > np(n, vector<double>(n, 0.0));
            for (int i = 0; i < n; i += 2 * len) {
                for (int l = i; l < i + len; l++) {
                    ndp[i][l] = 0;
                    np[i][l] = 0;
                    double mx = 0;
                    double add = 0;
                    for (int r = i + len; r < i + 2 * len; r++) {
                        mx = max(mx, dp[i + len][r]);
                        add += p[i + len][r] * a[l][r] / 100.0;
                    }
                    np[i][l] = add * p[i][l];
                    ndp[i][l] = mx + p[i][l] * (add * len) + dp[i][l];
                }
                for (int r = i + len; r < i + 2 * len; r++) {
                    ndp[i][r] = 0;
                    np[i][r] = 0;
                    double mx = 0;
                    double add = 0;
                    for (int l = i; l < i + len; l++) {
                        mx = max(mx, dp[i][l]);
                        add += p[i][l] * a[r][l] / 100.0;
                    }
                    np[i][r] = add * p[i + len][r];
                    ndp[i][r] = mx + p[i + len][r] * (add * len) + dp[i + len][r];
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (ndp[i][j] < 1e-40) ndp[i][j] = 0;
                    if (np[i][j] < 1e-40) np[i][j] = 0;
                }
            }
            dp = ndp;
            p = np;
        }
        double ans = -1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[0][i]);
        }

        /*int sum = 0;
        for (int i = 0; (1 << i) < n; i++) {
            int m = 1 << i;
            sum += m * (n / 2 / m);
        }
        ans *= sum;*/
        printf("%.15f\n", ans);
    }


#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}