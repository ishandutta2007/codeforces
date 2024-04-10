#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> q;
    while (q--) {
        cin >> n;
        int X[2] = {-100000, 100000}, Y[2] = {-100000, 100000};
        for (int i = 0; i < n; i++) {
            int x, y, f[4];
            cin >> x >> y >> f[0] >> f[1] >> f[2] >> f[3];
            if (f[0] == 0) X[0] = max(X[0], x);
            if (f[1] == 0) Y[1] = min(Y[1], y);
            if (f[2] == 0) X[1] = min(X[1], x);
            if (f[3] == 0) Y[0] = max(Y[0], y);
        }
        if (X[0] > X[1] || Y[0] > Y[1]) cout << "0\n";
        else cout << "1 " << X[0] << ' ' << Y[0] << endl;
    }
    return 0;
}