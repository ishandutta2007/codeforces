#include <bits/stdc++.h>

using namespace std;

vector<int> a;

void update(int x, int y) {
    while (x < a.size()) {
        a[x] += y;
        x = (x | (x + 1));
    }
}

int get(int x) {
    int res = 0;
    while (x >= 0) {
        res += a[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    a.resize(n, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        update(x, 1);
    }
    while (q--) {
        int x;
        cin >> x;
        if (x > 0) {
            update(x - 1, 1);
        }
        else {
            x = abs(x);
            int l = -1, r = n - 1;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (get(m) < x) l = m;
                else r = m;
            }
            update(r, -1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (get(i) - get(i - 1) > 0) {
            cout << i + 1;
            exit(0);
        }
    }
    cout << 0;
}