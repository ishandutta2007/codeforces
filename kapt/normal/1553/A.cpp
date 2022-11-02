#include <bits/stdc++.h>
using namespace std;

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k = (n + 1) / 10;
        k = max(k, 0);
        cout << k << endl;
    }
    return 0;
}