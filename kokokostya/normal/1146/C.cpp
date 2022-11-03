#include <bits/stdc++.h>

using namespace std;

int ask(int l1, int r1, int l2, int r2) {
    cout << r1 - l1 << ' ' << r2 - l2 << ' ';
    for (int i = l1; i < r1; i++) {
        cout << i + 1 << ' ';
    }
    for (int i = l2; i < r2; i++) {
        cout << i + 1 << ' ';
    }
    cout << endl;
    int d;
    cin >> d;
    return d;
}

int global = -1;
int n;

int solve(int l, int r) {
    if (r - l == 1) {
        cout << 1 << ' ' << n - 1 << ' ';
        cout << l + 1 << ' ';
        for (int i = 0; i< n; i++) {
            if (i != l)
                cout << i + 1 << ' ';
        }
        cout << endl;
        int val;
        cin >> val;
        return val;
    }
    int m = (l + r) / 2;
    int val = ask(0, 1, l, m);
    if (val == global) {
        return solve(l, m);
    }
    else {
        return solve(m, r);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int test;
    cin >> test;

    while(test--) {
        cin >> n;
        global = ask(0, 1, 1, n);
        int res = solve(1, n);
        cout << "-1 " << res << endl;
    }
    return 0;
}