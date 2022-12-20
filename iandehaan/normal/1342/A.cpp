#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if (2*a < b) {
            cout << abs(x)*a + abs(y)*a << endl;
        } else {
            if (x > 0 && y > 0) {
                //cout << "here" << endl;
                //cout << min(x, y) << ' ' << max(x, y) << endl;
                cout << min(x, y)*b + (max(x,y)-min(x,y))*a << endl;
            } else if (x < 0 && y < 0) {
                x = abs(x);
                y = abs(y);
                cout << min(x, y)*b + (max(x,y)-min(x,y))*a << endl;
            } else {
                cout << abs(x)*a + abs(y)*a << endl;
            }
        }
    }
}