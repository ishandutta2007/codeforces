#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[400000];
int n, k;
int fun(int mid) {
    int ok = 0;
    if (k & 1) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] <= mid) {
                cnt++;
                i++;
            }
        }
        if (cnt >= (k + 1) / 2) return 1;
        cnt = 0;
        for (int i = 2; i < n; i++) {
            if (a[i] <= mid) {
                cnt++;
                i++;
            }
        }
        if (cnt >= k / 2) return 1;
    } else {
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] <= mid) {
                cnt++;
                i++;
            }
        }
        if (cnt >= k / 2) return 1;
        cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] <= mid) {
                cnt++;
                i++;
            }
        }
        if (cnt >= k / 2) return 1;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1000000000, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (fun(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
}