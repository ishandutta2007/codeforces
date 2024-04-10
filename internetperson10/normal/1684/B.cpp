#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << (a + b + c) << ' ' << (b + c) << ' ' << c << '\n';
    }
}