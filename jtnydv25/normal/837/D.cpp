#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 205;
int x, y;
int dp[N][N * 26], dp2[N][N * 26];
bool poss[N][N * 26], poss2[N][N * 26];
ll a;
int main(){
    int n, K; cin >> n >> K;
    poss[0][0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> a; x = 0; y = 0;
        while(a % 2 == 0) x++, a >>= 1;
        while(a % 5 == 0) y++, a /= 5;
        memcpy(dp2, dp, sizeof dp);
        memcpy(poss2, poss, sizeof poss);
        for(int j = 0; j < i; j++){
            int lim = (i - 1) * 25;
            for(int k = 0; k <= lim; k++){
                if(poss2[j][k]){
                    dp[j + 1][k + y] = max(dp[j + 1][k + y], dp2[j][k] + x);
                    poss[j + 1][k + y] = 1;
                }
            }
        }
        // cerr << dp[1][2] << " " << dp[2][2] << endl;
    }
    int ans = 0;
    for(int i = 0; i <= 25 * n; i++) ans = max(ans, min(i, dp[K][i]));
    cout << ans;
}