#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            cout << a[i] / 2 << endl;
        }
        else {
            int x = a[i] / 2;
            if (a[i] < 0) {
                x--;
            }
            if (k >= 0) {
                if (x >= 0) {
                    cout << x << endl;
                }
                else {
                    cout << x << endl;
                }
                k--;
            }
            else {
                k++;
                if (x >= 0) {
                    cout << x + 1 << endl;
                }
                else {
                    cout << x + 1 << endl;
                }
            }
        }
    }
}