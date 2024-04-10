#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        int ans = (n * m + 2) / 3;
        cout << ans << endl;
    }
    return 0;
}