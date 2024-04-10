#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll fib[300005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    ll MOD;
    cin >> n >> q >> MOD;
    fib[1] = fib[2] = 1;
    for(int i = 3; i <= n+3; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
    vector<ll> fibs(n+1), nums(n+1);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fibs[i] += x;
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fibs[i] -= x;
        fibs[i] += MOD;
        fibs[i] %= MOD;
    }
    for(int i = 0; i < n; i++) {
        if(i == 0) nums[i] = fibs[i] % MOD;
        else if(i == 1) nums[i] = (MOD + fibs[i] - fibs[i-1]) % MOD;
        else nums[i] = (MOD + MOD + fibs[i] - fibs[i-1] - fibs[i-2]) % MOD;
    }
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
    }
    while(q--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        l--; 
        sum -= nums[l];
        if(r < n) sum -= nums[r];
        if(r < n - 1) sum -= nums[r+1];
        if(c == 'A') {
            nums[l] = (nums[l] + 1) % MOD;
            if(r < n) nums[r] = (nums[r] + MOD - fib[r-l+1]) % MOD;
            if(r < n-1) nums[r+1] = (nums[r+1] + MOD - fib[r-l]) % MOD;
        }
        else {
            nums[l] = (MOD + nums[l] - 1) % MOD;
            if(r < n) nums[r] = (nums[r] + fib[r-l+1]) % MOD;
            if(r < n-1) nums[r+1] = (nums[r+1] + fib[r-l]) % MOD;
        }
        sum += nums[l];
        if(r < n) sum += nums[r];
        if(r < n - 1) sum += nums[r+1];
        if(sum == 0 || MOD == 1) cout << "YES\n";
        else cout << "NO\n";
    }
}