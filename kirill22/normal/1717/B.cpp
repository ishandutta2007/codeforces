#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        x--, y--;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ".X"[(i % k - j % k + k) % k == (x % k - y % k + k) % k];
            }
            cout << '\n';
        }
    }
}