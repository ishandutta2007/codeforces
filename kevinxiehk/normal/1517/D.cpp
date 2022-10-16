#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
using namespace std;
int n, m, k;
bool valid(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}
void solve() {
    cin >> n >> m >> k;
    int dp[n + 5][m + 5][25];
    int dy[n + 5][m + 5];
    int dx[n + 5][m + 5];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) for(int kk = 0; kk <= k; kk++) dp[i][j][kk] = (kk == 0 ? 0 : 100000000);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) cin >> dy[i][j];
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) cin >> dx[i][j];
    }
    if(k % 2 == 1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << "-1 ";
            }
            cout << '\n';
        }
        return;
    }
    int dp2[n + 5][m + 5][k + 5];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) for(int kk = 0; kk <= k; kk++) dp2[i][j][kk] = (kk == 0 ? 0 : 100000000);
    }
    for(int x = 1; x <= k / 2; x++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(valid(i, j - 1)) dp2[i][j][x] = min(dp2[i][j][x], dp2[i][j - 1][x - 1] + dy[i][j - 1] * 2);
                if(valid(i, j + 1)) dp2[i][j][x] = min(dp2[i][j][x], dp2[i][j + 1][x - 1] + dy[i][j] * 2);
                if(valid(i - 1, j)) dp2[i][j][x] = min(dp2[i][j][x], dp2[i - 1][j][x - 1] + dx[i - 1][j] * 2);
                if(valid(i + 1, j)) dp2[i][j][x] = min(dp2[i][j][x], dp2[i + 1][j][x - 1] + dx[i][j] * 2);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << dp2[i][j][k / 2] << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    //cin >> t;
    
    while(t--) solve();
    return 0;
}