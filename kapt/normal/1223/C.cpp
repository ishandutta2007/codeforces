#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 3e5;
int arr[MAXN];

int x, y, a, b, k;

bool check(int m) {
    int c = m / a;
    int d = m / b;
    int e = m / (a * b / __gcd((int)a, (int)b));
    c -= e;
    d -= e;
    int x1 = x, y1 = y;
    if (x1 < y1) {
        swap(c, d);
        swap(x1, y1);
    }
    int res = 0;
    for (int i = 0; i < e; ++i) {
        res += (x1 + y1) * arr[i] / 100;
    }
    for (int i = e; i < e + c; ++i) {
        res += x1 * arr[i] / 100;
    }
    for (int i = e + c; i < e + c + d; ++i) {
        res += y1 * arr[i] / 100;
    }
    return res >= k;
}

main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        reverse(arr, arr + n);
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        int l = 0, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (check(m)) {
                r = m;
            } else {
                l = m;
            }
        }
        if (r == n + 1) {
            cout << -1 << endl;
        } else {
            cout << r << endl;
        }
    }
    return 0;
}