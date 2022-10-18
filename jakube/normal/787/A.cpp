#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int i = 0; i < (int)1e6; i++) {
        if (d == b) {
            cout << d << endl;
            return 0;
        } else if (b < d)
            b += a;
        else
            d += c;
    }
    cout << -1 << endl;
}