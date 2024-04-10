#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<bool>> red;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    cin >> n >> k;
    
    if (n < 4 || k == 1 || k > 3 || (k == 2 && n == 4)) {
        cout << -1 << endl;
    } else {
        if (k == 2) {
            cout << n-1 << '\n';
            for (int i = 1; i < n; i++) {
                cout << i << ' ' << i+1 << '\n';
            }
        } else {
            cout << n-1 << '\n';
            for (int i = 1; i < n; i++) {
                cout << (i < 4 ? i : 2) << ' ' << i+1 << '\n';
            }
        }
    }

    return 0;
}