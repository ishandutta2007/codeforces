#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (e > f) {
        int x = min(a, d);
        d -= x;
        int y = min(b, min(c, d));
        cout << x * e + y * f << endl;
    } else {
        int y = min(b, min(c, d));
        d -= y;
        int x = min(a, d);
        cout << x * e + y * f << endl;
    }
    return 0;
}