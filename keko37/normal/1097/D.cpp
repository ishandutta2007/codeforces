#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MOD = 1000000007;

llint n, k;
llint dp[55], inv[100];
vector < pair <llint, int> > v;

void factor () {
    llint val = n;
    for (llint d = 2; d * d <= val; d++) {
        int cnt = 0;
        while (val % d == 0) {
            val /= d;
            cnt++;
        }
        if (cnt) v.push_back(make_pair(d, cnt));
    }
    if (val > 1) v.push_back(make_pair(val, 1));
}

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
    for (int i=1; i<=70; i++) {
        inv[i] = pot(i, MOD-2);
    }
}

llint calc (int ind) {
    llint val = v[ind].first;
    llint cnt = v[ind].second;
    dp[0] = 1;
    for (int i=1; i<=cnt; i++) {
        dp[i] = val * dp[i-1] % MOD;
    }
    for (int i=0; i<k; i++) {
        for (int j=cnt; j>=1; j--) {
            for (int k=0; k<j; k++) {
                dp[j] += dp[k];
                if (dp[j] >= MOD) dp[j] -= MOD;
            }
            dp[j] = dp[j] * inv[j+1] % MOD;
        }
    }
    return dp[cnt];
}

int main () {
    cin >> n >> k;
    factor();
    precompute();
    llint sol = 1;
    for (int i=0; i<v.size(); i++) {
        sol = (sol * calc(i)) % MOD;
    }
    cout << sol;
    return 0;
}