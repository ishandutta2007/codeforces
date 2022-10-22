#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x %= 3;
        a[i] = x * x % 3;
    }
    int x = 0, y = 0;
    for (auto el : a) {
        (el == 0 ? x : y) += 1;
    }
    for (int l = 0; l <= min(n / 2, x); l++) {
        int r = n / 2 - l;
        if (r > y) {
            continue;
        }
        int l2 = x - l, r2 = y - r;
        vector<int> ban(3);
        if (l && l2) {
            ban[0] = 1;
        }
        if ((l && r2) || (r && l2)) {
            ban[1] = 1;
        }
        if (r && r2) {
            ban[2] = 1;
        }
        for (int j = 0; j < 3; j++) {
            if (!ban[j]) {
                cout << j << '\n';
                for (int i = 0; i < n; i++) {
                    if (a[i] == 0) {
                        if (l) {
                            cout << 0;
                            l--;
                        } else {
                            cout << 1;
                        }
                    } else {
                        if (r) {
                            cout << 0;
                            r--;
                        } else {
                            cout << 1;
                        }
                    }
                }
                return 0;
            }
        }
    }
}