#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 5005;
const int MOD = 998244353;

llint n, m, sol;
int a[MAXN];
map <int, int> mp;
vector < pair <int, int> > v;
llint dp[MAXN][MAXN], sum[MAXN][MAXN], inv[MAXN];

llint pot (llint b, llint e) {
    if (e == 0) return 1;
    if (e & 1) {
        return pot(b, e-1) * b % MOD;
    } else {
        llint t = pot(b, e/2);
        return t * t % MOD;
    }
}

void precompute () {
    for (int i=1; i<=n; i++) {
        inv[i] = pot(i, MOD-2);
    }
}

void calc () {
    for (int val = m-1; val >= 0; val--) {
        for (int br = n-1; br >= 1; br--) {
            llint res = (v[val].second - 1 + sum[val+1][br+1]) % MOD;
            res = res * inv[n - br] % MOD;
            dp[val][br] = res;
            sum[val][br] = (dp[val][br] * v[val].second + sum[val+1][br]) % MOD;
        }
    }
}

int main () {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (auto it : mp) {
        v.push_back(it);
    }
    m = v.size();
    precompute();
    calc();
    for (int i=0; i<m; i++) {
        sol += dp[i][1] * v[i].second;
        sol %= MOD;
    }
    sol = (sol * inv[n]) % MOD;
    cout << sol;
    return 0;
}