#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int INF = 1e9+5;

int n, m, k;

int main () {
    scanf("%d %d %d", &n, &m, &k);

    //vector<vector<vector<int>>> test(3, vector<int>(3, vector<int>));

    vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(m+1, vector<vector<int>>(73, vector<int>(73, -INF))));
    dp[0][0][0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);

            for (int cnt = 0; cnt < 71; cnt++) {
                for (int rem = 0; rem < 71; rem++) {
                    if (j == m-1) {
                        // nie bierzemy
                        dp[i+1][0][0][rem] = max(dp[i+1][0][0][rem], dp[i][j][cnt][rem]);

                        // bierzemy (jesli mozna)
                        if (cnt + 1 <= m/2) {
                            dp[i+1][0][0][(rem+x)%k] = max(dp[i+1][0][0][(rem+x)%k], dp[i][j][cnt][rem]+x);
                        }
                    }
                    else {
                        // nie bierzemy tego elementu
                        dp[i][j+1][cnt][rem] = max(dp[i][j+1][cnt][rem], dp[i][j][cnt][rem]);

                        // bierzemy (jesli mozna)
                        if (cnt + 1 <= m/2) {
                            dp[i][j+1][cnt+1][(rem+x)%k] = max(dp[i][j+1][cnt+1][(rem+x)%k], dp[i][j][cnt][rem]+x);
                        }
                    }
                }
            }
        }
    }



    printf("%d\n", max(0, dp[n][0][0][0]));
	return 0;
}