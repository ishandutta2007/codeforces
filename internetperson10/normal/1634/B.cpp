#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        while(n--) {
            ll g;
            cin >> g;
            x += g;
        }
        cout << ((y-x)%2 ? "Bob" : "Alice") << '\n';
    }
}