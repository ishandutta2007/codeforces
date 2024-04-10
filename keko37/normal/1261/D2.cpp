#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MOD = 998244353;
const int MAXN = 400005;

int mul (int x, int y) {return 1LL * x * y % MOD;}
int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}

int n, k, cnt;
int h[MAXN];
int fct[MAXN], inv[MAXN];

int pot (int a, int e) {
    int res = 1;
    while (e > 0) {
        if (e & 1) res = mul(res, a);
        a = mul(a, a);
        e /= 2;
    }
    return res;
}

void precompute () {
    fct[0] = inv[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fct[i] = mul(fct[i - 1], i);
        inv[i] = pot(fct[i], MOD - 2);
    }
}

int nck (int n, int k) {
    if (n < k || k < 0) return 0;
    return mul(fct[n], mul(inv[n - k], inv[k]));
}

void calc () {
    int res = 0;
    for (int i = 0; i <= cnt; i++) {
        int val = mul(nck(cnt, i), nck(cnt - i, i));
        val = mul(val, pot(k - 2, cnt - 2 * i));
        res = add(res, val);
    }
    res = sub(pot(k, cnt), res);
    res = mul(res, (MOD + 1) / 2);
    res = mul(res, pot(k, n - cnt));
    cout << res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        if (h[i] != h[(i + 1) % n]) cnt++;
    }
    calc();
    return 0;
}