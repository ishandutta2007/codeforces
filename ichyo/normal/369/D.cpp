#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
const int INF = 1000000;
void update(int& x, int y){
    if(x > y) x = y;
}

int main(){
    int n, k;
    while(cin >> n >> k){
        vector<int> p(n);
        REP(i, n) cin >> p[i];
        int p_max[3001] = {};
        for(int i = n - 1; i >= 0; i--){
            p_max[i] = max(p_max[i + 1], p[i]);
        }

        static int dp[3002][3002] = {}; // [1st][2nd]
        REP(i, n + 2) REP(j, n + 2) dp[i][j] = INF;
        dp[0][1] = 0;

        for(int f = 0; f < n; f++){
            for(int s = f + 1; s < n; s++){
                int prob1 = p_max[s];
                int prob2 = p[f];
                if(prob1 > 0 && prob2 < 100) update(dp[s][s + 1], dp[f][s] + 1);
                if(prob1 > 0 && prob2 > 0) update(dp[s + 1][s + 2], dp[f][s] + 1);
                if(prob1 < 100 && prob2 > 0) update(dp[f][s + 1], dp[f][s] + 1);
            }
        }

        int ans = 0;
        for(int f = 0; f < n; f++){
            for(int s = f + 1; s <= n; s++){
                if(dp[f][s] <= k){
                    ans ++;
                }
            }
        }
        if(dp[n][n + 1] <= k) ans++;
        cout << ans << endl;
    }
    return 0;
}