#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int t, n, m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            sum += x;
        }
        if (m < n || n <= 2) {
            cout << -1 << '\n';
        } else {
            cout << sum * 2 << '\n';
            for (int i = 0; i < n; i++) {
                cout << i + 1 << " " << (i + 1) % n + 1 << endl;
            }
        }
    }
    return 0;
}