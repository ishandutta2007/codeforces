#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll x, y;
        cin >> x >> y;
        if(y < x) cout << y+x << '\n';
        else if(y == x) cout << x << '\n';
        else {
            cout << y - (y - x * (y/x))/2 << '\n';
        }
    }
}