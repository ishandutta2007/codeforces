#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    ll n;
    cin >> n;
    ll bits[310000];
    for(int i = 1; i <= n; i++){
        ll in;
        cin >> in;
        ll number = 0;
        for(int i = 0; i <= 60; i++){
            if((in >> i) & 1){
                number++;
            }
        }
        bits[i] = number;
        //cout << number << endl;
    }
    ll ans = 0;
    ll dp[2][310000];
    dp[0][0] = 0;
    dp[1][0] = 0;
    for(int i = 1; i <= n; i++){
        if((bits[i] % 2 )== 0){
            for(int j = 0; j <= 1; j++){
                dp[j][i] = dp[j][i - 1];
            }
            dp[0][i]++;
            ans += dp[0][i];
        } else {
            for(int j = 0; j <= 1; j++){
                dp[j][i] = dp[1 - j][i - 1];
            }
            dp[1][i]++;
            ans += dp[0][i];
        }
        //cout << ans << endl;
    }
    for(ll i = 1; i <= n; i++){
        ll sum = 0;
        ll maxi = 0;
        for(ll j = i; j <= min(n, i + 70); j++){
            sum += bits[j];
            //cout << maxi << " " << bits[j] << endl;
            maxi = max(maxi, bits[j]);
            //cout << maxi << endl;
            if((sum % 2) == 1){
                continue;
            }
            if((2 * maxi) > sum){
                //cout << i << " " << j << " " << sum << " " << maxi << endl;
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}