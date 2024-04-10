#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i] || (b[i] > b[(i + 1) % n] + 1 && a[i] != b[i])) {
                ok = 0;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}