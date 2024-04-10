#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << a * 10 << " " << b * 10 + 1;
    }
    else if (a == 9 && b == 1) {
        cout << 9 << " " << 10;
    }
    else if (a == b - 1) {
        cout << a << " " << b;
    }
    else {
        cout << -1;
    }
}