#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    for (auto &i: a) {
        cin >> i;
    }

    int left = 0, right = 1e16;
    while (right - left > 1) {
        int middle = left + (right - left) / 2;
        vector<int> h = a;
        int nonzero = 0;
        for (int times = 0; times < m; times++) {
            int time = nonzero + 1;
            for (int i = nonzero; i < n && time < middle; i++, time++) {
                int dec = min(h[i], middle - time);
                time += dec;
                h[i] -= dec;
            }
            while (nonzero < n && h[nonzero] == 0) {
                nonzero++;
            }
        }
        if (nonzero < n) {
            left = middle;
        } else {
            right = middle;
        }
    }

    cout << right << endl;
}