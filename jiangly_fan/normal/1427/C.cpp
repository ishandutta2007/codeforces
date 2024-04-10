#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int t[maxn], x[maxn], y[maxn];
int dp[maxn], mdp[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, n;
    cin >> r >> n;
    x[0] = y[0] = 1;
    for(int i = 1; i <= n; i += 1)
        cin >> t[i] >> x[i] >> y[i];
    r *= 2;
    for(int i = 1; i <= n; i += 1){
        if(i >= r) dp[i] = mdp[i - r] + 1;
        else dp[i] = -maxn;
        for(int j = max(i - r, 0); j < i; j += 1)
            if(dp[i] <= dp[j])
                if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
                    dp[i] = dp[j] + 1;
        mdp[i] = max(dp[i], mdp[i - 1]);
    }
    cout << mdp[n];
    return 0;
}