#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int mod = 1000000007;

int binpow(int x, int p) {
    int ans = 1;
    while(p) {
        if (p & 1) {
            ans = (ans * (ll)x) % mod;
        }
        x = (x * ll(x)) % mod;
        p >>= 1;
    }
    return ans;
}

int inv(int x) {
    return binpow(x, mod - 2);
}


int main() {
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll cur = n;
    vector<ll> div;
    vector<int> deg;
    for(ll i = 2; i * i <= n; ++i) {
        if (cur % i == 0) {
            int cnt = 0;
            while (cur % i == 0) {
                cur /= i;
                ++cnt;
            }
            div.push_back(i);
            deg.push_back(cnt);
        }
    }
    if (cur > 1) {
        div.push_back(cur);
        deg.push_back(1);
    }
    int ans = 1;
    for(int i = 0; i < div.size(); ++i) {
        vector<int> p(deg[i] + 1, 0);
        p.back() = 1;
        for(int j = 0; j < k; ++j) {
            for(int u = (int)p.size() - 1; u >= 0; --u) {
                p[u] = (p[u] * ll(inv(u + 1))) % mod;
            }
            for(int u = (int)p.size() - 2; u >= 0; --u) {
                p[u] += p[u + 1];
                if (p[u] >= mod) {
                    p[u] -= mod;
                }
            }
        }
        int zu = 0;
        int cur = 1;
        for (int u = 0; u < p.size(); ++u) {
            zu = (zu + ll(p[u]) * cur) % mod;
            cur = (cur * ll(div[i])) % mod;
        }
        ans = (ans * ll(zu)) % mod;
    }
    cout << ans << endl;
}