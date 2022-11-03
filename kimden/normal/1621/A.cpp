#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n >= 2 * k - 1) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j || i % 2 == 1 || i / 2 >= k) {
                        cout << '.';
                    } else {
                        cout << 'R';
                    }
                }
                cout << '\n';
            }
        } else {
            cout << -1 << "\n";
        }
    }


}