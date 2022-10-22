#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        for (int i = 1; i != n - 1; i += 2) {
            cout << i + 1 << " " << i << " ";
        }
        cout << n - 1 << " " << n << '\n';
    } else {
        cout << "1 2 3 ";
        for (int i = 4; i != n - 1; i += 2) {
            cout << i + 1 << " " << i << " ";
        }
        cout << n - 1 << " " << n << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}