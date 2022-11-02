#include <bits/stdc++.h>
using namespace std;

main() {
    int b, g, n;
    cin >> b >> g >> n;
    cout << min(b, n) - max(0, n - g) + 1;
    return 0;
}