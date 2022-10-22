#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000;
const int C = 1000000;

int mnt[N+5];
int dp[C+5];
int b[N+5], c[N+5];

void solve(){
    int n, k;
    cin >> n >> k;
    int g = 0;
    for(int i=1; i<=n; i++) cin >> b[i], g += mnt[b[i]];
    k = min(k, g);
    for(int i=0; i<=k; i++) dp[i] = 0;
    for(int i=1; i<=n; i++) cin >> c[i];
    for(int i=1; i<=n; i++){
        for(int j=k; j>=mnt[b[i]]; j--){
            dp[j] = max(dp[j], dp[j - mnt[b[i]]] + c[i]);
        }
    }
    for(int i=1; i<=k; i++) dp[i] = max(dp[i], dp[i-1]);
    cout << dp[k] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    for(int i=2; i<=N; i++) mnt[i] = i;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            if(i + i/j <= N) mnt[i + i/j] = min(mnt[i + i/j], mnt[i] + 1);
        }
    }
    while(t--) solve();
    return 0;
}