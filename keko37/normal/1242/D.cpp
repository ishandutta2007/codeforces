#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

llint t, n, k;

llint f (llint x) {
    if (x == 0) return k * (k + 1) / 2;
    llint t = x % k, val = f(x / k), ofs = 0;
    if (val < k * t + 2) {
        ofs = k;
    } else if ((t + 1) * k < val) {
        ofs = 0;
    } else {
        ofs = (t + 1) * k - val + 1;
    }
    return k * (k + 1) / 2 - t + ofs;
}

llint rjesi (llint x) {
    llint buk = (x - 1) / (k * k + 1);
    llint pos = (k * k + 1) * buk + f(buk);
    if (x != pos) {
        llint lef = buk + (pos < x);
        return (x - 1 - lef) / k - lef + x;
    } else {
        llint t = buk % k, val = f(buk / k);
        if ((t + 1) * k < val) {
            return rjesi(buk / k * (k * k + 1) + (t + 1) * k) + 1;
        } else {
            return rjesi(buk / k * (k * k + 1) + (t + 1) * k + 1) + 1;
        }
    }
}

int main () {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << rjesi(n) << '\n';
    }
    return 0;
}