#pragma optimize("O3")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define all(x) x.begin(), x.end()

int get(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    int k;
    cin >> k;
    return k;
}

void solve() {
    int n;
    cin >> n;
    int a1 = 1, a2 = 2, a3 = 3;
    int mx = get(a1, a2, a3);
    int k = 4;
    bool ok = false;
    while (k <= n) {
        int t = get(a1, a2, k);
        if (t != mx)
            ok = true;
        if (t > mx) {
            mx = t;
            a3 = k;
        }
        k++;
    }
    k = 3;
    mx = get(a1, a2, a3);
    int lol = mx;
    ok = false;
    while (k <= n) {
        if (k == a3) {
            k++;
            continue;
        }
        int t = get(a1, k, a3);
        if (t > lol)
            ok = true;
        if (t > mx) {
            mx = t;
            a2 = k;
        }
        k++;
    }
    int ind = 1;
    for (int i = 1; i <= n; i++) {
        if (i != a1 && i != a2 && i != a3) {
            ind = i;
            break;
        }
    }
    int boba = get(a1, ind, a3);
    int aboba = get(a2, ind, a3);
    if (mx != boba && mx != aboba) {
        cout << "! " << a1 << " " << a2 << endl;
        return;
    }
    if (boba < aboba) {
        cout << "! " << a2 << " " << a3 << endl;
    } else {
        cout << "! " << a1 << " " << a3 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin >> T;
    while (T --> 0) {
        solve();
    }

    return 0;
}
/*

 */