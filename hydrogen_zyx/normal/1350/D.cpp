#include <bits/stdc++.h>
using namespace std;
int a[200000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        bool f = 0;
        bool youk = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == k) {
                youk = 1;
                if (i != 1 && a[i - 1] > k) f = 1;
                if (i != n && a[i + 1] > k) f = 1;
            }
        }
        if (!youk) {
            cout << "no" << endl;
            continue;
        }
        if (f) {
            cout << "yes" << endl;
            continue;
        }
        int pre = -10;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= k) {
                if (i - pre <= 2) f = 1;
                pre = i;
            }
        }
        if (n == 1) f = 1;
        if (f) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}