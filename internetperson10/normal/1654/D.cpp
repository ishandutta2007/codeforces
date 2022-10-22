#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 998244353;

vector<vector<int>> primeFacts;
vector<int> powVals, powMins;
vector<vector<pair<int, pair<int, int>>>> adj;

ll modpow(ll n, ll e = MOD - 2) {
    if(e == 0) return 1;
    ll x = modpow(n, e/2);
    x *= x;
    x %= MOD;
    if(e%2) {
        x *= n;
        x %= MOD;
    }
    return x;
}

ll inv[200001];
ll ans;

void dfs(int i, int par = -1, ll nn = 1) {
    ans += nn;
    ans %= MOD;
    for(auto p : adj[i]) {
        int ch, x, y;
        pair<int, int> u;
        tie(ch, u) = p;
        tie(x, y) = u;
        ll nu = nn;
        if(ch == par) continue;
        for(int pr : primeFacts[x]) {
            powVals[pr]++;
            nu *= pr;
            nu %= MOD;
        }
        for(int pr : primeFacts[y]) {
            powVals[pr]--;
            powMins[pr] = min(powMins[pr], powVals[pr]);
            nu *= inv[pr];
            nu %= MOD;
        }
        dfs(ch, i, nu);
        for(int pr : primeFacts[x]) {
            powVals[pr]--;
        }
        for(int pr : primeFacts[y]) {
            powVals[pr]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    primeFacts.resize(200001);
    for(int i = 2; i <= 200000; i++) {
        inv[i] = modpow(i);
        if(primeFacts[i].size() == 0) {
            for(ll j = i; j <= 200000; j *= i) {
                for(int k = j; k <= 200000; k += j) {
                    primeFacts[k].push_back(i);
                }
            }
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        powVals.resize(n+1);
        powMins.resize(n+1);
        adj.resize(n);
        for(int i = 1; i < n; i++) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            u--; v--;
            adj[u].push_back({v, {y, x}});
            adj[v].push_back({u, {x, y}});
        }
        ans = 0;
        dfs(0);
        for(int i = 2; i <= n; i++) {
            ans *= modpow(i, abs(powMins[i]));
            ans %= MOD;
        }
        cout << ans << '\n';
        vector<int>().swap(powVals);
        vector<int>().swap(powMins);
        vector<vector<pair<int, pair<int, int>>>>().swap(adj);
    }
}