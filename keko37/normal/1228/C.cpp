#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MOD = 1000000007;

llint n, x, sol = 1;

llint pot (llint x, llint e) {
    llint res = 1;
    while (e > 0) {
        if (e & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        e /= 2;
    }
    return res;
}

void f (llint p) {
    llint val = n;
    while (val > 0) {
        sol = sol * pot(p, val / p) % MOD;
        val /= p;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> n;
    for (int i = 2; i * i <= x; i++) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            cnt++;
        }
        if (cnt > 0) f(i);
    }
    if (x > 1) f(x);
    cout << sol;
    return 0;
}