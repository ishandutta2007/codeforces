#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t;
    cin >> n >> t;
    if (t < 10) {
        cout << t;
        for (int i = 0; i < n - 1; ++i) cout << "0";
        return 0;
    }
    if (n == 1) {
        cout << "-1";
        return 0;
    }
    cout << "1";
    for (int i = 0; i < n - 1; ++i) cout << "0";
    return 0;
};