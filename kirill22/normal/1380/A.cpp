#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, n, a[100000];
    cin >> t;
    for (int j = 0; j < t; j++) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        bool f = false;
        for (int i = 1; i < n - 1 && !f; i++) if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            f = true;
            cout << "YES\n" << i << " " << i + 1 << " " << i + 2 << "\n";
        }
        if (!f) cout << "NO\n";
    }
}