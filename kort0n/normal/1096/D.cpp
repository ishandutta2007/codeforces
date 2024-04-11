#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e16)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n;
    string s;
    cin >> n;
    cin >> s;
    s = "#" + s;
    ll a[100500];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll dp[100500][4];
    string hard = "hard";
    for(int i = 0; i <= 3; i++){
        dp[0][i] = 0;
    }
    for(int index = 1; index <= n; index++){
        for(int i = 0; i <= 3; i++){
            dp[index][i] = INF;
            if(i > 0){
                dp[index][i] = min(dp[index][i], dp[index - 1][i - 1]);
            }
            dp[index][i] = min(dp[index][i], dp[index - 1][i] + a[index]);
            if(s[index] != hard[i]){
                dp[index][i] = min(dp[index][i], dp[index - 1][i]);
            }
        }
    }
    ll ans = INF;
    for(int i = 0; i <= 3; i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}