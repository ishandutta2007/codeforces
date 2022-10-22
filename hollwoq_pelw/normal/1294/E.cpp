#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++){
        vector<int> dp(n, n);
        int res = 1e9;
        for (int j = 0; j < n; j++){
            int x = a[j][i] - 1; // pos of x = (x / m, x % m);
            if (x % m == i % m && x / m < n){
                dp[(j + n - x / m) % n] --;
            }
        }
        for (int i = 0; i < n; i++){
            res = min(res, dp[i] + i);
        //    cout << dp[i] << ' ';
        }
        //cout << "# " << res << endl;
        ans += res;
    }
    cout << ans;
}