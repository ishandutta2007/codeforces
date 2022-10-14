#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

llint a, b, c, d, e, f, sol;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> d >> e >> f;
    for (llint x = 0; x <= d; x++) {
        llint y = d - x;
        llint val = min(a, x) * e + min(min(b, c), y) * f;
        sol = max(sol, val);
    }
    cout << sol;
    return 0;
}