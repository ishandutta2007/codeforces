#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
vector<pair<int, int>> ind;
vector<int> res;
 
int f(int x, int j) {
    return (x & (1 << j)) > 0;
}
 
int solve(int j, int n) {
    vector<bool> ban(n, false);
    vector<int> z(n, -1);
    vector<int> left(n, 0);
    vector<int> g(n, 1e18);
    int m = res.size();
    for (int i = 0; i < m; i++) {
        if (f(res[i], j) == 1) {
            z[ind[i].first] = max(z[ind[i].first], ind[i].second);
        }
        else {
            g[ind[i].first] = min(g[ind[i].first], ind[i].second);
        }
    }
    int tmp = -1, J = n - 1;
    for (int i = 0; i < n; i++) {
        tmp = max(tmp, z[i]);
        if (tmp >= i) {
            ban[i] = true;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        while (J >= 0 && g[J] >= i) {
            J--;
        }
        left[i] = J;
    }
    vector<int> dp(n, 0);
    vector<int> pref(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            pref[i] = pref[i - 1] + dp[i - 1];
            pref[i] %= mod;
        }
        if (i == n || ban[i]) continue;
        if (left[i] == -1) {
            dp[i] = 1 + pref[i];
            dp[i] %= mod;
            continue;
        }
        dp[i] = (pref[i] - pref[left[i]] + mod);
        dp[i] %= mod;
    }
    int lst = -1;
    for (int i = 0; i < m; i++) {
        if (f(res[i], j) == 1) continue;
        lst = max(lst, ind[i].first);
    }
    if (lst == -1) return (pref[n] + mod + 1) % mod;
    else {
        return (pref[n] - pref[lst] + mod) % mod;
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ind.emplace_back(x - 1, y - 1);
        res.push_back(z);
    }
    int ans = 1;
    for (int i = 0; i < k; i++) {
        ans = (ans * solve(i, n)) % mod;
    }
    cout << ans;
}