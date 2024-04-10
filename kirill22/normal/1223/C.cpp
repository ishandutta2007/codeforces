#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] /= 100;
        }
        sort(a.begin(), a.end());
        int x, X, y, Y;
        cin >> x >> X >> y >> Y;
        if (x < y) {
            swap(x, y);
            swap(X, Y);
        }
        int k;
        cin >> k;
        int l = 0, r = n + 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            int z = m / ((X * Y) / __gcd(X, Y));
            int f = m / X - z;
            int f2 = m / Y - z;
            int sum = 0;
            int R = n - 1;
            while (R >= 0) {
                if (z > 0) {
                    z--;
                    sum += a[R] * (x + y);
                }
                else if (f > 0) {
                    f--;
                    sum += a[R] * x;
                }
                else if (f2 > 0) {
                    f2--;
                    sum += a[R] * y;
                }
                R--;
            }
            if (sum >= k) {
                r = m;
            }
            else {
                l = m;
            }
        }
        if (r == n + 1) {
            cout << -1 << endl;
        }
        else {
            cout << r << endl;
        }
    }
}