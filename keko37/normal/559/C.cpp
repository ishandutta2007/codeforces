#include<iostream>
#include<cstring>

using namespace std;

typedef long long llint;

const int MAXN = 200005;
const int MOD = 1000000007;

llint n, h, w;
llint fact[MAXN], inv[MAXN];
llint x[MAXN], y[MAXN];
llint dp[MAXN];

llint mul (llint a, llint b) {
    return a*b%MOD;
}

llint sub (llint a, llint b) {
    if (a-b<0) return a-b+MOD; return a-b;
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

llint f (llint pos) {
    if (dp[pos]!=-1) return dp[pos];
    dp[pos]=0;
    for (int i=0; i<=n; i++) {
        if (pos!=i && x[pos]<=x[i] && x[i]<=h && y[pos]<=y[i] && y[i]<=w) {
            int a=nck(h-x[i]+w-y[i], h-x[i]);
            int b=nck(x[i]-x[pos]+y[i]-y[pos], x[i]-x[pos]);
            dp[pos]+=mul(b, sub(a, f(i)));
            if (dp[pos]>=MOD) dp[pos]-=MOD;
        }
    }
    return dp[pos];
}

int main () {
    memset(dp, -1, sizeof dp);
    precompute();
    cin >> h >> w >> n;
    x[0]=y[0]=1;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << sub(nck(h+w-2, h-1), f(0));
    return 0;
}