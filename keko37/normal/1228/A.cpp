#include<bits/stdc++.h>

using namespace std;

int l, r;

bool ok (int x) {
    int cnt[15];
    memset(cnt, 0, sizeof cnt);
    while (x > 0) {
        cnt[x % 10]++;
        x /= 10;
    }
    for (int i=0; i<10; i++) {
        if (cnt[i] > 1) return 0;
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (ok(i)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}