#include <bits/stdc++.h>
using namespace std;

int niz[200005];
int pre[200005];
int dp[200005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        pre[i] = pre[i-1] + niz[i];
    }
    int mx = pre[n] - dp[n];
    for(int i=n-1; i>=1; i--){
        dp[i] = mx;
        mx = max(mx, pre[i]-dp[i]);
    }
    cout << dp[1];
    return 0;
}