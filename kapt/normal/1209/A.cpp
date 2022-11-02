#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int arr[MAXN];
int used[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        bool f = false;
        for (int j = 1; j <= arr[i]; ++j) {
            if (arr[i] % j == 0 && used[j]) {
                f = true;
                break;
            }
        }
        if (f) {
            continue;
        }
        cnt++;
        used[arr[i]] = 1;
    }
    cout << cnt;
    return 0;
}