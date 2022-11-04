#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    if(min(n, m) > 3) {
        cout << -1;
        return 0;
    }
    vector<vector<int>> a(max(n, m), vi(min(n, m)));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            int here = 1;
            if(c == '0') {
                here = 0;
            }
            if(n == max(n, m)) {
                a[i][j] = here;
            } else {
                a[j][i] = here;
            }
        }
    }
    if(min(n, m) == 1) {
        cout << 0;
        return 0;
    }
    vvi dp(max(n, m), vi(8, INF));
    for(int i = 0; i < max(n, m); i++) {
        for(int mask = 0; mask < 8; mask++) {
            if(max(n, m) == 2) {
                if((mask >> 3) & 1) {
                    continue;
                }
            }
            int here = 0;
            for(int j = 0; j < min(n, m); j++) {
                here += a[i][j] ^ ((mask >> j) & 1);
            }
            //cout << here << endl;
            if(i == 0) {
                dp[i][mask] = here;
                continue;
            }
            for(int mask1 = 0; mask1 < 8; mask1++) {
                if(max(n, m) == 2) {
                    if((mask1 >> 3) & 1) {
                        continue;
                    }
                }
                bool ok = true;
                for(int k = 0; k < min(n, m) - 1; k++) {
                    int sumhere = 0;
                    for(int l = 0; l < 2; l++) {
                        sumhere += ((mask >> (k + l)) & 1);
                        sumhere += ((mask1 >> (k + l)) & 1);
                    }
                    if(sumhere % 2 == 0) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    dp[i][mask] = min(dp[i][mask], dp[i - 1][mask1] + here);
                }
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < 8; i++) {
        ans = min(ans, dp[max(n, m) - 1][i]);
    }
    cout << ans;
}