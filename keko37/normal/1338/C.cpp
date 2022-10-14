#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

llint t, n;
llint a[3][4] = {{0, 1, 2, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}};

void solve () {
    llint pot = 1;
    while (pot <= n) pot *= 4; pot /= 4;
    n -= pot;
    llint ost = n % 3;
    n /= 3;
    llint res = (ost + 1) * pot;
    llint pot2 = 1;
    while (pot > 1) {
        res += a[ost][n % 4] * pot2;
        n /= 4; pot /= 4; pot2 *= 4;
    }
    cout << res << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        solve();
    }
    return 0;
}