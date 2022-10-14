#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

llint t, a, b, c, r;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> r;
        if (a > b) swap(a, b);
        cout << b - a - max(min(b, c + r) - max(a, c - r), 0LL) << '\n';
    }
    return 0;
}