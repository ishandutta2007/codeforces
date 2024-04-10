#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

int dp[N+5][2];
int nxt[N+5][26][2];

void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for(int i=n; i>=0; i--){
        for(int j=0; j<26; j++){
            nxt[i][j][0] = nxt[i][j][1] = n+5;
        }
    }
    if(m > n){
        cout << "NO\n";
        return;
    }
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<26; j++){
            nxt[i][j][0] = nxt[i+1][j][0];
            nxt[i][j][1] = nxt[i+1][j][1];
        }
        int k = s[i+1] - 'a';
        nxt[i][k][(i+1)%2] = i+1;
    }
    for(int i=0; i<m; i++){
        dp[i][0] = dp[i][1] = N+5;
    }
    for(int i=0; i<n; i++){
        if(s[i] == t[0]){
            dp[0][i%2] = min(dp[0][i%2], i);
        }
    }
    for(int i=0; i<m-1; i++){
        int treba = t[i+1] - 'a';
        if(dp[i][1] < n) dp[i+1][0] = min(dp[i+1][0], nxt[dp[i][1]][treba][0]);
        if(dp[i][0] < n) dp[i+1][1] = min(dp[i+1][1], nxt[dp[i][0]][treba][1]);
    }
    if(dp[m-1][1 - n%2] < n) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}