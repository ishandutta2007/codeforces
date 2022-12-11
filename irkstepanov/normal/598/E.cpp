#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

const int INF = 100000000;
const int nmax = 31;
const int kmax = 51;

int main()
{

    vector<vector<vector<int> > > dp(nmax, vector<vector<int> > (nmax, vector<int>(kmax)));
    for (int n = 0; n < nmax; ++n) {
        for (int m = 0; m < nmax; ++m) {
            for (int k = 0; k < kmax; ++k) {
                dp[n][m][k] = INF;
            }
        }
    }

    for (int n = 1; n < nmax; ++n) {
        for (int m = 1; m < nmax; ++m) {
            for (int k = 0; k <= min(n * m, kmax - 1); ++k) {
                if (!k) {
                    dp[n][m][k] = 0;
                    continue;
                }
                if (n * m == k) {
                    dp[n][m][k] = 0;
                    continue;
                }
                if (n == 1 || m == 1) {
                    dp[n][m][k] = 1;
                    continue;
                }
                for (int x = 1; x < n; ++x) {
                    int ans = INF;
                    for (int z = 0; z <= k; ++z) {
                        ans = min(ans, m * m + dp[x][m][z] + dp[n - x][m][k - z]);
                    }
                    dp[n][m][k] = min(dp[n][m][k], ans);
                }
                for (int y = 1; y < m; ++y) {
                    int ans = INF;
                    for (int z = 0; z <= k; ++z) {
                        ans = min(ans, n * n + dp[n][y][z] + dp[n][m - y][k - z]);
                    }
                    dp[n][m][k] = min(dp[n][m][k], ans);
                }
            }
        }
    }

    int tt;
    scanf("%d", &tt);

    while (tt--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        printf("%d\n", dp[n][m][k]);
    }

}