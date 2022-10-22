#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int P = 1;
const ll mult = 691337;
ll primes[4] = {1000000007, 1000000009, 1000000021, 1000000033};

ll modpow(ll MOD, ll n, ll e) {
    if(e == 0) return 1;
    if(e == 1) return n;
    ll x = modpow(MOD, n, e/2);
    x *= x;
    x %= MOD;
    if(e%2) {
        x *= n;
        x %= MOD;
    }
    return x;
}

struct Hash {
    vector<ll> mpow[P];
    vector<ll> sums[P];
    int n;
    Hash(vector<ll> v) {
        n = v.size();
        for(int i = 0; i < P; i++) {
            sums[i].resize(2*n+1);
            mpow[i].resize(2*n+1);
            mpow[i][0] = 1;
            for(int j = 0; j < 2*n; j++) {
                mpow[i][j+1] = (mult * mpow[i][j]) % primes[i];
                sums[i][j+1] = ((v[j%n] + primes[i]) * mpow[i][j+1]) % primes[i];
                sums[i][j+1] += sums[i][j];
                sums[i][j+1] %= primes[i];
            }
            for(int j = 0; j <= 2*n; j++) mpow[i][j] = modpow(primes[i], mpow[i][j], primes[i]-2);
        }
    }
    ll sum(int x, int y, int i) {
        if(x > y) y += n;
        return ((sums[i][y] - sums[i][x] + primes[i]) * mpow[i][x+1]) % primes[i];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if(m == 2) {
        cout << "1\n0\n";
        return 0;
    }
    if(n == 1) {
        int x;
        cin >> x;
        cout << "1\n" << (2*x)%m << '\n';
        return 0;
    }
    vector<ll> nums(n);
    vector<ll> diff(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    diff[n-1] = (nums[0] - nums[n-1] + m)%m;
    for(int i = 0; i < n-1; i++) diff[i] = (nums[i+1] - nums[i] + m)%m;
    Hash h1(diff);
    reverse(diff.begin(), diff.end());
    Hash h2(diff);
    set<int> ans;
    for(int i = 1; i <= n; i++) {
        bool ok = true;
        for(int j = 0; j < P; j++) {
            if(h1.sum(i, i+n-1, j) != h2.sum(n-i+1, 2*n-i, j)) {
                ok = false;
            }
        }
        if(ok) {
            if(i < n) ans.insert((nums[i-1] + nums[i])%m);
            else ans.insert((nums[0] + nums[n-1])%m);
        }
    }
    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(int j = 0; j < P; j++) {
            if(h1.sum(i, i+n, j) != h2.sum(n-i, 2*n-i, j)) {
                ok = false;
            }
        }
        if(ok) {
            ans.insert((2*nums[i])%m);
        }
    }
    cout << ans.size() << '\n';
    for(int g : ans) cout << g << ' ';
    cout << '\n';
}