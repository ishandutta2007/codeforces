#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


int main() {
    ios_base::sync_with_stdio(false);

    int n, x, y, a, c;
    c = 0;
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a <= x) ++c;
    }
    if (x > y) {
        cout << n << endl;
        return 0;
    }
    cout << (c + 1) / 2 << endl;
}