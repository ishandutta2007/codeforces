#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; cin >> q; while (q--) {
        int n; cin >> n;
        if (n <= 3) cout << -1 << endl;
        else {
            for (int i = 2 - n % 2; i <= n; i += 2) cout << i << " ";
            cout << n - 3 << " " << n - 1 << " ";
            for (int j = n - 5; j > 0; j -= 2) cout << j << " ";
            cout << endl;
        }
    }
}