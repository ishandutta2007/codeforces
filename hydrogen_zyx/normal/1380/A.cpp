#include <bits/stdc++.h>
using namespace std;
int a[10000];
int mmin[10000];
int mmax[10000];
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        mmin[1] = a[1];
        for (int i = 2; i <= n; i++) mmin[i] = min(mmin[i - 1], a[i]);
        mmax[n] = a[n];
        for (int i = n - 1; i > 0; i--) mmax[i] = min(mmax[i + 1], a[i]);
        bool f = 1;
        for (int i = 2; i < n; i++) {
            if (a[i] > mmin[i - 1] && a[i] > mmax[i + 1]) {
                cout << "YES" << endl;
                for (int j = 1; j < i; j++) {
                    if (a[j] < a[i]) {
                        cout << j << ' ';
                        break;
                    }
                }
                cout << i << ' ';
                for (int j = n; j > i; j--) {
                    if (a[j] < a[i]) {
                        cout << j << ' ' << endl;
                        break;
                    }
                }
                f = 0;
                break;
            }
        }
        if (f) {
            cout << "NO" << endl;
        }
    }
}