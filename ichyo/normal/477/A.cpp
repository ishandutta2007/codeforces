#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef long long LL;
const int MOD = 1000000007;

LL slow(LL a, LL b) {
    LL ans = 0;
    for(LL A = 1; A < b; A++) {
        // x = A + kb
        for(LL x = A; ; x += b) {
            assert(x < LLONG_MAX / 2);
            if((x / b) % A != 0) continue;
            if((x / b) / A > a) break;
            if((x / b) / A <= 0) continue;
            ans += x;
            ans %= MOD;
        }
    }
    return ans;
}
LL extgcd(LL a, LL b, LL& x, LL& y){
    LL d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else{
        x = 1; y = 0;
    }
    return d;
}
LL inv_mod(LL a, LL mod){
    LL x, y;
    extgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

LL solve(LL a, LL b) {
    //cout << "solve " << a << " " << b << endl;
    LL ans = 0;
    LL inv2 = inv_mod(2, MOD);
    for(LL A = 1; A < b; A++){
        // x = A + kb
        //assert((A * a) % (B * b) == 0);
        LL n = a;
        LL a0 = (A + b * A) % MOD;
        LL d = (b * A) % MOD;
        //ans += n * (2 * a0 + (n - 1) * d) / 2;
        LL add1 = a0 * n;
        assert(add1 >= 0);
        ans += add1;
        ans %= MOD;
        //ans += n * (n - 1) % MOD * d % MOD * inv2 % MOD;
        LL add2 = n * (n - 1) % MOD * d % MOD * inv2 % MOD;
        assert(add2 >= 0);
        ans += add2;
        ans %= MOD;
    }
    return ans;
}


int main(){
#ifdef LOCAL
    for(int a = 1; a <= 100; a++) {
        for(int b = 1; b <= 100; b++) {
            cout << a << " " << b << endl;
            if(solve(a, b) != slow(a, b)){
                cout << "a,b : " << a << " " << b << endl;
                cout << "solve: " << solve(a, b) << endl;
                cout << "slow: " << slow(a, b) << endl;
                assert(false);
            }
        }
    }
#endif
    LL a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}