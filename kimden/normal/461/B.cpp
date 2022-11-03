#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<vector<int>> g;
vector<int> a;
const int mod = 1'000'000'007;
vector<ll> dp0, dp1;

int binpow(int x, int p){
    x %= mod;
    int ans = 1;
    while(p) {
        if (p & 1){
            ans = (ans * ll(x)) % mod;
        }
        x = (x * ll(x)) % mod;
        p >>= 1;
    }
    return ans;
}

int inv(int x) {
    return binpow(x, mod - 2);
}

void dfs(int v) {
    int prod = 1;
    int sum = 0;
    for(auto u: g[v]){
        dfs(u);
        prod = (prod * ll(dp0[u] + dp1[u])) % mod;
        sum = (sum + ll(dp1[u]) * inv(dp0[u] + dp1[u])) % mod;
    }
    if (a[v] == 0) {
        dp0[v] = prod;
        dp1[v] = (prod * ll(sum)) % mod;
    }else{
        dp1[v] = prod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    g.resize(n);
    a.resize(n);
    dp0.resize(n, 0);
    dp1.resize(n, 0);
    for(int i = 1; i < n; ++i){
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    dfs(0);
    cout << dp1[0] << endl;
}