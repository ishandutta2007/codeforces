#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
using namespace std;
int n, m,v, k, ans;
__V<vi> g;
vi dp, dps, p;

void dfspre(int v) {
    dps[v] = 1;
    p.pb(v);
    if(dp[v] == -1) dp[v] = p.size() - 1;
    for(auto& i : g[v]) {
        dfspre(i);
        dps[v] += dps[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    dp.resize(n + 1, -1);
    dps.resize(n + 1, 0);
    for(int i = 2; i <= n; i++)
        cin >> v, g[v].pb(i);
    dfspre(1);
    while(m--) {
        cin >>v >> k;
        if(dps[v] < k)
            ans = -1;
        else
            ans = p[dp[v] + k - 1];
        cout << ans << "\n";
    }
}