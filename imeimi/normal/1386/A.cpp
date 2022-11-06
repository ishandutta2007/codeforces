#include <bits/stdc++.h>

using namespace std;
typedef long long llong;

#ifdef imeimi
llong val = 0;
#endif

llong n, p;
set<llong> used;
int Q(llong x) {
    llong ret;
    cout << "? " << x << endl;
    if (x > n || x < 1) exit(7);
    if (used.count(x)) exit(4);
    used.insert(x);
#ifdef imeimi
    ret = (abs(p - x) >= val);
    cout << "! " << ret << endl;
#else
    cin >> ret;
#endif
    p = x;
    return ret;
}

llong solve() {
    p = -1;
    used.clear();
#ifndef imeimi
    if (n <= 64) {
        Q(1);
        for (int s = 1, e = n; s != e; ) {
            if (!Q(e)) return abs(e - s) + 1;
            swap(s, e);
            if (s < e) --e; else ++e;
        }
        return 1;
    }
#endif
    llong L = 0, R = 0, x = 0, o = 0;
    llong s = 1, e = n;
    while (s < e) {
        llong m = (s + e - 1) / 2;
        if (o ^= 1) R = max(R, x += m);
        else L = min(L, x -= m);
        s = m + 1;
    }
    if (R - L + 1 > n) exit(6);
    x = 1 - L, o = 0;
    s = 1, e = n;
    Q(x);
    while (s < e) {
        llong m = (s + e - 1) / 2;
        llong ret;
        if (o ^= 1) ret = Q(x += m);
        else ret = Q(x -= m);
        if (ret) e = m;
        else s = m + 1;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef imeimi
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= i; ++j) {
            n = i;
            val = j;
            if (j != solve()) exit(9);
        }
    }
#endif
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        llong ret = solve();
        cout << "= " << ret << endl;
    }
    return 0;
}