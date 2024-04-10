#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <pair <int, int>> graf[500005];
ll dp[500005][2];

int n, k;

void dfs(int v, int parent){
    ll sum = 0;
    vector <ll> vec;
    for(auto c : graf[v]){
        if(c.first == parent) continue;
        dfs(c.first, v);
        vec.push_back(dp[c.first][1]+c.second-dp[c.first][0]);
        sum += dp[c.first][0];
    }
    dp[v][0] = dp[v][1] = sum;
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    int x = vec.size();
    if(x < k){
        for(int j=0; j<x; j++){
            dp[v][0] += max(0LL, vec[j]);
        }
        dp[v][1] = dp[v][0];
        return;
    }
    for(int j=0; j<k-1; j++){
        dp[v][0] += max(0LL, vec[j]);
    }
    dp[v][1] = dp[v][0];
    dp[v][0] += max(0LL, vec[k-1]);
}

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        graf[i].clear();
    }
    for(int i=1; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}