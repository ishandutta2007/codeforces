#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
// #define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int dp[1005][1005];
int n, k;

int calc(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(j == 0 || i == 1){
        dp[i][j] = 1;
        return dp[i][j];
    }
    dp[i][j] = calc(i, j - 1) + calc(i - 1, n - j);
    dp[i][j] %= mod;
    return dp[i][j];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> k;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= k; j++){
                dp[j][i] = -1;
            }
        }
        cout << calc(k, n) << endl;
    }
}