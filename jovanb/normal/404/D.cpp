#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

ll add(ll a, ll b){
    return (a+b)%MOD;
}

ll dp[1000005][10];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    int n = s.size();
    if(s[0] == '0') dp[1][0] = 1;
    if(s[0] == '1') dp[1][1] = 1;
    if(s[0] == '*') dp[1][4] = 1;
    if(s[0] == '?'){
        dp[1][0] = 1;
        dp[1][1] = 1;
        dp[1][4] = 1;
    }
    for(int i=2; i<=n; i++){
        if(s[i-1] == '0'){
            dp[i][0] = add(dp[i][0], dp[i-1][0]);
            dp[i][0] = add(dp[i][0], dp[i-1][3]);
        }
        else if(s[i-1] == '1'){
            dp[i][1] = add(dp[i][1], dp[i-1][0]);
            dp[i][1] = add(dp[i][1], dp[i-1][3]);
            dp[i][3] = add(dp[i][3], dp[i-1][4]);
        }
        else if(s[i-1] == '2'){
            dp[i][2] = add(dp[i][2], dp[i-1][4]);
        }
        else if(s[i-1] == '*'){
            dp[i][4] = add(dp[i][4], dp[i-1][2]);
            dp[i][4] = add(dp[i][4], dp[i-1][1]);
            dp[i][4] = add(dp[i][4], dp[i-1][4]);
        }
        else{
            dp[i][0] = add(dp[i][0], dp[i-1][0]);
            dp[i][0] = add(dp[i][0], dp[i-1][3]);
            dp[i][1] = add(dp[i][1], dp[i-1][0]);
            dp[i][1] = add(dp[i][1], dp[i-1][3]);
            dp[i][3] = add(dp[i][3], dp[i-1][4]);
            dp[i][2] = add(dp[i][2], dp[i-1][4]);
            dp[i][4] = add(dp[i][4], dp[i-1][2]);
            dp[i][4] = add(dp[i][4], dp[i-1][1]);
            dp[i][4] = add(dp[i][4], dp[i-1][4]);
        }
    }
    ll res = 0;
    res = add(res, dp[n][4]);
    res = add(res, dp[n][3]);
    res = add(res, dp[n][0]);
    cout << res;
    return 0;
}