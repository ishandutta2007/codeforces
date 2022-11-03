#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i){
        cin >> h[i];
//        h[i] = (i % 2 == 0 ? 0 : 100000);
    }
    vector<int> a(n), b(n);
    a[0] = b[n - 1] = 0;
    for(int i = 0; i < n - 1; ++i){
        a[i + 1] = max(0, h[i] - h[i + 1] + 1);
        b[i] = max(0, h[i + 1] - h[i] + 1);
    }
    const int N = 5006;
    const int INF = 1'001'001'003;
    vector<vector<int>> dp(N, vector<int>(N, INF));
    vector<vector<int>> mn(N, vector<int>(N, INF));
    /*int dp[N][N], mn[N][N];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            dp[i][j] = mn[i][j] = INF;
        }
    }*/
    dp[0][0] = 0;
    mn[0][0] = mn[1][0] = mn[2][0] = 0;
    for(int i = 3; i < n + 3; ++i){
        mn[i][0] = 0;
        for(int j = 1; j <= (n + 1) / 2; ++j){
            dp[i][j] = a[i - 3] + b[i - 3] + mn[i - 3][j - 1];
            if(i >= 5){
                dp[i][j] = min(dp[i][j], b[i - 3] + max(0, a[i - 3] - b[i - 5]) + dp[i - 2][j - 1]);
            }
            dp[i][j] = min(dp[i][j], INF);
            mn[i][j] = min(mn[i - 1][j], dp[i][j]);
//            cerr << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }
    for(int i = 1; i <= (n + 1) / 2; ++i){
        if(i > 1){
            cout << " ";
        }
        cout << mn[n + 2][i];
    }
    cout << endl;
    return 0;
}