//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 4010;
const ll tof = 90;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, a[maxn], ps[maxn], x;
unordered_map<ll, ll> dp[2][tof][maxn];

void solve(ll l, ll r, ll k, ll f){
    if(dp[f][k][l].find(r) != dp[f][k][l].end()|| l + k - 1 > r) return;
    if(f){
        solve(l, r - k, k, 0);
        solve(l, r - k - 1, k + 1, 0);
        x = inf;
        if(r - k >= l - 1){
            x = min(x, dp[0][k][l][r - k] - ps[r] + ps[r - k]);
        }
        if(r - k - 1 >= l - 1){
            x = min(x, dp[0][k + 1][l][r - k - 1] - ps[r] + ps[r - k - 1]);
        }
        dp[f][k][l][r] = x;
    }
    else{
        solve(l + k, r, k, 1);
        solve(l + k + 1, r, k + 1, 1);
        x = -inf;
        if(l + k <= r + 1){
            x = max(x, dp[1][k][l + k][r] + ps[l + k - 1] - ps[l - 1]);
        }
        if(l + k + 1 <= r + 1){
            x = max(x, dp[1][k + 1][l + k + 1][r] + ps[l + k] - ps[l - 1]);
        }
        dp[f][k][l][r] = x;
    }
    //cout << "? " << f << " " << k << " " << l << " " << r << " => " << dp[f][k][l][r] << '\n';
    return;
}

int main(){
    fast_io;

    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    solve(1, n, 1, 0);
    cout << dp[0][1][1][n];

    return 0;
}