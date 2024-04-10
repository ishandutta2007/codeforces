#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        long long l, r, d;
        cin >> l >> r >> d;
        if (d < l) {
            cout << d << '\n';
        } else {
            cout << (r + d) / d * d << '\n';
        }
    }
}