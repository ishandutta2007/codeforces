#include <bits/stdc++.h>
using namespace std;

int64_t pw(int64_t n, int64_t k, int64_t MOD) {
    if (k==0)
        return 1;
    int64_t tmp = pw(n, k/2, MOD);
    return k%2==0 ? tmp*tmp%MOD : tmp*tmp%MOD*n%MOD;
}

int64_t inv(int64_t x, int64_t MOD) {
    return pw(x, MOD-2, MOD);
}

int main() {
    //freopen("cequation.inp", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int64_t a, b, p, x, res = 0;
    cin >> a >> b >> p >> x;
    if (a%p==0) {
        if (b!=0) cout << 0;
        else cout << x;
    }
    else {
        //cerr << pw(2, 2, p) << '\n';
        int64_t M = 1LL*p*(p-1);
        for (int64_t r=0; r<p-1; ++r) {
            int64_t a1 = r;
            int64_t a2 = inv(pw(a, r, p), p)*b%p;
            int64_t M1 = p, M2 = p-1;
            int64_t y1 = inv(M1, p-1), y2 = inv(M2, p);
            int64_t t = (a1*M1*y1 + a2*M2*y2)%M;
            if (x>=t)
                res += (x-t)/M+1;
        }
        cout << res;
    }
}