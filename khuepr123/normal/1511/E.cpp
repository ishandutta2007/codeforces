#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 998244353;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, m;
int x, y, z, k;
int dp[maxN];
int pw[maxN];

int calc(int i){
    if(dp[i] != -1) return dp[i];
    dp[i] = calc(i - 1) + 2 * calc(i - 2) + pw[i - 2];
    dp[i] %= mod;
    return dp[i];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int a[n + 5][m + 5];
    char c;
    dp[0] = -1;
    pw[0] = 1;
    for(int i = 1; i < maxN; i++){
        dp[i] = -1;
        pw[i] = (pw[i - 1] * 2) % mod;
    }
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    int ans = 0;
    int ff = 0;
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= m + 1; j++){
            a[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c;
            a[i][j] = (c == 'o');
            ff = ff + (c == 'o');
        }
    }
    
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= m + 1; j++){
            if(a[i][j]) cnt++;
            else{
                ans += (pw[ff - cnt] * calc(cnt));
                ans %= mod;
                cnt = 0;
            }
        }
        // cout << ans << endl;
    }
    // cout << endl;
    for(int j = 1; j <= m; j++){
        int cnt = 0;
        for(int i = 1; i <= n + 1; i++){
            if(a[i][j]) cnt++;
            else{
                ans += (pw[ff - cnt] * calc(cnt));
                ans %= mod;
                cnt = 0;
            }
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
}