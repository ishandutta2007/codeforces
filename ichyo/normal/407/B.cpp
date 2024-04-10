#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    const int MOD = 1000000007;
    const int MAX = 1024;
    long long dp[MAX] = {};
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        p--;
        dp[i + 1] = (2 * dp[i] - dp[p] + 2 + MOD) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}