#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int dp[64][64][64][41];

bool valid(int n, int x, int y, int z) {
    for(int i = 0; i < n; i++) {
        if(x & (1 << i)) continue;
        if(y & (1 << i)) continue;
        if(z & (1 << i)) continue;
        if(i == 0 && !(y & (1 << 1))) return false;
        if(i == 0) continue;
        if(i == n-1 && !(y & (1 << (n-2)))) return false;
        if(i == n-1) continue;
        if(y & (1 << (i-1))) continue;
        if(y & (1 << (i+1))) continue;
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if(n > m) swap(n, m);
    if(m == 1) {
        cout << "0\n";
        return 0;
    }
    if(m == 2) {
        if(n == 1) cout << "1\n";
        else cout << "2\n";
        return 0;
    }
    if(n == 1) {
        cout << m - (m+2)/3 << '\n';
        return 0;
    }
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < (1 << n); j++) {
            for(int k = 0; k < (1 << n); k++) {
                if(!valid(n, i, j, k) || !valid(n, 0, i, j)) dp[i][j][k][3] = 999;
                else dp[i][j][k][3] = __builtin_popcount(i) + __builtin_popcount(j) + __builtin_popcount(k);
            }
        }
    }
    for(int x = 4; x <= m; x++) {
        for(int i = 0; i < (1 << n); i++) {
            for(int j = 0; j < (1 << n); j++) {
                for(int k = 0; k < (1 << n); k++) {
                    dp[i][j][k][x] = 999;
                    if(valid(n, i, j, k)) {
                        for(int l = 0; l < (1 << n); l++) {
                            dp[i][j][k][x] = min(
                                dp[i][j][k][x],
                                dp[l][i][j][x-1] + __builtin_popcount(k)
                            );
                        }
                    }
                }
            }
        }
    }
    int ans = 999;
    for(int j = 0; j < (1 << n); j++) {
        for(int k = 0; k < (1 << n); k++) {
            if(valid(n, j, k, 0)) {
                for(int i = 0; i < (1 << n); i++) {
                    ans = min(ans, dp[i][j][k][m]);
                }
            }
        }
    }
    cout << n * m - ans << '\n';
}