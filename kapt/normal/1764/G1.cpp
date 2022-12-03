#include <bits/stdc++.h>
using namespace std;

int ask(int l, int r) {
    if (r == l) {
        return 1;
    }
    cout << "? " << l << " " << r << " " << 2 << endl;
    int x;
    cin >> x;
    return x;
}

int ask1(int l, int r, int n) {
    if (r == l) {
        return 1;
    }
    cout << "? " << l << " " << r << " " << n << endl;
    int x;
    cin >> x;
    return x;
}

int find_n(int n) {
    int l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (m != n) {
            if (ask1(m, n, n) == 2) {
                l = m;
            } else {
                r = m;
            }
        } else {
            if (ask1(1, m - 1, n) == 2) {
                r = m;
            } else {
                l = m;
            }
        }
    }
    return l;
}

main() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            int a = ask(1, m - 1);
            int b = ask(m, n);
            int t = a + b - (n + 1) / 2;
            if ((m - 1 - t) % 2 == 1) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << "! " << l << endl;
        return 0;
    }
    int i = find_n(n);
    int l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int a = ask(1, m - 1);
        int b = ask(m, n);
        int t = a + b - (n + 2) / 2;
        if ((m - 1 - t) % 2 == 1) {
            if (i >= m) {
                r = m;
            } else {
                l = m;
            }
        } else {
            if (i >= m) {
                l = m;
            } else {
                r = m;
            }
        }
    }
    cout << "! " << l << endl;
    return 0;
}