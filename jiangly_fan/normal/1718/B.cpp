#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int k;
        cin >> k;
        vector<LL> c(k);
        LL sum = 0;
        for (LL& ci : c) {
            cin >> ci;
            sum += ci;
        }
        if (sum == 1) {
            cout << "YES\n";
            continue;
        }
        LL fs = 2;
        vector<LL> f = {1, 1};
        while (fs < sum) {
            LL x = f[f.size() - 1], y = f[f.size() - 2];
            fs += x + y;
            f.push_back(x + y);
        }
        if (fs > sum) {
            cout << "NO\n";
            continue;
        }
        int ok = 1;
        for (int i = f.size() - 1, j = -1; i >= 0; i -= 1) {
            int x = -1;
            for (int y = 0; y < k; y += 1)
                if (y != j) {
                    if (x == -1 or c[y] > c[x])
                        x = y;
                }
            if (x == -1 or c[x] < f[i]) {
                ok = 0;
                break;
            }
            j = x;
            c[x] -= f[i];
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}