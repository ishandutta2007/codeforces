//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, s, e, x[maxn], a[maxn], b[maxn], c[maxn], d[maxn], dp[maxn][maxn];

int main(){
    fast_io;

    cin >> n >> s >> e;
    s--;
    e--;
    for(ll i = 0; i < n; i++){
        cin >> x[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> c[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> d[i];
    }
    fill(dp[n], dp[n] + maxn, inf);
    dp[n][0] = 0;
    for(ll i = n; i--;){
        ll k;
        fill(dp[i], dp[i] + maxn, inf);
        if(i == s){
            for(ll j = 0; j <= n; j++){
                k = j;
                if(i <= s) k++;
                if(i <= e) k--;
                if(k < 0) continue;
                dp[i][j] = min(dp[i][j], d[i] - x[i] + dp[i + 1][j + 1]);
                if(k) dp[i][j] = min(dp[i][j], x[i] + c[i] + dp[i + 1][j]);
                if(i != 0 && j == 0 && k == 0) dp[i][j] = inf;
            }
        }
        else if(i == e){
            for(ll j = 0; j <= n; j++){
                k = j;
                if(i <= s) k++;
                if(i <= e) k--;
                if(k < 0) continue;
                dp[i][j] = min(dp[i][j], b[i] - x[i] + dp[i + 1][j]);
                if(j) dp[i][j] = min(dp[i][j], x[i] + a[i] + dp[i + 1][j - 1]);
                if(i != 0 && j == 0 && k == 0) dp[i][j] = inf;
            }
        }
        else{
            for(ll j = 0; j <= n; j++){
                k = j;
                if(i <= s) k++;
                if(i <= e) k--;
                if(k < 0) continue;
                dp[i][j] = min(dp[i][j], d[i] - x[i] + b[i] - x[i] + dp[i + 1][j + 1]);
                if(j) dp[i][j] = min(dp[i][j], d[i] - x[i] + x[i] + a[i] + dp[i + 1][j]);
                if(k) dp[i][j] = min(dp[i][j], x[i] + c[i] + b[i] - x[i] + dp[i + 1][j]);
                if(j && k) dp[i][j] = min(dp[i][j], x[i] + c[i] + x[i] + a[i] + dp[i + 1][j - 1]);
                if(i != 0 && j == 0 && k == 0) dp[i][j] = inf;
            }
        }
    }
    cout << dp[0][0] << '\n';
    return 0;
}