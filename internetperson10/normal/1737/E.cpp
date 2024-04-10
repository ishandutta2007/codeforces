#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 1000000007;

ll modpow(ll n, ll e) {
    if(e == 0) return 1;
    ll x = modpow(n, e/2);
    x *= x;
    x %= MOD;
    if(e % 2) {
        x *= n;
        x %= MOD;
    }
    return x;
}

ll half = modpow(2, MOD - 2);
ll ans[2000001], sum[2000001];

void solve() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << "1\n";
        return;
    }
    if(n == 2) {
        cout << "0\n1\n";
        return;
    }
    for(int i = 0; i < 2 * n; i++) {
        ans[i] = sum[i] = 0;
    }
    ans[n-1] = modpow(half, (n-1)/2);
    sum[n-1] = ans[n-1];
    ll tot = 1;
    for(int i = n-2; i >= 1; i--) {
        ans[i] = (modpow(half, 1 + i/2) * (MOD + 1 - sum[2*i+1])) % MOD;
        sum[i] = (ans[i] + sum[i+1]) % MOD;
    }
    assert(sum[1] == 1);
    cout << "0\n";
    for(int i = 1; i < n; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}