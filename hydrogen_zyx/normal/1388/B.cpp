#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k = (n + 3) / 4;
        for (int i = 1; i <= n - k; i++) {
            cout << 9;
        }
        for (int i = n - k + 1; i <= n; i++) {
            cout << 8;
        }
        cout << endl;
    }
}