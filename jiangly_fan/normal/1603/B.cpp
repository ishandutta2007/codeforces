#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        LL x, y;
        cin >> x >> y;
        if (y < x) cout << x + y << "\n";
        else {
            LL n =  y - (y - x) % x / 2;
            cout << n << "\n";
            assert(n % x == y % n);
        }
    }
    return 0;
}