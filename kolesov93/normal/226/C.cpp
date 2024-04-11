#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

typedef long long ll;

ll DIV(ll a, ll b) {
    return (a + b - 1) / b;
}

ll MOD;

struct matrix {
    ll a[2][2];

    matrix() {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }

    matrix operator*(const matrix& A) const {
        matrix res;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k) {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * A.a[k][j]) % MOD;
                }
        return res;
    }
};

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    ll m, l, r, k;
    cin >> m >> l >> r >> k;
    ll n = r - l + 1;
    MOD = m;

    ll maxx = (n - 1) / (k - 1);

    ll ans = 1;

    ll cx = maxx;
    while (cx > 0) {
        ll curd = DIV(l, cx);
        ll D = r / (curd + k - 1);

        ll L = 1, R = cx;
        while (L < R) {
            ll mid = (L + R) >> 1;
            if (DIV(l, mid) < curd) L = mid + 1;
            else R = mid;
        }

        if (L <= D) {
            ll cand = min(D, cx);
            ans = cand;
            break;
        }
    }

    matrix A, B;
    A.a[0][0] = A.a[1][1] = 1 % m;
    B.a[0][1] = B.a[1][0] = B.a[1][1] = 1 % m;

    //cerr << "num = " << ans << endl;

    --ans;
    while (ans) {
        if (ans & 1) A = A * B;
        B = B * B;
        ans >>= 1;
    }

    cout << A.a[1][1] << endl;

    return 0;
}