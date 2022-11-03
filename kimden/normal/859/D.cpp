#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int k = (1 << n);
    vector<vector<ld>> w(k, vector<ld>(k));
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < k; ++j){
            cin >> w[i][j];
            w[i][j] *= 0.01;
        }
    }
    ld p[100][100];
    ld dp[100][100];
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            p[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    int step = 2;
    int l = k - 2;
    int r = k - 1;
    int mid = (l + r) >> 1;
    for(int i = k - 2; i >= 0; --i){
        if(step > 2) {
            for (int j = l; j <= r; ++j) {
                if (j <= mid) {
                    ld mx = 0;
                    for (int o = mid + 1; o <= r; ++o) {
                        p[i][j] += p[2 * i + 1][j] * p[2 * i + 2][o] * w[j][o];
                        dp[i][j] += p[2 * i + 1][j] * p[2 * i + 2][o] * w[j][o] * (step * 0.5);
                        mx = max(mx, dp[2 * i + 2][o]);
                         /*
                        if(p[2 * i + 2][o] * w[j][o] * (step * 0.5 + dp[2 * i + 2][o]) > dp[i][j]){
                            dp[i][j] = p[2 * i + 2][o] * w[j][o] * (step * 0.5 + dp[2 * i + 2][o]);
                            p[i][j] = p[2 * i + 2][o] * w[j][o];
                        }*/
                    }
                    dp[i][j] += dp[2 * i + 1][j] + mx;
                } else {
                    ld mx = 0;
                    for (int o = l; o <= mid; ++o) {
                        p[i][j] += p[2 * i + 2][j] * p[2 * i + 1][o] * w[j][o];
                        dp[i][j] += p[2 * i + 2][j] * p[2 * i + 1][o] * w[j][o] * (step * 0.5);
                        mx = max(mx, dp[2 * i + 1][o]);
//                        if(p[2 * i + 1][o] * w[j][o] * (step * 0.5 + dp[2 * i + 1][o]) > dp[i][j]){
//                            dp[i][j] = p[2 * i + 1][o] * w[j][o] * (step * 0.5 + dp[2 * i + 1][o]);
//                            p[i][j] = p[2 * i + 1][o] * w[j][o];
//                        }
                    }
                    dp[i][j] += dp[2 * i + 2][j] + mx;
                }
            }
        }else{
            p[i][l] = w[l][r];
            p[i][r] = w[r][l];
            dp[i][l] = w[l][r];
            dp[i][r] = w[r][l];
        }

        if(i == 0){
            break;
        }
        r = l - 1;
        l = r - step + 1;
        if(r < 0){
            step <<= 1;
            r = k - 1;
            l = r - step + 1;
        }
        mid = (l + r) >> 1;
    }
    ld ans = 0;
    for(int i = 0; i < k; ++i){
        ans = max(ans, dp[0][i]);
    }
    cout << setprecision(17) << fixed << ans << endl;
    return 0;
}