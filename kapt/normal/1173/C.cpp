#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
int arr[MAXN];
int n;

int suff() {
    int k = 1;
    int last = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if (last == 1) {
            break;
        }
        if (arr[i] != last - 1) {
            return 0;
        }
        k++;
        last--;
    }
    return arr[n - 1];
}

main() {
    cin >> n;
    int not_need;
    for (int i = 0; i < n; ++i) {
        cin >> not_need;
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int x = suff();
    // cout << x << endl;
    if (x == n) {
        cout << 0;
        return 0;
    }
    int mx = 1e9;
    for (int i = 0; i < n - x; ++i) {
        if (arr[i] != 0 && arr[i] - i < mx) {
            mx = arr[i] - i;
        }
    }
    if (mx >= x + 2) {
        cout << n - x;
        return 0;
    }
    mx = 1e9;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0 && arr[i] - i < mx) {
            mx = arr[i] - i;
        }
    }
    cout << 2 - mx + n;
    return 0;
}