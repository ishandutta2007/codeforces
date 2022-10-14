#include<bits/stdc++.h>

using namespace std;

int t;

int main () {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        if (x >= 4 || x > 1 && y <= 3 || y == 1) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}