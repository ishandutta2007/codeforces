#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    vector<int> a(n);
    int x = 1, y = n * 2;
    for (int i = 0; i < n; i += 2) {
        a[i] = i + 1;
    }
    for (int i = 1; i < n; i += 2) {
        a[i] = y;
        y -= 2;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            cout << a[i] + 1 << " ";
        }
        else {
            cout << a[i] - 1 << " ";
        }
    }
}