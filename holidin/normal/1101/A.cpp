#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j, l, r, q, d;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> l >> r >> d;
        if (l > d)
            cout << d << "\n";
        else
            cout << (r / d + 1) * d << "\n";
    }
}