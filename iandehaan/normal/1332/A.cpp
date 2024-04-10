#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        ll finalx = x+b-a;
        ll finaly = y+d-c;

        if (finalx < x1 || finalx > x2 || finaly < y1 || finaly > y2) {
            cout << "No" << endl;
        } else {
            // check for interval
            if (a+b != 0 && x1==x2) {
                cout << "No" << endl;
            } else if (c+d != 0 && y1== y2) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
    }
}