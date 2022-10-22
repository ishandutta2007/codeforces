#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int niz[100000];
ll dp[100000];

int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    for(int i=1; i<=n; i++){
        dp[i+1] = 2*dp[i]-dp[niz[i]]+2;
        dp[i+1] %= 1000000007;
    }
    if(dp[n+1] < 0) dp[n+1] += 1000000007;
    cout << dp[n+1]%1000000007;
    return 0;
}