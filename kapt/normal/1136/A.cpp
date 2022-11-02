#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int arr[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i] >> arr[i];
    }
    int k;
    cin >> k;
    int ans = n;
    for (int i = 0; i < n; ++i) {
        if (k > arr[i]) {
            ans--;
        }
    }
    cout << ans;
    return 0;
}