#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, x, y, z;
    x = y = z = 0;
    int n;
    cin >> n;
    while(n--) {
        cin >> a >> b >> c;
        x += a; y += b; z += c;
    }
    if(!x && !y && !z) cout << "YES\n";
    else cout << "NO\n";
}