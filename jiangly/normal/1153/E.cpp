#include <bits/stdc++.h>
using namespace std;
int query(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 << " " << y2 << endl;
    int result;
    cin >> result;
    return result;
}
void report(int x1, int y1, int x2, int y2) {
    cout << "! " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
    exit(0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int l = n, r = -1, u = n, d = -1;
    for (int i = 1; i < n; ++i) {
        if (query(0, 0, n, i) % 2 == 1) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    for (int i = 1; i < n; ++i) {
        if (query(0, 0, i, n) % 2 == 1) {
            u = min(u, i);
            d = max(d, i);
        }
    }
    if (r != -1 && d != -1) {
        if (query(u - 1, l - 1, u, l) % 2 == 1)
            report(u - 1, l - 1, d, r);
        else
            report(u - 1, r, d, l - 1);
    } else if (r != -1) {
        u = 1;
        d = n;
        while (u < d) {
            int mid = (u + d) / 2;
            if (query(0, l - 1, mid, l) % 2 == 1)
                d = mid;
            else
                u = mid + 1;
        }
        report(u - 1, l - 1, u - 1, r);
    } else {
        l = 1;
        r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (query(u - 1, 0, u, mid) % 2 == 1)
                r = mid;
            else
                l = mid + 1;
        }
        report(u - 1, l - 1, d, l - 1);
    }
    return 0;
}