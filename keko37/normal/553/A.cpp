#include<iostream>

using namespace std;

typedef long long llint;

const int MAXN = 1005;
const int MOD = 1000000007;

llint k, cnt;
llint fact[MAXN], inv[MAXN];
llint l[MAXN], dp[MAXN];

llint mul (llint a, llint b) {
    return a*b%MOD;
}

llint pot (llint a, llint p) {
    if (p==0) return 1;
    if (p&1) {
        return mul(pot(a, p-1), a);
    } else {
        llint t=pot(a, p>>1);
        return mul(t, t);
    }
}

void precompute () {
    fact[0]=inv[0]=1;
    for (int i=1; i<MAXN; i++) {
        fact[i]=mul(fact[i-1], i);
        inv[i]=pot(fact[i], MOD-2);
    }
}

llint nck (llint nn, llint kk) {
    return mul(fact[nn], mul(inv[kk], inv[nn-kk]));
}

int main () {
    precompute();
    cin >> k;
    for (int i=1; i<=k; i++) {
        cin >> l[i];
    }
    dp[1]=1;
    cnt=l[1];
    for (int i=2; i<=k; i++) {
        cnt+=l[i];
        dp[i]=mul(dp[i-1], nck(cnt-1, l[i]-1));
    }
    cout << dp[k];
    return 0;
}