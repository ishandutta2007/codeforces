#include <bits/stdc++.h>
using namespace std;


long long f(int n, int m, long long k, int x, int y) {
    int period = (n-1) * m * 2;
    long long cnt = k / period * (x == 1 || x == n ? 1 : 2); 

    k %= period;
    bool reverse = false;
    for (int row = 1; row > 0;) {
        for (int col = 1; col <= m; col++) {
            if (k == 0) return cnt;
            if (row == x && col == y) cnt++;
            k--;
        }
        if (row == n) reverse = true;
        if (reverse) row--;
        else row++;
    }
    return cnt;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    long long k;
    cin >> k;
    int x, y;
    cin >> x >> y;

    if (n == 1) {
        cout << k / m + (k % m > 0) << ' ' << k / m << ' ' << k / m + (k % m >= y) << endl;
        return 0;
    }

    cout << max(f(n, m, k, 1, 1), max(f(n, m, k, 2, 1), f(n, m, k, n-1, 1))) << ' ';
    cout << f(n, m, k, n, m) << ' ';
    cout << f(n, m, k, x, y) << endl;

    return 0;
}