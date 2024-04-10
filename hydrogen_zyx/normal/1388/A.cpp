#include <bits/stdc++.h>
using namespace std;
int a[10] = {6, 10, 14, 15};
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 6 + 10 + 14) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;

            if (n - 6 - 10 - 14 == 6 || n - 6 - 10 - 14 == 10 ||
                n - 6 - 10 - 14 == 14) {
                cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << n - 6 - 10 - 15
                     << endl;
            } else {
                cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 6 - 10 - 14
                     << endl;
            }
        }
    }
}