#include <bits/stdc++.h>
using namespace std;

const int mod = 1'000'000'007;

void ad(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

map<int, int> dp[2005][2];

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int x=0, y=0;
    for (char c : s) {
        if (c == '(') {
            y++;
        } else {
            y--;
        }
        x = min(x, y);
    }
    // x je min pad, y je ceo balans
    
    if (n == m) {
        cout << (y == 0 && x == 0) << '\n';
        return 0;
    }
    
    dp[0][0][0] = 1;
    for (int i=0; i<=n-m; i++) {
        for (int j=0; j<2; j++) {
            for (auto [b, v] : dp[i][j]) {
                // dodaj ceo string
                if (j == 0 && b + x >= 0) {
                    ad(dp[i][j+1][b + y], v);
                }
                // dodaj otvr
                ad(dp[i+1][j][b+1], v);
                // dodaj zatv
                if (b-1 >= 0) {
                    ad(dp[i+1][j][b-1], v);
                }
            }
        }
    }
    cout << dp[n-m][1][0] << '\n'; 
}