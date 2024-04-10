#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a, b, c;
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if (a >= c)
            cout << -1 << ' ';
        else
            cout << 1 << ' ';
        if (b * a <= c)
            cout << -1 << endl;
        else
            cout << b << endl;
    }
}