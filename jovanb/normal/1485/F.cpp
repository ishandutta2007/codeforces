#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map <ll, int> dp;

const int MOD = 1000000007;

int add(int a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int sub(int a, int b){
    return add(a, MOD-b);
}

void solve(){
    int n;
    cin >> n;
    dp.clear();
    dp[0] = 1;
    ll sums = 0;
    ll sumdp = 1;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        ll g = sub(sumdp, dp[sums]);
        sumdp = add(sumdp, g);
        dp[sums] = add(dp[sums], g);
        sums += x;
    }
    int res = 0;
    for(auto c : dp) res = add(res, c.second);
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}