#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t --> 0) {
        int L, v, l, r;
        cin >> L >> v >> l >> r;
        auto f = [v](int x) {
            return x / v;
        };
        cout << f(L) - (f(r) - f(l - 1)) << '\n';
    }
}