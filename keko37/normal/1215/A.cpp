#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000007;

int a1, a2, k1, k2, n;

int mx (int a, int k, int br) {
    return min(a, br / k);
}

int mn (int a, int k, int br) {
    int val = br - a * (k-1);
    return min(a, max(0, val));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int rmx = 0, rmn = INF;
    for (int i=0; i<=n; i++) {
        if (!(i <= a1 * k1 && n - i <= a2 * k2)) continue;
        rmx = max(rmx, mx(a1, k1, i) + mx(a2, k2, n - i));
        rmn = min(rmn, mn(a1, k1, i) + mn(a2, k2, n - i));
    }
    cout << rmn << " " << rmx;
    return 0;
}