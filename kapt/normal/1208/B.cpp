#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int arr[MAXN];
int arr1[MAXN];
int b[MAXN];
map<int, int> b1;
int used[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr1[i] = arr[i];
    }
    sort(arr1, arr1 + n);
    int k = unique(arr1, arr1 + n) - arr1;
    for (int i = 0; i < k; ++i) {
        b1[arr1[i]] = i;
        b[i] = arr1[i];
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = b1[arr[i]];
    }
    int aans = n;
    k = 0;
    for (int i = 0; i < n; ++i) {
        fill(used, used + n, 0);
        bool f = false;
        for (int j = 0; j < i; ++j) {
            if (used[arr[j]]) {
                f = true;
                break;
            }
            used[arr[j]] = 1;
        }
        if (f) {
            break;
        }
        int ans = n - i;
        for (int j = n - 1; j >= 0; --j) {
            if (!used[arr[j]]) {
                used[arr[j]] = 1;
                ans--;
            } else {
                break;
            }
        }
        // cout << ans << endl;
        if (ans < aans) {
            aans = ans;
        }
    }
    cout << aans;
    return 0;
}