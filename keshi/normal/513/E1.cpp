//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3e4 + 100;
const ll maxk = 210;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, a[maxn], dp[maxn][maxk][3][2];

int main(){
    fast_io;

    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        for(ll j = 1; j <= m; j++){
            for(ll k = 0; k < 3; k++){
                for(ll o = 0; o < 2; o++){
                   dp[i][j][k][o] = -inf;
                }
            }
            if(j > i){
                continue;
            }
            for(ll k = 0; k < 2; k++){
                for(ll o = 0; o < 2; o++){
                    dp[i][j][k][o] = max(dp[i - 1][j][k][o], dp[i - 1][j - 1][0][1 - k]);
                    dp[i][j][k][o] = max(dp[i][j][k][o], max(dp[i - 1][j - 1][1][1 - k], dp[i - 1][j - 1][2][1 - k]));
                    if(j != 1){
                        dp[i][j][k][o] += a[i] * (2 * k - 1);
                    }
                    if(j != m){
                        dp[i][j][k][o] += a[i] * (2 * o - 1);
                    }
                }
            }
            if(j < i){
                for(ll o = 0; o < 2; o++){
                    dp[i][j][2][o] = max(dp[i - 1][j][0][o], max(dp[i - 1][j][1][o], dp[i - 1][j][2][o]));
                }
            }
        }
    }
    ll ans = 0;
    for(ll k = 0; k < 3; k++){
        for(ll o = 0; o < 2; o++){
           ans = max(ans, dp[n][m][k][o]);
        }
    }
    cout << ans;


    return 0;
}