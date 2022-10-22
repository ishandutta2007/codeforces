#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

ll res = 1000000000000000000LL;

ll gmx;
ll dp[N+5], h[N+5], mx1[N+5], mx2[N+5];

vector <int> graf[N+5];

void dfs_calc(int v, int p){
    for(auto c : graf[v]){
        if(c == p) continue;
        dfs_calc(c, v);
        if(max(h[c], mx1[c]) > mx1[v]){
            swap(mx1[v], mx2[v]);
            mx1[v] = max(h[c], mx1[c]);
        }
        else if(max(h[c], mx1[c]) > mx2[v]){
            mx2[v] = max(h[c], mx1[c]);
        }
        dp[v] += dp[c];
    }
    dp[v] += max(0LL, h[v] - mx1[v]);
}

void dfs(int v, int p, ll mxp, ll sump){
    ll sum = sump + gmx;
    ll sumd = 0;
    for(auto c : graf[v]) if(c != p) sumd += dp[c];
    res = min(res, sum + sumd + max(0LL, gmx - max(mxp, mx1[v])));
    for(auto c : graf[v]){
        if(c == p) continue;
        ll dmx = mxp;
        if(max(h[c], mx1[c]) == mx1[v]) dmx = max(dmx, mx2[v]);
        else dmx = max(dmx, mx1[v]);
        sumd -= dp[c];
        dfs(c, v, max(dmx, h[v]), sumd + sump + max(0LL, h[v] - dmx));
        sumd += dp[c];
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> h[i];
        gmx = max(gmx, h[i]);
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs_calc(1, 0);
    dfs(1, 0, 0, 0);
    cout << res << "\n";
    return 0;
}