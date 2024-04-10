#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int arr[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        bool x = false;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] == k) {
                x = true;
            }
        }
        bool f = false;
        for (int i = 1; i < n; ++i) {
            if (arr[i] >= k && arr[i - 1] >= k) {
                f = true;
                break;
            }
        }
        for (int i = 2; i < n; ++i) {
            if (arr[i] >= k && arr[i - 2] >= k) {
                f = true;
                break;
            }
        }
        if (x && (f || n == 1)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}