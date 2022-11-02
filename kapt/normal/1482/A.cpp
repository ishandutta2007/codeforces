#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int arr[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a((n + 1) / 2), b(n / 2);
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                cin >> a[i / 2];
            } else {
                cin >> b[i / 2];
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                arr[i] = a[i / 2];
            } else {
                arr[i] = b[i / 2];
            }
        }
        bool f = true;
        for (int i = 1; i < n; ++i) {
            f &= (arr[i] >= arr[i - 1]);
        }
        if (f) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}