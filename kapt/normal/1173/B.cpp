#include <bits/stdc++.h>
using namespace std;

main() {
    int n;
    cin >> n;
    int m = n / 2 + 1;
    cout << m << endl;
    for (int i = 0; i < m; ++i) {
        cout << 1 << " " << i + 1 << endl;
    }
    for (int i = 0; i < n - m; ++i) {
        cout << i + 2 << " " << m << endl;
    }
    return 0;
}