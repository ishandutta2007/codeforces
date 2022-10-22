#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll dp[100005][2];
ll l[100005];
ll r[100005];
vector <int> graf[100005];

void dfs(int v, int p){
    dp[v][0] = dp[v][1] = 0;
    for(auto c : graf[v]){
        if(c == p) continue;
        dfs(c, v);
        dp[v][0] += max(dp[c][0] + abs(l[c] - l[v]), dp[c][1] + abs(r[c] - l[v]));
        dp[v][1] += max(dp[c][0] + abs(l[c] - r[v]), dp[c][1] + abs(r[c] - r[v]));
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> l[i] >> r[i];
        graf[i].clear();
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";
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