#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int u, v;
        cin >> u >> v;
        cout << -u * u << " " << v * v << endl;
    }
    return 0;
}