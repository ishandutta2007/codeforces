#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }
int sub(int a, int b){ return add(a, MOD - b); }

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int inv(int a){ return pw(a, MOD - 2); }

const int N = 14;

int a[N+5];
int dp[N+5];
int win[N+5][(1<<N)];
int prob[N+5][N+5];
int cyc[(1<<N)];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            prob[i][j] = mul(a[i], inv(a[i] + a[j]));
        }
    }
    for(int i=1; i<=n; i++){
        win[i][0] = 1;
        for(int mask=1; mask<(1<<n); mask++){
            if((1 << (i-1)) & mask) continue;
            int x = mask & -mask;
            win[i][mask] = mul(win[i][mask ^ x], prob[i][1 + __builtin_ctz(x)]);
        }
    }
    int res = 0;
    for(int mask=1; mask<(1<<n); mask++){
        cyc[mask] = 1;
        for(int subm=mask; subm; subm=(subm-1)&mask){
            if(subm == mask) continue;
            int x = mask ^ subm;
            int pr = cyc[x];
            for(int i=1; i<=n; i++) if((1 << (i-1)) & x) pr = mul(pr, win[i][subm]);
            cyc[mask] = sub(cyc[mask], pr);
        }
    }
    for(int mask=1; mask<(1<<n); mask++){
        int x = ((1<<n) - 1) ^ mask;
        int pr = cyc[mask];
        for(int i=1; i<=n; i++) if((1 << (i-1)) & mask) pr = mul(pr, win[i][x]);
        res = add(res, mul(__builtin_popcount(mask), pr));
    }
    cout << res << "\n";
    return 0;
}