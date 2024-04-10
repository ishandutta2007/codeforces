#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                cout << (n - i + 1) + j * n << " ";
            }
            else {
                cout << i + j * n << " ";
            }
        }
        cout << endl;
    }
}