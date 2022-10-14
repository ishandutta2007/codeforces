#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

llint t, x1, y1, z1, x2, y2, z2;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        llint d = min(z1, y2);
        z1 -= d; y2 -= d;
        y1 -= min(y1, x2 + y2);
        cout << 2 * (d - y1) << '\n';
    }
    return 0;
}