#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1) {
            cout << -1;
        } else {
            cout << 2;
            for (int i = 1; i < n; i++) {
                cout << 9;
            }
        }
        cout << '\n';
    }
}