#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define X first
#define Y second

const int MOD = 1e9 + 7;
int m;
ll f[10005][105];

ll rev[105];
vector<pair<ll, int>> decomp(ll n) {
    vector<pair<ll, int>> ans;
    for(ll x = 2; x * x <= n; x++) if (n % x == 0) {
        int lv = 0;
        while (n % x == 0) {
            n /= x;
            lv++;
        }
        ans.push_back({x, lv});
    }
    if (n > 1) ans.push_back({n, 1});
    return ans;
}
ll solve(ll x, int n) {
    //cout << x << " " << n << '\n';
    memset(f[0], 0, sizeof(f));
    f[0][n] = 1;
    for(int i = 1; i <= m; i++) {
        f[i][n + 1] = 0;
        for(int j = n; j >= 0; j--)
            f[i][j] = (f[i][j + 1] + f[i - 1][j] * rev[j + 1]) % MOD;
    }
    ll ans = 0;
    for(ll i = 0, cur = 1; i <= n; i++, cur = cur * x % MOD) 
        ans = (ans + f[m][i] * cur) % MOD;
    //cout << n << " " << x << " " << ans << '\n';
    return ans;
}
int main() {
    rev[1] = 1;
    for(int i = 2; i <= 100; i++) rev[i] = MOD - (MOD / i) * rev[MOD % i] % MOD;
    ll n;
    cin >> n >> m;
    vector<pair<ll, int>> a = decomp(n);


    ll ans = 1;
    for(auto i : a) ans = (ans * solve(i.X, i.Y)) % MOD;
    cout << ans;
}