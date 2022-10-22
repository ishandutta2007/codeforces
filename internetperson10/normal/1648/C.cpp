#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 998244353;

ll fact[200001], invfact[200001], inv[200001];

ll modpow(ll n, ll e = MOD-2) {
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

struct FTree {
    vector<int> nums;
    int size = 1;
    FTree(int n) {
        n++;
        while(size <= n) size *= 2;
        nums.resize(size+1);
    }
    void add(int n, int k) {
        n++;
        while(n <= size) {
            nums[n] += k;
            n += (n & (-n));
        }
    }
    int sum(int n) {
        n++;
        int ans = 0;
        while(n) {
            ans += nums[n];
            n -= (n & (-n));
        }
        return ans;
    }
    int get(int n) {
        if(n == 0) return sum(n);
        return sum(n) - sum(n-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = 1;
    invfact[0] = 1;
    for(ll i = 1; i <= 200000; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
        invfact[i] = modpow(fact[i]);
        inv[i] = modpow(i);
    }
    int n, m;
    cin >> n >> m;
    vector<int> ct(200001), nums(m);
    FTree ft(200005);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ct[x]++;
        ft.add(x, 1);
    }
    for(int i = 0; i < m; i++) {
        cin >> nums[i];
    }
    ll totDenom = 1;
    for(int g : ct) {
        totDenom *= invfact[g];
        totDenom %= MOD;
    }
    ll ans = 0;
    ll doubleCount = 1;
    for(int i = 0; i < min(n, m); i++) {
        int curr = nums[i];
        ans += ((fact[n-i-1] * doubleCount) % MOD) * ft.sum(curr-1);
        ans %= MOD;
        doubleCount *= ct[curr];
        if(!doubleCount) break;
        doubleCount %= MOD;
        ct[curr]--;
        ft.add(curr, -1);
    }
    if(n < m) {
        ans += doubleCount;
        ans %= MOD;
    }
    cout << (ans * totDenom) % MOD << '\n';
}